#include "Overview.h"

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
    label->Padding = System::Windows::Forms::Padding(10); // Add padding for better spacing

    return label;
}


LoginForm::Overview::Overview(System::String^ title, System::String^ overview, System::String^ posterPath, System::String^ release_date, double rating)
{
    this->Username = title;
    this->MovieID = overview;

    // Initialize the form and set properties
    this->Text = "Movie Overview";
    this->WindowState = FormWindowState::Maximized;

    // Create the TableLayoutPanel to hold the controls
    TableLayoutPanel^ tableLayoutPanel = gcnew TableLayoutPanel();
    tableLayoutPanel->Dock = DockStyle::Fill;
    tableLayoutPanel->AutoSize = true;
    tableLayoutPanel->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
    tableLayoutPanel->ColumnCount = 2;
    tableLayoutPanel->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
    tableLayoutPanel->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));

    // Create and add the labels to the TableLayoutPanel
    Label^ titleLabel = CreateLabel("Title: " + title);
    Label^ overviewLabel = CreateLabel("Overview: " + overview);
    Label^ releaseDateLabel = CreateLabel("Release Date: " + release_date);
    Label^ ratingLabel = CreateLabel("Rating: " + rating.ToString());

    tableLayoutPanel->Controls->Add(titleLabel, 0, 0);
    tableLayoutPanel->Controls->Add(overviewLabel, 0, 1);
    tableLayoutPanel->Controls->Add(releaseDateLabel, 0, 2);
    tableLayoutPanel->Controls->Add(ratingLabel, 0, 3);

    // Create the PictureBox and set its properties
    PictureBox^ pictureBox = gcnew PictureBox();
    pictureBox->SizeMode = PictureBoxSizeMode::Zoom;
    pictureBox->ImageLocation = posterPath;
    pictureBox->Dock = DockStyle::Fill;

    // Add the PictureBox to the TableLayoutPanel
    tableLayoutPanel->Controls->Add(pictureBox, 1, 0);
    tableLayoutPanel->SetRowSpan(pictureBox, 4);

    // Add the TableLayoutPanel to the form
    this->Controls->Add(tableLayoutPanel);

    this->saveButton = gcnew Button();
    this->saveButton->Text = "Save Movie";
    this->saveButton->Click += gcnew System::EventHandler(this, &LoginForm::Overview::SaveMovieButton_Click);
    tableLayoutPanel->Controls->Add(this->saveButton, 0, 5);
}

System::Void LoginForm::Overview::SaveMovieButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Create a new MySqlConnection
    String^ constr = "Server=127.0.0.1;Uid=root;Pwd=;Database=database";
    MySqlConnection^ con = gcnew MySqlConnection(constr);

    try {
        // Open the connection
        con->Open();

        // Create a command to check if the username exists
        MySqlCommand^ checkCommand = gcnew MySqlCommand("SELECT COUNT(*) FROM user_reg WHERE Username = @Username", con);
        checkCommand->Parameters->AddWithValue("@Username", this->Username);

        // Execute the command and get the count
        int count = Convert::ToInt32(checkCommand->ExecuteScalar());

        if (count == 0) {
            // If the count is 0, the username does not exist in the database
            MessageBox::Show("Username does not exist in the database!");
            return;
        }

        // Create a command to get the current movie IDs for the user
        MySqlCommand^ getCommand = gcnew MySqlCommand("SELECT MovieID FROM user_reg WHERE Username = @Username", con);
        getCommand->Parameters->AddWithValue("@Username", this->Username);

        // Execute the command and get the current Movie_IDs
        MySqlDataReader^ reader = getCommand->ExecuteReader();

        // Get the current Movie_IDs
        System::String^ currentMovieIds = nullptr;
        if (reader->Read())
        {
            currentMovieIds = reader->GetString(0);
        }
        reader->Close();

        // Append the new Movie_ID
        System::String^ newMovieIds;
        if (String::IsNullOrEmpty(currentMovieIds)) {
            newMovieIds = this->MovieID;
        }
        else {
            newMovieIds = currentMovieIds + "," + this->MovieID;
        }

        // Print debug messages
        Console::WriteLine("Current Movie IDs: " + currentMovieIds);
        Console::WriteLine("New Movie IDs: " + newMovieIds);

        // Create a command to update the Movie_IDs
        MySqlCommand^ updateCommand = gcnew MySqlCommand("UPDATE user_reg SET MovieID = @MovieID WHERE Username = @Username", con);
        updateCommand->Parameters->AddWithValue("@MovieID", newMovieIds);
        updateCommand->Parameters->AddWithValue("@Username", this->Username);

        // Execute the update command
        updateCommand->ExecuteNonQuery();

        // Show success message
        MessageBox::Show("Successfully saved!");
    }
    catch (Exception^ ex) {
        // Show error message
        MessageBox::Show(ex->Message);
    }
    finally {
        // Ensure the connection is closed in case of an exception
        if (con->State == ConnectionState::Open) {
            con->Close();
        }
    }
}


