#pragma once

#include <iostream>
#include <msclr\marshal_cppstd.h>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "Overview.h"
#include "User.h"

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
    using namespace MySql::Data::MySqlClient;

    public ref class Display : public System::Windows::Forms::Form {
    private:
        HttpClient^ client;
        System::Windows::Forms::ListBox^ movieListBox;
        System::Windows::Forms::LinkLabel^ linkLabel1;
        System::Windows::Forms::LinkLabel^ linkLabel2;
        System::Windows::Forms::LinkLabel^ linkLabel3;
        System::ComponentModel::Container^ components;
        System::Windows::Forms::Panel^ scrollablePanel;
        System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel;
        delegate void PictureBoxWithTitleDelegate(String^ path, String^ title);

        System::String^ Username;

           System::String^ MovieID;

    public:
        Display(String^ loggedInUsername);
        void LoadSavedMovies(String^ username);
        void GetMovieDetailsAsync(String^ movieId);
        void HandleMovieDetailsResponse(Task<HttpResponseMessage^>^ responseTask);
        void CreatePictureBoxWithTitle(String^ path, String^ title);
        void InitializeComponent(void);
        void Display_Load(System::Object^ sender, System::EventArgs^ e);
    private: System::Void Display_Load_1(System::Object^ sender, System::EventArgs^ e) {
    }
    };
}
