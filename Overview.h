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

    protected:
        ~Overview();

    private:
        System::Windows::Forms::Button^ saveButton;
        System::Windows::Forms::Button^ saveRatingButton; // Button for saving the rating
        System::Windows::Forms::NumericUpDown^ ratingInput; // Input field for the rating
        System::String^ Username;
        System::String^ MovieID;

        System::Windows::Forms::Label^ CreateLabel(System::String^ text);
        System::Void SaveMovieButton_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void SaveRatingButton_Click(System::Object^ sender, System::EventArgs^ e); // Function for handling the button click
    };
}
