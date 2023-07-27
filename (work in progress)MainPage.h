//10.1.8.18:4201
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
#include "Recommed.h"




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
        String^ username;
        String^ movieIdStr;
        System::Windows::Forms::Label^ titleLabel = gcnew System::Windows::Forms::Label();
        System::Windows::Forms::Label^ titleLabel2 = gcnew System::Windows::Forms::Label();
        System::Windows::Forms::Label^ titleLabel3 = gcnew System::Windows::Forms::Label();
        System::Windows::Forms::Label^ titleLabel4 = gcnew System::Windows::Forms::Label();
        System::Windows::Forms::ListBox^ movieListBox;
        System::Windows::Forms::LinkLabel^ linkLabel1;
        System::Windows::Forms::LinkLabel^ linkLabel2;
        System::Windows::Forms::LinkLabel^ linkLabel3;
        System::ComponentModel::Container^ components;
        System::Windows::Forms::Panel^ scrollablePanel;
        System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel;
        System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel2;
        System::Windows::Forms::LinkLabel^ linkLabel4;
        System::Windows::Forms::LinkLabel^ linkLabel5;
        System::Windows::Forms::LinkLabel^ linkLabel6;
        System::Windows::Forms::LinkLabel^ linkLabel7;
        System::Windows::Forms::LinkLabel^ linkLabel8;
        System::Windows::Forms::LinkLabel^ linkLabel9;
        System::Windows::Forms::LinkLabel^ linkLabel10;
        System::Windows::Forms::LinkLabel^ linkLabel11;
        System::Windows::Forms::LinkLabel^ linkLabel12;
        System::Windows::Forms::LinkLabel^ linkLabel13;
        System::Windows::Forms::Button^ logoutButton;
        delegate void PictureBoxWithTitleDelegate(String^ path, String^ title);
        System::Windows::Forms::Panel^ recommendedMoviesPanel;
        System::Windows::Forms::Button^ loadMoreButton;
        int currentPage;
        LoginForm^ loginForm;

        System::Void linkLabel3_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
            TopRated^ topRatedForm = gcnew TopRated();
            topRatedForm->Show();

        }
        System::Void linkLabel2_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
            List<String^>^ userGenres = gcnew List<String^>();
            List<Movie^>^ allMovies = gcnew List<Movie^>();
            std::string stdUsername = User::Username;
            System::String^ LoggedInUsername = gcnew System::String(stdUsername.c_str());


            Recommed^ recommedForm = gcnew Recommed(userGenres, allMovies, LoggedInUsername);
            recommedForm->Show();
        }
        System::Void linkLabel4_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
            System::Diagnostics::Process::Start("https://www.gotocme.com/");
        }
        
        System::Void linkLabel5_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
            System::Diagnostics::Process::Start("https://www.instagram.com/cmegroup/?hl=en");
        }

        System::Void linkLabel6_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
            System::Diagnostics::Process::Start("https://www.facebook.com/GotoCMELebanon//");
        }

        System::Void linkLabel7_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
            System::Diagnostics::Process::Start("https://www.linkedin.com/company/cmeoffshore-sal");
        }

        System::Void linkLabel8_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
            System::Diagnostics::Process::Start("https://www.google.com/maps/dir//cme+offshore/data=!4m6!4m5!1m1!4e2!1m2!1m1!1s0x151f17091ce8699f:0x922f753718b9597d?sa=X&ved=2ahUKEwis4_bA4q6AAxVMTaQEHchpDeYQ9Rd6BAhFEAA&ved=2ahUKEwis4_bA4q6AAxVMTaQEHchpDeYQ9Rd6BAhMEAU");
        }
        
        System::Void linkLabel9_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
            System::Diagnostics::Process::Start("https://www.gotocme.com/contact-us/");
        }

        System::Void linkLabel10_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
            System::Diagnostics::Process::Start("https://www.instagram.com/m7madsabbagh/?hl=en");
        }

        System::Void linkLabel11_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
            System::Diagnostics::Process::Start("https://www.linkedin.com/in/mohammed-sabbagh-2a3818254");
        }

        System::Void linkLabel12_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
            System::Diagnostics::Process::Start("https://wa.me/<+966590065941>");

        }

        System::Void linkLabel13_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
            System::Diagnostics::Process::Start("https://www.gotocme.com/careers/");
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
            loadMoreButton->Click += gcnew System::EventHandler(this, &MainPage::loadMoreButton_Click);
            currentPage = 1;
            MakeRequestAsync();
            //DisplayRecommendedMovies();




        }


        void MakeRequestAsync() {
            String^ apiKey = "e18bd6b624b9b189e366056ce94a353c";
            String^ apiUrl = "https://api.themoviedb.org/3/movie/popular?api_key=" + apiKey + "&page=" + currentPage;
            auto responseTask = client->GetAsync(apiUrl);
            responseTask->ContinueWith(gcnew Action<Task<HttpResponseMessage^>^>(this, &MainPage::HandleResponse));
        }


        void loadMoreButton_Click(Object^ sender, EventArgs^ e) {
            currentPage++;
            MakeRequestAsync();
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
            this->linkLabel4 = (gcnew System::Windows::Forms::LinkLabel());
            this->linkLabel5 = (gcnew System::Windows::Forms::LinkLabel());
            this->linkLabel6 = (gcnew System::Windows::Forms::LinkLabel());
            this->linkLabel7 = (gcnew System::Windows::Forms::LinkLabel());
            this->linkLabel8 = (gcnew System::Windows::Forms::LinkLabel());
            this->linkLabel9 = (gcnew System::Windows::Forms::LinkLabel());
            this->linkLabel10 = (gcnew System::Windows::Forms::LinkLabel());
            this->linkLabel11 = (gcnew System::Windows::Forms::LinkLabel());
            this->linkLabel12 = (gcnew System::Windows::Forms::LinkLabel());
            this->linkLabel13 = (gcnew System::Windows::Forms::LinkLabel());
    
            this->flowLayoutPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->SuspendLayout();




            this->loadMoreButton = (gcnew System::Windows::Forms::Button());
            this->loadMoreButton->Location = System::Drawing::Point(1850, 270);
            this->loadMoreButton->Size = System::Drawing::Size(75, 23);
            this->loadMoreButton->Text = L"Load More";
            this->Controls->Add(this->loadMoreButton);



            this->linkLabel1->Location = System::Drawing::Point(600, 220);
            this->linkLabel1->Name = L"linkLabel1";
            this->linkLabel1->Size = System::Drawing::Size(39, 13);
            this->linkLabel1->TabIndex = 1;
            this->linkLabel1->Text = L"Saved";

            this->linkLabel2->Location = System::Drawing::Point(900, 220);
            this->linkLabel2->Name = L"linkLabel2";
            this->linkLabel2->Size = System::Drawing::Size(67, 13);
            this->linkLabel2->TabIndex = 2;
            this->linkLabel2->Text = L"What we recommend for you";

            this->linkLabel3->Location = System::Drawing::Point(1200, 220);
            this->linkLabel3->Name = L"linkLabel3";
            this->linkLabel3->Size = System::Drawing::Size(43, 13);
            this->linkLabel3->TabIndex = 3;
            this->linkLabel3->Text = L"Top rated";

            this->linkLabel4->Location = System::Drawing::Point(650, 825);
            this->linkLabel4->Name = L"linkLabel4";
            this->linkLabel4->Size = System::Drawing::Size(100, 20);
            this->linkLabel4->TabIndex = 4;
            this->linkLabel4->Text = L"Website";
            
            this->linkLabel5->Location = System::Drawing::Point(650, 875);
            this->linkLabel5->Name = L"linkLabel5";
            this->linkLabel5->Size = System::Drawing::Size(100, 20);
            this->linkLabel5->TabIndex = 5;
            this->linkLabel5->Text = L"Instagram";

            this->linkLabel6->Location = System::Drawing::Point(650, 925);
            this->linkLabel6->Name = L"linkLabel6";
            this->linkLabel6->Size = System::Drawing::Size(100, 20);
            this->linkLabel6->TabIndex = 6;
            this->linkLabel6->Text = L"Facebook";

            this->linkLabel7->Location = System::Drawing::Point(650, 975);
            this->linkLabel7->Name = L"linkLabel7";
            this->linkLabel7->Size = System::Drawing::Size(100, 20);
            this->linkLabel7->TabIndex = 7;
            this->linkLabel7->Text = L"LinkedIn";

            this->linkLabel8->Location = System::Drawing::Point(950, 825);
            this->linkLabel8->Name = L"linkLabel8";
            this->linkLabel8->Size = System::Drawing::Size(100, 20);
            this->linkLabel8->TabIndex = 8;
            this->linkLabel8->Text = L"Location";

            this->linkLabel9->Location = System::Drawing::Point(950, 875);
            this->linkLabel9->Name = L"linkLabel9";
            this->linkLabel9->Size = System::Drawing::Size(100, 20);
            this->linkLabel9->TabIndex = 9;
            this->linkLabel9->Text = L"Get in touch";

            this->linkLabel10->Location = System::Drawing::Point(1250, 825);
            this->linkLabel10->Name = L"linkLabel10";
            this->linkLabel10->Size = System::Drawing::Size(100, 20);
            this->linkLabel10->TabIndex = 10;
            this->linkLabel10->Text = L"Instragram";

            this->linkLabel11->Location = System::Drawing::Point(1250, 875);
            this->linkLabel11->Name = L"linkLabel11";
            this->linkLabel11->Size = System::Drawing::Size(100, 20);
            this->linkLabel11->TabIndex = 11;
            this->linkLabel11->Text = L"LinkedIn";

            this->linkLabel12->Location = System::Drawing::Point(1250, 925);
            this->linkLabel12->Name = L"linkLabel12";
            this->linkLabel12->Size = System::Drawing::Size(100, 20);
            this->linkLabel12->TabIndex = 12;
            this->linkLabel12->Text = L"Whatsapp";

            this->linkLabel13->Location = System::Drawing::Point(950, 925);
            this->linkLabel13->Name = L"linkLabel13";
            this->linkLabel13->Size = System::Drawing::Size(100, 20);
            this->linkLabel13->TabIndex = 13;
            this->linkLabel13->Text = L"Need a job?";

            titleLabel->Location = System::Drawing::Point(900, 50); 
            titleLabel->Name = L"titleLabel";
            titleLabel->Size = System::Drawing::Size(200, 50); 
            titleLabel->Text = L"CME Movies";
            titleLabel->Font = gcnew System::Drawing::Font(L"Arial", 20, System::Drawing::FontStyle::Bold);


            titleLabel2->Location = System::Drawing::Point(600, 770);
            titleLabel2->Name = L"titleLabel";
            titleLabel2->Size = System::Drawing::Size(200, 50);
            titleLabel2->Text = L"Social Media";
            titleLabel2->Font = gcnew System::Drawing::Font(L"Arial", 15, System::Drawing::FontStyle::Underline);

            titleLabel3->Location = System::Drawing::Point(900, 770);
            titleLabel3->Name = L"titleLabel";
            titleLabel3->Size = System::Drawing::Size(200, 50);
            titleLabel3->Text = L"Reach out";
            titleLabel3->Font = gcnew System::Drawing::Font(L"Arial", 15, System::Drawing::FontStyle::Underline);

            titleLabel4->Location = System::Drawing::Point(1200, 770);
            titleLabel4->Name = L"titleLabel";
            titleLabel4->Size = System::Drawing::Size(200, 50);
            titleLabel4->Text = L"Meet the Creator";
            titleLabel4->Font = gcnew System::Drawing::Font(L"Arial", 15, System::Drawing::FontStyle::Underline);


            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1043, 636);
            this->Controls->Add(this->linkLabel3);
            this->Controls->Add(this->linkLabel2);
            this->Controls->Add(this->linkLabel1);
            this->Controls->Add(this->linkLabel4);
            this->Controls->Add(this->linkLabel5);
            this->Controls->Add(this->linkLabel6);
            this->Controls->Add(this->linkLabel7);
            this->Controls->Add(this->linkLabel8);
            this->Controls->Add(this->linkLabel9);
            this->Controls->Add(this->linkLabel10);
            this->Controls->Add(this->linkLabel11);
            this->Controls->Add(this->linkLabel12);
            this->Controls->Add(this->linkLabel13);
            this->Controls->Add(titleLabel);
            this->Controls->Add(titleLabel2);
            this->Controls->Add(titleLabel3);
            this->Controls->Add(titleLabel4);

            
            this->Name = L"MainPage";
            this->Text = L"MainPage";
            this->ResumeLayout(false);
            this->PerformLayout();
            System::Int32 topMargin = 300;
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
            this->linkLabel2->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MainPage::linkLabel2_LinkClicked);
            this->linkLabel4->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MainPage::linkLabel4_LinkClicked);
            this->linkLabel5->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MainPage::linkLabel5_LinkClicked);
            this->linkLabel6->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MainPage::linkLabel6_LinkClicked);
            this->linkLabel7->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MainPage::linkLabel7_LinkClicked);
            this->linkLabel8->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MainPage::linkLabel8_LinkClicked);
            this->linkLabel9->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MainPage::linkLabel9_LinkClicked);
            this->linkLabel10->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MainPage::linkLabel10_LinkClicked);
            this->linkLabel11->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MainPage::linkLabel11_LinkClicked);
            this->linkLabel12->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MainPage::linkLabel12_LinkClicked);
            this->linkLabel13->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MainPage::linkLabel13_LinkClicked);



        }



    };

}
