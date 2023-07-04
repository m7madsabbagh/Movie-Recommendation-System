#pragma once

#include <iostream>
#include <nlohmann/json.hpp>
#include <msclr\marshal_cppstd.h>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"


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
                        if (d["results"][i].HasMember("title") && d["results"][i].HasMember("poster_path")) {
                            std::string title = d["results"][i]["title"].GetString();
                            std::string posterPath = d["results"][i]["poster_path"].GetString();

                            // Convert from std::string to System::String^
                            String^ title_managed = gcnew String(title.c_str());
                            String^ posterPath_managed = gcnew String(posterPath.c_str());

                            // Create PictureBox with title on UI thread
                            PictureBoxWithTitleDelegate^ action = gcnew PictureBoxWithTitleDelegate(this, &MainPage::CreatePictureBoxWithTitle);
                            this->Invoke(action, posterPath_managed, title_managed);
                        }
                    }
                }
            }
            else {
                Console::WriteLine("API request failed: " + response->StatusCode.ToString());
            }
        }
        


        void CreatePictureBoxWithTitle(String^ path, String^ title) {
            int picBoxWidth = 200; 
            
            int picBoxHeight = 300; 
            
            int labelHeight = 20; 
            
           
            

            PictureBox^ pictureBox = gcnew PictureBox();
            pictureBox->SizeMode = PictureBoxSizeMode::StretchImage;
            pictureBox->Size = Drawing::Size(picBoxWidth, picBoxHeight);
            pictureBox->ImageLocation = "https://image.tmdb.org/t/p/w500" + path;

            Label^ label = gcnew Label();
            label->Text = title;
            label->Size = Drawing::Size(picBoxWidth, labelHeight);
            label->TextAlign = ContentAlignment::MiddleCenter;
            label->Location = Point(0, picBoxHeight); // Position the label just below the PictureBox

            Panel^ panel = gcnew Panel(); // Create a new panel
            panel->Size = Drawing::Size(picBoxWidth, picBoxHeight + labelHeight); // Size to fit both PictureBox and Label
            panel->Controls->Add(pictureBox); // Add PictureBox to the panel
            panel->Controls->Add(label); // Add Label to the panel

            this->flowLayoutPanel->Controls->Add(panel); // Add the panel to the FlowLayoutPanel
        }










        void InitializeComponent(void) {
          
            this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
            this->linkLabel2 = (gcnew System::Windows::Forms::LinkLabel());
            this->linkLabel3 = (gcnew System::Windows::Forms::LinkLabel());
            this->SuspendLayout();
            // 
           
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
            this->linkLabel3->Text = L"Popular";
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
