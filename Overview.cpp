#include "Overview.h"
#include "User.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;

System::Windows::Forms::Label^ LoginForm::Overview::CreateLabel(System::String^ text)
{
    System::Windows::Forms::Label^ label = gcnew System::Windows::Forms::Label();
    label->Text = text;
    label->AutoSize = true;
    label->Padding = System::Windows::Forms::Padding(10); 

    return label;
}


LoginForm::Overview::Overview(System::String^ title, System::String^ overview, System::String^ posterPath, System::String^ release_date, double rating)
{
    this->Username = title;
    this->MovieID = title;

   
    this->Text = "Movie Overview";
    this->WindowState = FormWindowState::Maximized;

    
    TableLayoutPanel^ tableLayoutPanel = gcnew TableLayoutPanel();
    tableLayoutPanel->Dock = DockStyle::Fill;
    tableLayoutPanel->AutoSize = true;
    tableLayoutPanel->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
    tableLayoutPanel->ColumnCount = 2;
    tableLayoutPanel->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
    tableLayoutPanel->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));

    
    Label^ titleLabel = CreateLabel("Title: " + title);
    titleLabel->Font = gcnew System::Drawing::Font("Arial", 22, FontStyle::Bold);
    titleLabel->ForeColor = System::Drawing::Color::Black;

    Label^ overviewLabel = CreateLabel("Overview: " + overview);
    overviewLabel->Font = gcnew System::Drawing::Font("Arial", 12);
    overviewLabel->ForeColor = System::Drawing::Color::Black;

    Label^ releaseDateLabel = CreateLabel("Release Date: " + release_date);
    overviewLabel->Font = gcnew System::Drawing::Font("Arial", 12);
    overviewLabel->ForeColor = System::Drawing::Color::Black;

    Label^ ratingLabel = CreateLabel("Rating: " + rating.ToString());
    ratingLabel->Font = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);
    ratingLabel->ForeColor = System::Drawing::Color::Blue;
 


    tableLayoutPanel->Controls->Add(titleLabel, 0, 0);
    tableLayoutPanel->Controls->Add(overviewLabel, 0, 1);
    tableLayoutPanel->Controls->Add(releaseDateLabel, 0, 2);
    tableLayoutPanel->Controls->Add(ratingLabel, 0, 3);

    
    PictureBox^ pictureBox = gcnew PictureBox();
    pictureBox->SizeMode = PictureBoxSizeMode::AutoSize;
    pictureBox->ImageLocation = posterPath;
    pictureBox->Dock = DockStyle::Fill;

    
    tableLayoutPanel->Controls->Add(pictureBox, 1, 0);
    tableLayoutPanel->SetRowSpan(pictureBox, 4);

    
    this->Controls->Add(tableLayoutPanel);

    this->saveButton = gcnew Button();
    this->saveButton->Text = "Save Movie";
    this->saveButton->Click += gcnew System::EventHandler(this, &LoginForm::Overview::SaveMovieButton_Click);
    tableLayoutPanel->Controls->Add(this->saveButton, 0, 5);
}

System::Void LoginForm::Overview::SaveMovieButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Get the username from the User class
    std::string username_std = User::Username;

    // Convert std::string to System::String^
    String^ username_cli = gcnew String(username_std.c_str());

    String^ constr = "Server=127.0.0.1;Uid=root;Pwd=;Database=database";
    MySqlConnection^ con = gcnew MySqlConnection(constr);

    try {
        con->Open();

        MySqlCommand^ checkCommand = gcnew MySqlCommand("SELECT COUNT(*) FROM user_reg WHERE Username = @Username", con);
        checkCommand->Parameters->AddWithValue("@Username", username_cli);

        int count = Convert::ToInt32(checkCommand->ExecuteScalar());

        if (count == 0) {
            MessageBox::Show("Username does not exist in the database!");
            return;
        }

        MySqlCommand^ getCommand = gcnew MySqlCommand("SELECT MovieID FROM user_reg WHERE Username = @Username", con);
        getCommand->Parameters->AddWithValue("@Username", username_cli);

        MySqlDataReader^ reader = getCommand->ExecuteReader();

        System::String^ currentMovieIds = nullptr;
        if (reader->Read()) {
            currentMovieIds = reader->GetString(0);
        }
        reader->Close();

        System::String^ newMovieIds;
        if (String::IsNullOrEmpty(currentMovieIds)) {
            newMovieIds = this->MovieID;
        }
        else {
            newMovieIds = currentMovieIds + "," + this->MovieID;
        }

        Console::WriteLine("Current Movie IDs: " + currentMovieIds);
        Console::WriteLine("New Movie IDs: " + newMovieIds);

        MySqlCommand^ updateCommand = gcnew MySqlCommand("UPDATE user_reg SET MovieID = @MovieID WHERE Username = @Username", con);
        updateCommand->Parameters->AddWithValue("@MovieID", newMovieIds);
        updateCommand->Parameters->AddWithValue("@Username", username_cli);

        updateCommand->ExecuteNonQuery();

        MessageBox::Show("Successfully saved!");
    }
    catch (Exception^ ex) {
        MessageBox::Show(ex->Message);
    }
    finally {
        if (con->State == ConnectionState::Open) {
            con->Close();
        }
    }
}


