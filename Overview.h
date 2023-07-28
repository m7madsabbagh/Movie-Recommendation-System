#pragma once

#include "User.h"

namespace LoginForm {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;

    public ref class Overview : public System::Windows::Forms::Form
    {
    public:
        Overview(System::String^ title, System::String^ overview, System::String^ posterPath, System::String^ release_date, double rating);
        delegate void MovieSavedEventHandler(System::String^ movieID);
        event MovieSavedEventHandler^ MovieSaved;

    protected:
        ~Overview();

        virtual void OnMovieSaved(System::String^ movieID) 
        {
            MovieSaved(movieID);
        }
    private:
        System::Windows::Forms::Button^ saveButton;
        System::Windows::Forms::Button^ unsaveButton;
        System::Windows::Forms::Button^ saveRatingButton; 
        System::Windows::Forms::NumericUpDown^ ratingInput; 
        System::String^ Username;
        System::String^ MovieID;

        System::Windows::Forms::Label^ CreateLabel(System::String^ text);
        System::Void SaveMovieButton_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void SaveRatingButton_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void UnsaveMovieButton_Click(System::Object^ sender, System::EventArgs^ e);
        System::Windows::Forms::TextBox^ commentBox;
        System::Windows::Forms::Button^ submitCommentButton;
        System::Windows::Forms::ListBox^ commentsList;
        System::Void SubmitCommentButton_Click(System::Object^ sender, System::EventArgs^ e);
        void LoadComments();
        System::Void InitializeComponent() {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Overview::typeid));
            this->SuspendLayout();
            // 
            // Overview
            // 
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->ClientSize = System::Drawing::Size(1250, 730);
            this->Name = L"Overview";
            this->Load += gcnew System::EventHandler(this, &Overview::Overview_Load);
            this->ResumeLayout(false);

        }
    private: System::Void Overview_Load(System::Object^ sender, System::EventArgs^ e) {
    }
    };
}
