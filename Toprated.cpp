#include "TopRated.h"
#include "MainPage.h"

using namespace LoginForm;

TopRated::TopRated(void) {
    InitializeComponent();
    client = gcnew HttpClient();
    MakeRequestAsync();
}

void TopRated::MakeRequestAsync() {
    String^ apiKey = "e18bd6b624b9b189e366056ce94a353c";
    String^ apiUrl = "https://api.themoviedb.org/3/movie/top_rated?api_key=" + apiKey;
    auto responseTask = client->GetAsync(apiUrl);
    responseTask->ContinueWith(gcnew Action<Task<HttpResponseMessage^>^>(this, &TopRated::HandleResponse));
}

delegate void PictureBoxWithTitleAndRatingDelegate(String^ path, String^ title, String^ rating, int movieId);

void TopRated::HandleResponse(Task<HttpResponseMessage^>^ responseTask) {
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

        if (d.IsObject() && d.HasMember("results") && d["results"].IsArray()) {
            for (rapidjson::SizeType i = 0; i < d["results"].Size(); i++) {
                if (d["results"][i].HasMember("title") && d["results"][i].HasMember("poster_path") && d["results"][i].HasMember("vote_average")) {
                    std::string title = d["results"][i]["title"].GetString();
                    std::string posterPath = d["results"][i]["poster_path"].GetString();
                    double rating = d["results"][i]["vote_average"].GetDouble();
                    int movieId = d["results"][i]["id"].GetInt();

                    // Convert from std::string to System::String^
                    String^ title_managed = gcnew String(title.c_str());
                    String^ posterPath_managed = gcnew String(posterPath.c_str());

                    // Format rating
                    String^ rating_managed;
                    if (rating == static_cast<int>(rating)) {
                        rating_managed = String::Format("{0:F0}", rating); // No decimal part
                    }
                    else {
                        rating_managed = String::Format("{0:F2}", rating); // With two decimal places
                    }

                    // Create PictureBox with title on UI thread
                    PictureBoxWithTitleAndRatingDelegate^ action = gcnew PictureBoxWithTitleAndRatingDelegate(this, &TopRated::CreatePictureBoxWithTitle);
                    this->Invoke(action, posterPath_managed, title_managed, rating_managed, movieId);
                }
            }
        }
        else {
            Console::WriteLine("API request failed: " + response->StatusCode.ToString());
        }
    }
}

void TopRated::CreatePictureBoxWithTitle(String^ path, String^ title, String^ rating, int movieId) {
            int picBoxWidth = 200;
            int picBoxHeight = 300;
            int labelHeight = 20;

            PictureBox^ pictureBox = gcnew PictureBox();
            pictureBox->SizeMode = PictureBoxSizeMode::StretchImage;
            pictureBox->Size = Drawing::Size(picBoxWidth, picBoxHeight);
            pictureBox->ImageLocation = "https://image.tmdb.org/t/p/w500" + path;
            pictureBox->Tag = movieId;
            pictureBox->Click += gcnew System::EventHandler(this, &TopRated::pictureBox_Click);

            Label^ titleLabel = gcnew Label();
            titleLabel->Text = title;
            titleLabel->Size = Drawing::Size(picBoxWidth, labelHeight);
            titleLabel->TextAlign = ContentAlignment::MiddleCenter;
            titleLabel->Location = Point(0, picBoxHeight);

            Label^ ratingLabel = gcnew Label();
            ratingLabel->Text = "Rating: " + rating;
            ratingLabel->Size = Drawing::Size(100, 20);
            ratingLabel->Location = Point(picBoxWidth - ratingLabel->Width, 0);
            ratingLabel->BackColor = Color::White;
            pictureBox->Controls->Add(ratingLabel);
            ratingLabel->Text = rating + "%";

            Panel^ panel = gcnew Panel();
            panel->Size = Drawing::Size(picBoxWidth, picBoxHeight + labelHeight);
            panel->Controls->Add(pictureBox);
            panel->Controls->Add(titleLabel);

            this->flowLayoutPanel->Controls->Add(panel);
}

void TopRated::pictureBox_Click(Object^ sender, EventArgs^ e) {
    PictureBox^ picBox = safe_cast<PictureBox^>(sender);
    int movieId = safe_cast<int>(picBox->Tag);
    GetMovieDetailsAsync(movieId);
    
}

void TopRated::BackButton_Click(Object^ sender, EventArgs^ e) {
    // Create a new instance of MainPage and show it
    MainPage^ mainPage = gcnew MainPage();
    mainPage->Show();

    // Close the current form
    this->Close();
    
}

