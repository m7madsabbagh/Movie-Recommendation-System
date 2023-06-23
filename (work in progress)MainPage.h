#pragma once

#include <iostream>
#include <nlohmann/json.hpp>
#include <msclr\marshal_cppstd.h>


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
        System::Windows::Forms::TextBox^ textBox1;

        System::ComponentModel::Container^ components;

    public:
        MainPage(void) {
            InitializeComponent();
            client = gcnew HttpClient();
            MakeRequestAsync();
        }

        void MakeRequestAsync() {
            String^ apiKey = "e18bd6b624b9b189e366056ce94a353c";
            String^ apiUrl = "https://api.themoviedb.org/3/movie/550?api_key=" + apiKey;

            auto responseTask = client->GetAsync(apiUrl);
            responseTask->ContinueWith(gcnew Action<Task<HttpResponseMessage^>^>(this, &MainPage::HandleResponse));
        }

        void DisplayTitle(String^ title) {
            if (this->textBox1->InvokeRequired) {
                this->textBox1->Invoke(gcnew Action<String^>(this, &MainPage::DisplayTitle), title);
            }
            else {
                this->textBox1->Text = title;
            }
        }

        void HandleResponse(Task<HttpResponseMessage^>^ responseTask) {
            auto response = responseTask->Result;
            if (response->IsSuccessStatusCode) {
                auto contentTask = response->Content->ReadAsStringAsync();
                contentTask->Wait();
                auto content = contentTask->Result;

                int titlePos = content->IndexOf("\"title\":\"") + 9;
                int endPos = content->IndexOf("\",", titlePos);
                String^ title = content->Substring(titlePos, endPos - titlePos);

                DisplayTitle(title);
            }
        }

#pragma region Windows Form Designer generated code
        void InitializeComponent(void) {
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->SuspendLayout();
            // 
            // textBox1
            // 
            this->textBox1->Location = System::Drawing::Point(12, 12);
            this->textBox1->Multiline = true;
            this->textBox1->Size = System::Drawing::Size(458, 434);
            this->textBox1->TabIndex = 0;
            // 
            // MainPage
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(482, 458);
            this->Controls->Add(this->textBox1);
            this->Name = L"MainPage";
            this->Text = L"MainPage";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    };
