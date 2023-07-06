#include <iostream>
#include <nlohmann/json.hpp>
#include <msclr\marshal_cppstd.h>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "Overview.h"


using namespace System;
using namespace System::Net::Http;
using namespace System::Threading::Tasks;
using json = nlohmann::json;

namespace LoginForm {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;





    public ref class MainPage : public System::Windows::Forms::Form {
    private:
        HttpClient^ client;
        System::Windows::Forms::ListBox^ movieListBox;
        System::Windows::Forms::LinkLabel^ linkLabel1;
        System::Windows::Forms::LinkLabel^ linkLabel2;
        System::Windows::Forms::LinkLabel^ linkLabel3;
        System::ComponentModel::Container^ components;
        System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel;
        delegate void PictureBoxWithTitleDelegate(String^ path, String^ title);

    public:
        MainPage(void) {
            InitializeComponent();
            client = gcnew HttpClient();
            MakeRequestAsync();
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
        }

        void pictureBox_Click(Object^ sender, EventArgs^ e) {
            PictureBox^ picBox = safe_cast<PictureBox^>(sender);
            int movieId = safe_cast<int>(picBox->Tag);

            GetMovieDetailsAsync(movieId);
        }

        void GetMovieDetailsAsync(int movieId) {
            String^ apiKey = "e18bd6b624b9b189e366056ce94a353c";
            String^ apiUrl = "https://api.themoviedb.org/3/movie/" + movieId + "?api_key=" + apiKey;
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
            //  this->movieListBox = (gcnew System::Windows::Forms::ListBox());
            this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
            this->linkLabel2 = (gcnew System::Windows::Forms::LinkLabel());
            this->linkLabel3 = (gcnew System::Windows::Forms::LinkLabel());
            this->SuspendLayout();
            //
            // linkLabel1
            //
            this->linkLabel1->Location = System::Drawing::Point(366, 31);
            this->linkLabel1->Name = L"linkLabel1";
            this->linkLabel1->Size = System::Drawing::Size(39, 13);
            this->linkLabel1->TabIndex = 1;
            this->linkLabel1->Text = L"For me";
            //
            // linkLabel2
            //
            this->linkLabel2->Location = System::Drawing::Point(584, 31);
            this->linkLabel2->Name = L"linkLabel2";
            this->linkLabel2->Size = System::Drawing::Size(67, 13);
            this->linkLabel2->TabIndex = 2;
            this->linkLabel2->Text = L"Whats new?";
            //
            // linkLabel3
            //
            this->linkLabel3->Location = System::Drawing::Point(472, 31);
            this->linkLabel3->Name = L"linkLabel3";
            this->linkLabel3->Size = System::Drawing::Size(43, 13);
            this->linkLabel3->TabIndex = 3;
            this->linkLabel3->Text = L"Top rated";
            //
            // MainPage
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1043, 636);
            this->Controls->Add(this->linkLabel3);
            this->Controls->Add(this->linkLabel2);
            this->Controls->Add(this->linkLabel1);
            this->Controls->Add(this->movieListBox);
            this->Name = L"MainPage";
            this->Text = L"MainPage";
            this->ResumeLayout(false);
            //scroll
            this->flowLayoutPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->flowLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->flowLayoutPanel->AutoScroll = true;
            this->flowLayoutPanel->FlowDirection = System::Windows::Forms::FlowDirection::LeftToRight;
            this->flowLayoutPanel->WrapContents = true;


            this->Controls->Add(this->flowLayoutPanel);
        }

    };

}
