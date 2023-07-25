    #pragma once
    #include <iostream>
    #include <msclr\marshal_cppstd.h>
    #include "rapidjson/document.h"
    #include "rapidjson/writer.h"
    #include "rapidjson/stringbuffer.h"
    #include "Overview.h"
    #include "Display.h"
    #include "User.h"
    #include "Movie.h"
    #include "TopRated.h"
#include "Recommendation.h"
   



    namespace LoginForm {

        using namespace System;
        using namespace System::ComponentModel;
        using namespace System::Collections;
        using namespace System::Windows::Forms;
        using namespace System::Data;
        using namespace System::Drawing;
        using namespace System::Net::Http;
        using namespace System::Threading::Tasks;
      

        ref class LoginForm;

        public ref class MainPage : public System::Windows::Forms::Form {



        private:
           
            HttpClient^ client; 
            Panel^ MoviesPanel;
            RecommendationHandler^ recHandler;
            String^ username;
            String^ movieIdStr;
            System::Windows::Forms::ListBox^ movieListBox;
            System::Windows::Forms::LinkLabel^ linkLabel1;
            System::Windows::Forms::LinkLabel^ linkLabel2;
            System::Windows::Forms::LinkLabel^ linkLabel3;
            System::ComponentModel::Container^ components;
            System::Windows::Forms::Panel^ scrollablePanel;
            System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel;
            System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel2;
            System::Windows::Forms::Button^ logoutButton;
            delegate void PictureBoxWithTitleDelegate(String^ path, String^ title);
            System::Windows::Forms::Panel^ recommendedMoviesPanel;


            System::Void linkLabel3_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
                TopRated^ topRatedForm = gcnew TopRated();
                topRatedForm->Show();
            

            }

       

            System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
                try {
                    std::string stdUsername = User::Username;
                    System::String^ loggedInUsername = gcnew System::String(stdUsername.c_str());

                    Display^ displayForm = gcnew Display(loggedInUsername);
                    displayForm->Show();

                }
                catch (Exception^ ex) {
                    MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                }
            }

        




        protected:
            ~MainPage()
            {
                if (components)
                {
                    delete components;
                }
            }

        public:

            MainPage(void) {

                InitializeComponent();
                client = gcnew HttpClient();
                MakeRequestAsync();
                DisplayRecommendedMovies();
                


            }

            void MakeRequestAsync() {
                String^ apiKey = "e18bd6b624b9b189e366056ce94a353c";
                String^ apiUrl = "https://api.themoviedb.org/3/movie/popular?api_key=" + apiKey;
                auto responseTask = client->GetAsync(apiUrl);
                responseTask->ContinueWith(gcnew Action<Task<HttpResponseMessage^>^>(this, &MainPage::HandleResponse));
            }

       



            delegate void PictureBoxWithTitleAndRatingDelegate(String^ path, String^ title, String^ rating, int movieId);




            void HandleResponse(Task<HttpResponseMessage^>^ responseTask) {


                auto response = responseTask->Result;
                if (response->IsSuccessStatusCode) {
                    auto contentTask = response->Content->ReadAsStringAsync();
                    contentTask->Wait();
                    String^ content = contentTask->Result;

                    // Convert from System::String^ to std::string
                    msclr::interop::marshal_context context;
                    std::string content_std_str = context.marshal_as<std::string>(content);

                    // Parse with RapidJSON
                    rapidjson::Document d;
                    d.Parse(content_std_str.c_str());

                    if (d.IsObject() && d.HasMember("results") && d["results"].IsArray()) {
                        for (rapidjson::SizeType i = 0; i < d["results"].Size(); i++) {
                            if (d["results"][i].HasMember("title") && d["results"][i].HasMember("poster_path") && d["results"][i].HasMember("vote_average")) {
                                std::string title = d["results"][i]["title"].GetString();
                                std::string posterPath = d["results"][i]["poster_path"].GetString();
                                double rating = d["results"][i]["vote_average"].GetDouble();
                                int movieId = d["results"][i]["id"].GetInt();

                                // Convert from std::string to System::String^
                                String^ title_managed = gcnew String(title.c_str());
                                String^ posterPath_managed = gcnew String(posterPath.c_str());

                                // Format rating
                                String^ rating_managed;
                                if (rating == static_cast<int>(rating)) {
                                    rating_managed = String::Format("{0:F0}", rating); // No decimal part
                                }
                                else {
                                    rating_managed = String::Format("{0:F2}", rating); // With two decimal places
                                }

                                // Create PictureBox with title on UI thread
                                PictureBoxWithTitleAndRatingDelegate^ action = gcnew PictureBoxWithTitleAndRatingDelegate(this, &MainPage::CreatePictureBoxWithTitle);
                                this->Invoke(action, posterPath_managed, title_managed, rating_managed, movieId);
                            }
                        }
                    }
                    else {
                        Console::WriteLine("API request failed: " + response->StatusCode.ToString());
                    }
                }
            }





            void CreatePictureBoxWithTitle(String^ path, String^ title, String^ rating, int movieId) {
                int picBoxWidth = 200;
                int picBoxHeight = 300;
                int labelHeight = 20;

                PictureBox^ pictureBox = gcnew PictureBox();
                pictureBox->SizeMode = PictureBoxSizeMode::StretchImage;
                pictureBox->Size = Drawing::Size(picBoxWidth, picBoxHeight);
                pictureBox->ImageLocation = "https://image.tmdb.org/t/p/w500" + path;
                pictureBox->Tag = movieId;
                pictureBox->Click += gcnew System::EventHandler(this, &MainPage::pictureBox_Click);

                Label^ titleLabel = gcnew Label();
                titleLabel->Text = title;
                titleLabel->Size = Drawing::Size(picBoxWidth, labelHeight);
                titleLabel->TextAlign = ContentAlignment::MiddleCenter;
                titleLabel->Location = Point(0, picBoxHeight);

                Label^ ratingLabel = gcnew Label();
                ratingLabel->Text = "Rating: " + rating;
                ratingLabel->Size = Drawing::Size(100, 20);
                ratingLabel->Location = Point(picBoxWidth - ratingLabel->Width, 0);
                ratingLabel->BackColor = Color::White;
                pictureBox->Controls->Add(ratingLabel);
                ratingLabel->Text = rating + "%";

                Panel^ panel = gcnew Panel();
                panel->Size = Drawing::Size(picBoxWidth, picBoxHeight + labelHeight);
                panel->Controls->Add(pictureBox);
                panel->Controls->Add(titleLabel);

                this->flowLayoutPanel->Controls->Add(panel);
                //this->flowLayoutPanel2->Controls->Add(panel);


            }

            void pictureBox_Click(Object^ sender, EventArgs^ e) {
                PictureBox^ picBox = safe_cast<PictureBox^>(sender);
                int movieId = safe_cast<int>(picBox->Tag);

                GetMovieDetailsAsync(movieId);
            }

            void GetMovieDetailsAsync(int movieId) {
                String^ apiKey = "e18bd6b624b9b189e366056ce94a353c";
                String^ movieIdStr = movieId.ToString(); // Convert int to System::String^
                String^ apiUrl = "https://api.themoviedb.org/3/movie/" + movieIdStr + "?api_key=" + apiKey;
                auto responseTask = client->GetAsync(apiUrl);
                responseTask->ContinueWith(gcnew Action<Task<HttpResponseMessage^>^>(this, &MainPage::HandleMovieDetailsResponse));
            }

           
            void DisplayRecommendedMovies()
            {
                if (recHandler == nullptr)
                {
                    recHandler = gcnew RecommendationHandler();
                }

                List<Movie^>^ recommendedMovies = recHandler->getRecommendedMovies(username);
                

                for each (Movie ^ movie in recommendedMovies)
                {
                    System::Windows::Forms::PictureBox^ pb = gcnew System::Windows::Forms::PictureBox();
                    pb->SizeMode = PictureBoxSizeMode::StretchImage;
                    pb->Load(movie->ImageUrl); // this method downloads and displays the image
                    this->flowLayoutPanel2->Controls->Add(pb);
                }
            }




            void HandleMovieDetailsResponse(Task<HttpResponseMessage^>^ responseTask) {
                auto response = responseTask->Result;
                if (response->IsSuccessStatusCode) {
                    auto contentTask = response->Content->ReadAsStringAsync();
                    contentTask->Wait();
                    String^ content = contentTask->Result;

                    // Convert from System::String^ to std::string
                    msclr::interop::marshal_context context;
                    std::string content_std_str = context.marshal_as<std::string>(content);

                    // Parse with RapidJSON
                    rapidjson::Document d;
                    d.Parse(content_std_str.c_str());

                    if (d.IsObject()) {

                        std::string title = d["title"].GetString();
                        std::string overview = d["overview"].GetString();
                        std::string posterPath = d["poster_path"].GetString();
                        std::string release_date = d["release_date"].GetString();
                        double rating = d["vote_average"].GetDouble();


                        String^ title_managed = gcnew String(title.c_str());
                        String^ overview_managed = gcnew String(overview.c_str());
                        String^ posterPath_managed = gcnew String(posterPath.c_str());
                        String^ release_date_managed = gcnew String(release_date.c_str());


                        Overview^ overviewForm = gcnew Overview(title_managed, overview_managed, "https://image.tmdb.org/t/p/w500" + posterPath_managed, release_date_managed, rating);
                        overviewForm->ShowDialog();
                    }
                    else {
                        Console::WriteLine("API request failed: " + response->StatusCode.ToString());
                    }
                }
            }



