//this window opens when the user clicks on a specific movie

#include "Overview.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace LoginForm {
    Label^ CreateLabel(System::String^ text)
    {
        Label^ label = gcnew Label();
        label->Text = text;
        label->AutoSize = true;
        label->Padding = System::Windows::Forms::Padding(10); // Add padding for better spacing

        return label;
    }

    Overview::Overview(System::String^ title, System::String^ overview, System::String^ posterPath, System::String^ release_date, double rating)
    {
        
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
    }
}