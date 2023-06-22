#pragma once

#include <iostream>
#include <msclr\marshal_cppstd.h>


using namespace System;
using namespace System::Net::Http;
using namespace System::Threading::Tasks;

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

        System::ComponentModel::Container^ components;

    public:
        MainPage(void) {
            InitializeComponent();
            client = gcnew HttpClient();
            MakeRequestAsync();
        }

        void MakeRequestAsync() {
            String^ apiKey = "e18bd6b624b9b189e366056ce94a353c";
            String^ apiUrl = "https://api.themoviedb.org/3/authentication";

            client->DefaultRequestHeaders->Authorization = gcnew System::Net::Http::Headers::AuthenticationHeaderValue("Bearer", apiKey);

            auto responseTask = client->GetAsync(apiUrl);
            responseTask->ContinueWith(gcnew Action<Task<HttpResponseMessage^>^>(this, &MainPage::HandleResponse));
        }

        void HandleResponse(Task<HttpResponseMessage^>^ responseTask) {
            auto response = responseTask->Result;
            if (response->IsSuccessStatusCode) {
                auto contentTask = response->Content->ReadAsStringAsync();
                contentTask->Wait();
                auto content = contentTask->Result;
               
            }
        }

    protected:
        ~MainPage() {
            if (components) {
                delete components;
            }
        }

#pragma region Windows Form Designer generated code
        void InitializeComponent(void) {
            this->SuspendLayout();
            // 
            // MainPage
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1482, 844);
            this->Name = L"MainPage";
            this->Text = L"MainPage";
            this->ResumeLayout(false);

        }
#pragma endregion
    };
}
