#include "Display.h"

using namespace LoginForm;
using namespace MySql::Data::MySqlClient;

Display::Display(String^ loggedInUsername) {
    InitializeComponent();
    client = gcnew HttpClient();
    Username = loggedInUsername;
    LoadSavedMovies(Username);
}

void Display::LoadSavedMovies(String^ username) {
    try {
        MySqlConnection^ con = gcnew MySqlConnection("Server=127.0.0.1;Uid=root;Pwd=;Database=database");
        con->Open();
        String^ query = "SELECT MovieID FROM saving_reg WHERE Username = @username";
        MySqlCommand^ cmd = gcnew MySqlCommand(query, con);
        cmd->Parameters->AddWithValue("@username", username);
        MySqlDataReader^ reader = cmd->ExecuteReader();

        while (reader->Read()) {
            String^ movieIdString = reader->GetString("MovieID");
            try {

                GetMovieDetailsAsync(movieIdString);
            }
            catch (System::FormatException^ ex) {
                MessageBox::Show("MovieID is not in correct format: " + movieIdString);
            }
        }

        reader->Close();
        con->Close();
    }
    catch (Exception^ ex) {
        MessageBox::Show(ex->Message);
    }
}



void Display::GetMovieDetailsAsync(String^ movieTitle) {
    String^ apiKey = "e18bd6b624b9b189e366056ce94a353c";
    String^ escapedMovieTitle = Uri::EscapeDataString(movieTitle);
    String^ apiUrl = "https://api.themoviedb.org/3/search/movie?api_key=" + apiKey + "&query=" + escapedMovieTitle;
    auto responseTask = client->GetAsync(apiUrl);
    responseTask->ContinueWith(gcnew Action<Task<HttpResponseMessage^>^>(this, &Display::HandleMovieDetailsResponse));
}


void Display::HandleMovieDetailsResponse(Task<HttpResponseMessage^>^ responseTask) {
    auto response = responseTask->Result;
    if (response->IsSuccessStatusCode) {
        auto contentTask = response->Content->ReadAsStringAsync();
        contentTask->Wait();
        String^ content = contentTask->Result;

        // Convert from System::String^ to std::string
        msclr::interop::marshal_context context;
        std::string content_std_str = context.marshal_as<std::string>(content);

        // Parse with RapidJSON
        rapidjson::Document d;
        d.Parse(content_std_str.c_str());

        if (d.IsObject() && d.HasMember("results") && d["results"].IsArray() && !d["results"].Empty()) {
            // Taking the first result from the search
            const rapidjson::Value& movie = d["results"][0];

            std::string title = movie["title"].GetString();
            std::string overview = movie["overview"].GetString();
            std::string posterPath = movie["poster_path"].GetString();
            std::string release_date = movie["release_date"].GetString();
            double rating = movie["vote_average"].GetDouble();

            // Convert from std::string to System::String^
            String^ title_managed = gcnew String(title.c_str());
            String^ overview_managed = gcnew String(overview.c_str());
            String^ posterPath_managed = gcnew String(posterPath.c_str());
            String^ release_date_managed = gcnew String(release_date.c_str());

            // Create PictureBox with title on UI thread
            PictureBoxWithTitleDelegate^ action = gcnew PictureBoxWithTitleDelegate(this, &Display::CreatePictureBoxWithTitle);
            this->Invoke(action, posterPath_managed, title_managed);
        }
        else {
            Console::WriteLine("API request failed: " + response->StatusCode.ToString());
        }
    }
}


void Display::CreatePictureBoxWithTitle(String^ path, String^ title) {
    int picBoxWidth = 200;
    int picBoxHeight = 300;
    int labelHeight = 20;

    PictureBox^ pictureBox = gcnew PictureBox();
    pictureBox->SizeMode = PictureBoxSizeMode::StretchImage;
    pictureBox->Size = Drawing::Size(picBoxWidth, picBoxHeight);
    pictureBox->ImageLocation = "https://image.tmdb.org/t/p/w500" + path;

    Label^ titleLabel = gcnew Label();
    titleLabel->Text = title;
    titleLabel->Size = Drawing::Size(picBoxWidth, labelHeight);
    titleLabel->TextAlign = ContentAlignment::MiddleCenter;
    titleLabel->Location = Point(0, picBoxHeight);

    Panel^ panel = gcnew Panel();
    panel->Size = Drawing::Size(picBoxWidth, picBoxHeight + labelHeight);
    panel->Controls->Add(pictureBox);
    panel->Controls->Add(titleLabel);

    this->flowLayoutPanel->Controls->Add(panel);
}

void Display::InitializeComponent(void) {
    this->flowLayoutPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
    this->SuspendLayout();
    // 
    // flowLayoutPanel
    // 
    this->flowLayoutPanel->AutoScroll = true;
    this->flowLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
    this->flowLayoutPanel->Location = System::Drawing::Point(0, 0);
    this->flowLayoutPanel->Name = L"flowLayoutPanel";
    this->flowLayoutPanel->Size = System::Drawing::Size(778, 539);
    this->flowLayoutPanel->TabIndex = 0;
    // 
    // Display
    // 
    this->ClientSize = System::Drawing::Size(778, 539);
    this->Controls->Add(this->flowLayoutPanel);
    this->Name = L"Display";
    this->Load += gcnew System::EventHandler(this, &Display::Display_Load);
    this->ResumeLayout(false);

}

void Display::Display_Load(System::Object^ sender, System::EventArgs^ e) {
    // No implementation was provided in original file, add here if needed
}