#pragma region
        void InitializeComponent(void) {

            


            this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
            this->linkLabel2 = (gcnew System::Windows::Forms::LinkLabel());
            this->linkLabel3 = (gcnew System::Windows::Forms::LinkLabel());
            this->flowLayoutPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->SuspendLayout();

       

            System::Windows::Forms::Label^ titleLabel = (gcnew System::Windows::Forms::Label());
            titleLabel->BackColor = System::Drawing::Color::Transparent;
            titleLabel->Text = L"CME Movies";
            titleLabel->Font = (gcnew System::Drawing::Font(L"Arial", 30, System::Drawing::FontStyle::Bold));
            titleLabel->ForeColor = System::Drawing::Color::Black;
            titleLabel->Location = System::Drawing::Point(10, 10);
            this->Controls->Add(titleLabel);


            this->linkLabel1->Location = System::Drawing::Point(600, 100);
            this->linkLabel1->Name = L"linkLabel1";
            this->linkLabel1->Size = System::Drawing::Size(39, 13);
            this->linkLabel1->TabIndex = 1;
            this->linkLabel1->Text = L"For me";
            this->linkLabel2->Location = System::Drawing::Point(650, 100);
            this->linkLabel2->Name = L"linkLabel2";
            this->linkLabel2->Size = System::Drawing::Size(67, 13);
            this->linkLabel2->TabIndex = 2;
            this->linkLabel2->Text = L"What\'s new\?";
            this->linkLabel3->Location = System::Drawing::Point(1500, 100);
            this->linkLabel3->Name = L"linkLabel3";
            this->linkLabel3->Size = System::Drawing::Size(43, 13);
            this->linkLabel3->TabIndex = 3;
            this->linkLabel3->Text = L"Top rated";
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1043, 636);
            this->Controls->Add(this->linkLabel3);
            this->Controls->Add(this->linkLabel2);
            this->Controls->Add(this->linkLabel1);
            this->Name = L"MainPage";
            this->Text = L"MainPage";
            this->ResumeLayout(false);
            this->PerformLayout();
            System::Int32 topMargin = 250;
            this->flowLayoutPanel->Dock = System::Windows::Forms::DockStyle::Top;
            this->flowLayoutPanel->AutoScroll = true;
            this->flowLayoutPanel->FlowDirection = System::Windows::Forms::FlowDirection::LeftToRight;
            this->flowLayoutPanel->WrapContents = false;
            this->flowLayoutPanel->Location = System::Drawing::Point(0, topMargin);
            this->flowLayoutPanel->Size = System::Drawing::Size(this->Width, (this->Height - topMargin));
            this->flowLayoutPanel->Anchor = ((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right);
            System::Windows::Forms::Panel^ scrollablePanel = (gcnew System::Windows::Forms::Panel());
            scrollablePanel->Dock = System::Windows::Forms::DockStyle::Fill;
            scrollablePanel->AutoScroll = true;
            scrollablePanel->Controls->Add(this->flowLayoutPanel);
            this->Controls->Add(scrollablePanel);

            this->flowLayoutPanel2 = gcnew System::Windows::Forms::FlowLayoutPanel();
            this->flowLayoutPanel2->AutoSize = true;
            this->flowLayoutPanel2->Location = System::Drawing::Point(0, this->flowLayoutPanel->Bottom + 10); 
            this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
            this->flowLayoutPanel2->Size = System::Drawing::Size(800, 450);
           
            System::Windows::Forms::Panel^ scrollablePanel2 = (gcnew System::Windows::Forms::Panel());
            scrollablePanel2->Dock = System::Windows::Forms::DockStyle::Fill;
            scrollablePanel2->AutoScroll = true;
            scrollablePanel2->Controls->Add(this->flowLayoutPanel2);

            this->Controls->Add(scrollablePanel2);

            this->linkLabel3->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MainPage::linkLabel3_LinkClicked);
            this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MainPage::linkLabel1_LinkClicked);

        }



    };

}