void TopRated::GetMovieDetailsAsync(int movieId) {
    String^ apiKey = "e18bd6b624b9b189e366056ce94a353c";
    String^ apiUrl = "https://api.themoviedb.org/3/movie/" + movieId + "?api_key=" + apiKey;
    auto responseTask = client->GetAsync(apiUrl);
    responseTask->ContinueWith(gcnew Action<Task<HttpResponseMessage^>^>(this, &TopRated::HandleMovieDetailsResponse));
    
}

void TopRated::HandleMovieDetailsResponse(Task<HttpResponseMessage^>^ responseTask) {
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

        if (d.IsObject()) {
            std::string title = d["title"].GetString();
            std::string overview = d["overview"].GetString();
            std::string posterPath = d["poster_path"].GetString();
            std::string release_date = d["release_date"].GetString();
            double rating = d["vote_average"].GetDouble();
            int movieId = d["id"].GetInt();


            String^ title_managed = gcnew String(title.c_str());
            String^ overview_managed = gcnew String(overview.c_str());
            String^ posterPath_managed = gcnew String(posterPath.c_str());
            String^ release_date_managed = gcnew String(release_date.c_str());
            String^ movieId_managed = gcnew String(std::to_string(movieId).c_str());


            Overview^ overviewForm = gcnew Overview(movieId_managed, title_managed, overview_managed, "https://image.tmdb.org/t/p/w500" + posterPath_managed, release_date_managed, rating);
            overviewForm->ShowDialog();

        }
        else {
            Console::WriteLine("API request failed: " + response->StatusCode.ToString());
        }
    }
}

void TopRated::InitializeComponent(void) {
    System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(TopRated::typeid));
    this->flowLayoutPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
    this->titleLabel = (gcnew System::Windows::Forms::Label());
    this->scrollablePanel = (gcnew System::Windows::Forms::Panel());
    this->backButton = (gcnew System::Windows::Forms::Button());
    this->scrollablePanel->SuspendLayout();
    this->SuspendLayout();
    // 
    // flowLayoutPanel
    // 
    this->flowLayoutPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
        | System::Windows::Forms::AnchorStyles::Right));
    this->flowLayoutPanel->AutoScroll = true;
    this->flowLayoutPanel->BackColor = System::Drawing::Color::Transparent;
    this->flowLayoutPanel->Location = System::Drawing::Point(3, 86);
    this->flowLayoutPanel->Name = L"flowLayoutPanel";
    this->flowLayoutPanel->Size = System::Drawing::Size(1471, 345);
    this->flowLayoutPanel->TabIndex = 0;
    this->flowLayoutPanel->WrapContents = false;
    this->flowLayoutPanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &TopRated::flowLayoutPanel_Paint);
    // 
    // titleLabel
    // 
    this->titleLabel->BackColor = System::Drawing::Color::Transparent;
    this->titleLabel->Font = (gcnew System::Drawing::Font(L"Baskerville Old Face", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->titleLabel->ForeColor = System::Drawing::Color::Transparent;
    this->titleLabel->Location = System::Drawing::Point(623, 9);
    this->titleLabel->Name = L"titleLabel";
    this->titleLabel->Size = System::Drawing::Size(261, 56);
    this->titleLabel->TabIndex = 0;
    this->titleLabel->Text = L"CME Movies";
    this->titleLabel->Click += gcnew System::EventHandler(this, &TopRated::titleLabel_Click);
    // 
    // scrollablePanel
    // 
    this->scrollablePanel->AutoScroll = true;
    this->scrollablePanel->BackColor = System::Drawing::SystemColors::Control;
    this->scrollablePanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"scrollablePanel.BackgroundImage")));
    this->scrollablePanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
    this->scrollablePanel->Controls->Add(this->titleLabel);
    this->scrollablePanel->Controls->Add(this->flowLayoutPanel);
    this->scrollablePanel->Dock = System::Windows::Forms::DockStyle::Fill;
    this->scrollablePanel->ForeColor = System::Drawing::SystemColors::Control;
    this->scrollablePanel->Location = System::Drawing::Point(0, 0);
    this->scrollablePanel->Name = L"scrollablePanel";
    this->scrollablePanel->Size = System::Drawing::Size(1419, 821);
    this->scrollablePanel->TabIndex = 1;
    // 
    // backButton
    // 
    this->backButton->Location = System::Drawing::Point(0, 0);
    this->backButton->Name = L"backButton";
    this->backButton->Size = System::Drawing::Size(75, 23);
    this->backButton->TabIndex = 2;
    this->backButton->Text = L"Back";
    this->backButton->Click += gcnew System::EventHandler(this, &TopRated::BackButton_Click);
    // 
    // TopRated
    // 
    this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->ClientSize = System::Drawing::Size(1419, 821);
    this->Controls->Add(this->scrollablePanel);
    this->Controls->Add(this->backButton);
    this->Name = L"TopRated";
    this->Text = L"MainPage";
    this->scrollablePanel->ResumeLayout(false);
    this->ResumeLayout(false);

}


