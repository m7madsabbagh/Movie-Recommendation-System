#pragma once

#include <iostream>
#include <msclr\marshal_cppstd.h>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "Overview.h"

using namespace System;
using namespace System::Net::Http;
using namespace System::Threading::Tasks;

namespace LoginForm {
    public ref class TopRated : public System::Windows::Forms::Form {
    public:
        TopRated(void);
        void MakeRequestAsync();
        void HandleResponse(Task<HttpResponseMessage^>^ responseTask);
        void CreatePictureBoxWithTitle(String^ path, String^ title, String^ rating, int movieId);
        void pictureBox_Click(Object^ sender, EventArgs^ e);
        void BackButton_Click(Object^ sender, EventArgs^ e);
        void GetMovieDetailsAsync(int movieId);
        void HandleMovieDetailsResponse(Task<HttpResponseMessage^>^ responseTask);
        void InitializeComponent(void);

    private:
        HttpClient^ client;
        System::Windows::Forms::ListBox^ movieListBox;
        System::Windows::Forms::LinkLabel^ linkLabel1;
        System::Windows::Forms::LinkLabel^ linkLabel2;
        System::Windows::Forms::LinkLabel^ linkLabel3;
        System::ComponentModel::Container^ components;
        System::Windows::Forms::Panel^ scrollablePanel;
    private: System::Windows::Forms::Label^ titleLabel;
    private: System::Windows::Forms::Button^ backButton;
    
           System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel;
        delegate void PictureBoxWithTitleDelegate(String^ path, String^ title);
    private: System::Void titleLabel_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void flowLayoutPanel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    }



    };
}
