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

//constructor w ta7to front end design
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

    // Rating input field
    this->ratingInput = gcnew NumericUpDown();
    this->ratingInput->Minimum = 0;
    this->ratingInput->Maximum = 10;
    this->ratingInput->DecimalPlaces = 1;
    this->ratingInput->Increment = System::Decimal(0.1);
    tableLayoutPanel->Controls->Add(this->ratingInput, 0, 6);

    // Button for saving the rating
    this->saveRatingButton = gcnew Button();
    this->saveRatingButton->Text = "Save Rating";
    this->saveRatingButton->Click += gcnew System::EventHandler(this, &LoginForm::Overview::SaveRatingButton_Click);
    tableLayoutPanel->Controls->Add(this->saveRatingButton, 0, 7);

    //Button for the unsave 
    
    this->unsaveButton = gcnew Button();
    this->unsaveButton->Text = "Unsave Movie";
    this->unsaveButton->Click += gcnew System::EventHandler(this, &LoginForm::Overview::UnsaveMovieButton_Click);
    tableLayoutPanel->Controls->Add(this->unsaveButton, 0, 5);

    // Create TextBox for user input
    this->commentBox = gcnew TextBox();
    this->commentBox->Multiline = true;
    this->commentBox->Height = 60;
    tableLayoutPanel->Controls->Add(this->commentBox, 0, 8);

    // Create Button for submitting the comment
    this->submitCommentButton = gcnew Button();
    this->submitCommentButton->Text = "Submit Comment";
    this->submitCommentButton->Click += gcnew System::EventHandler(this, &LoginForm::Overview::SubmitCommentButton_Click);
    tableLayoutPanel->Controls->Add(this->submitCommentButton, 0, 9);

    // Create ListBox to display the comments
    this->commentsList = gcnew ListBox();
    tableLayoutPanel->Controls->Add(this->commentsList, 0, 10);
    tableLayoutPanel->SetColumnSpan(this->commentsList, 2);

    LoadComments();

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

            MySqlCommand^ checkUserCommand = gcnew MySqlCommand("SELECT COUNT(*) FROM user_reg WHERE Username = @Username", con);
            checkUserCommand->Parameters->AddWithValue("@Username", username_cli);

            int count = Convert::ToInt32(checkUserCommand->ExecuteScalar());

            if (count == 0) {
                MessageBox::Show("Username does not exist in the database!");
                return;
            }

            MySqlCommand^ checkExistCommand = gcnew MySqlCommand("SELECT COUNT(*) FROM saving_reg WHERE Username = @Username AND MovieID = @MovieID", con);
            checkExistCommand->Parameters->AddWithValue("@Username", username_cli);
            checkExistCommand->Parameters->AddWithValue("@MovieID", this->MovieID);

            int exists = Convert::ToInt32(checkExistCommand->ExecuteScalar());

            if (exists > 0) {
                MessageBox::Show("This movie is already saved!");
                return;
            }

            MySqlCommand^ insertCommand = gcnew MySqlCommand("INSERT INTO saving_reg (Username, MovieID) VALUES (@Username, @MovieID)", con);
            insertCommand->Parameters->AddWithValue("@Username", username_cli);
            insertCommand->Parameters->AddWithValue("@MovieID", this->MovieID);
            insertCommand->ExecuteNonQuery();
            insertCommand->ExecuteNonQuery();
            MessageBox::Show("Successfully saved!");

            
            OnMovieSaved(this->MovieID);

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

    void LoginForm::Overview::LoadComments()
    {
        // Get the username from the User class
        std::string username_std = User::Username;

        // Convert std::string to System::String^
        String^ username_cli = gcnew String(username_std.c_str());

        String^ constr = "Server=127.0.0.1;Uid=root;Pwd=;Database=database";
        MySqlConnection^ con = gcnew MySqlConnection(constr);

        try {
            con->Open();

            MySqlCommand^ getCommentsCommand = gcnew MySqlCommand("SELECT Username, Comment FROM Comments_reg WHERE MovieID = @MovieID", con);
            getCommentsCommand->Parameters->AddWithValue("@MovieID", this->MovieID);

            MySqlDataReader^ reader = getCommentsCommand->ExecuteReader();

            while (reader->Read()) {
                this->commentsList->Items->Add(reader["Username"] + ": " + reader["Comment"]);
            }
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

    System::Void LoginForm::Overview::SubmitCommentButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        // Get the username from the User class
        std::string username_std = User::Username;

        // Convert std::string to System::String^
        String^ username_cli = gcnew String(username_std.c_str());

        // Get the comment from the TextBox
        String^ comment = this->commentBox->Text;

        String^ constr = "Server=127.0.0.1;Uid=root;Pwd=;Database=database";
        MySqlConnection^ con = gcnew MySqlConnection(constr);

        try {
            con->Open();

            MySqlCommand^ insertCommand = gcnew MySqlCommand("INSERT INTO Comments_reg (Username, MovieID, Comment) VALUES (@Username, @MovieID, @Comment)", con);
            insertCommand->Parameters->AddWithValue("@Username", username_cli);
            insertCommand->Parameters->AddWithValue("@MovieID", this->MovieID);
            insertCommand->Parameters->AddWithValue("@Comment", comment);

            insertCommand->ExecuteNonQuery();

            MessageBox::Show("Successfully submitted the comment!");

            // Add the comment to the ListBox
            this->commentsList->Items->Add(username_cli + ": " + comment);

            // Clear the TextBox
            this->commentBox->Text = "";
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

System::Void LoginForm::Overview::SaveRatingButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Get the username from the User class
    std::string username_std = User::Username;

    // Convert std::string to System::String^
    String^ username_cli = gcnew String(username_std.c_str());

    // Convert the rating to double
    double rating = Convert::ToDouble(this->ratingInput->Value);

    String^ constr = "Server=127.0.0.1;Uid=root;Pwd=;Database=database";
    MySqlConnection^ con = gcnew MySqlConnection(constr);

    try {
        con->Open();

        MySqlCommand^ insertCommand = gcnew MySqlCommand("INSERT INTO Rating_reg (Username, MovieID, Rating) VALUES (@Username, @MovieID, @Rating)", con);
        insertCommand->Parameters->AddWithValue("@Username", username_cli);
        insertCommand->Parameters->AddWithValue("@MovieID", this->MovieID);
        insertCommand->Parameters->AddWithValue("@Rating", rating);

        insertCommand->ExecuteNonQuery();

        MessageBox::Show("Successfully saved the rating!");
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
System::Void LoginForm::Overview::UnsaveMovieButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Get the username from the User class
    std::string username_std = User::Username;

    // Convert std::string to System::String^
    String^ username_cli = gcnew String(username_std.c_str());

    String^ constr = "Server=127.0.0.1;Uid=root;Pwd=;Database=database";
    MySqlConnection^ con = gcnew MySqlConnection(constr);

    try {
        con->Open();

        MySqlCommand^ deleteCommand = gcnew MySqlCommand("DELETE FROM saving_reg WHERE Username = @Username AND MovieID = @MovieID", con);
        deleteCommand->Parameters->AddWithValue("@Username", username_cli);
        deleteCommand->Parameters->AddWithValue("@MovieID", this->MovieID);

        int rowsAffected = deleteCommand->ExecuteNonQuery();

        if (rowsAffected > 0) {
            MessageBox::Show("Successfully unsaved the movie!");
        }
        else {
            MessageBox::Show("Movie is not saved.");
        }
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



LoginForm::Overview::~Overview()
{
   
}
