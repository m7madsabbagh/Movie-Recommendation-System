#include "Recommed.h"
#include "User.h"
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using namespace System;
using namespace System::IO;
using namespace System::Net;
using namespace MySql::Data::MySqlClient;
using namespace LoginForm;
using namespace rapidjson;
using namespace System::Net::Http;
using namespace System::Threading::Tasks;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Drawing;

Recommed::Recommed(List<String^>^ userGenres, List<Movie^>^ allMovies, String^ LoggedInUsername)
{
	Console::WriteLine("In the Recommed constructor");
	this->userGenrePreferences = userGenres;
	this->allMovies = allMovies;
	
	client = gcnew HttpClient();
	InitializeComponent();
	Username = LoggedInUsername;
	LoadLikedGenres(Username);
}



void Recommed::LoadLikedGenres(String^ username)
{
	Console::WriteLine("Loading liked genres for " + username);	
	gcnew String(User::Username.c_str());
	try {
		MySqlConnection^ con = gcnew MySqlConnection("Server=127.0.0.1;Uid=root;Pwd=;Database=database");
		con->Open();
		String^ query = "SELECT Action, Adventure, Animation, Comedy, Drama, Fantasy, History, Horror, Mystery, Romance, SciFi, Thriller FROM user_reg WHERE Username = @username";
		MySqlCommand^ cmd = gcnew MySqlCommand(query, con);
		cmd->Parameters->AddWithValue("@username", username);
		MySqlDataReader^ reader = cmd->ExecuteReader();

		while (reader->Read()) {
			for (int i = 0; i < reader->FieldCount; i++) {
				if (reader->GetInt32(i) == 1) {
					String^ genre = reader->GetName(i);
					Console::WriteLine("Liked genre: " + genre);
					GetMovieListAsync(genre);
				}
			}
		}

		reader->Close();
		con->Close();
	}
	catch (Exception^ ex) {
		MessageBox::Show(ex->Message);
	}
}

String^ Recommed::GetGenreId(String^ genre)
{
	Dictionary<String^, String^>^ genreIds = gcnew Dictionary<String^, String^>();
	genreIds->Add("Action", "28");
	genreIds->Add("Adventure", "12");
	genreIds->Add("Animation", "16");
	genreIds->Add("Comedy", "35");
	genreIds->Add("Drama", "18");
	genreIds->Add("Fantasy", "14");
	genreIds->Add("History", "36");
	genreIds->Add("Horror", "27");
	genreIds->Add("Mystery", "9648");
	genreIds->Add("Romance", "10749");
	genreIds->Add("SciFi", "878");
	genreIds->Add("Thriller", "53");

	return genreIds[genre];
}

void Recommed::GetMovieListAsync(String^ genre)
{
	Console::WriteLine("Sending API request for genre: " + genre);
	String^ apiKey = "e18bd6b624b9b189e366056ce94a353c";
	String^ genreId = GetGenreId(genre);
	String^ apiUrl = "https://api.themoviedb.org/3/discover/movie?api_key=" + apiKey + "&with_genres=" + genreId;
	auto responseTask = client->GetAsync(apiUrl);
	responseTask->ContinueWith(gcnew Action<Task<HttpResponseMessage^>^>(this, &Recommed::HandleMovieListResponse));
}



void Recommed::HandleMovieListResponse(Task<HttpResponseMessage^>^ responseTask)
{
	Console::WriteLine("Handling API response...");
	auto response = responseTask->Result;
	if (response->IsSuccessStatusCode) {
		auto contentTask = response->Content->ReadAsStringAsync();
		contentTask->Wait();
		String^ content = contentTask->Result;

	
		msclr::interop::marshal_context context;
		std::string content_std_str = context.marshal_as<std::string>(content);

	
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
			PictureBoxWithTitleDelegate^ action = gcnew PictureBoxWithTitleDelegate(this, &Recommed::CreatePictureBoxWithTitle);
			this->Invoke(action, posterPath_managed, title_managed);
		}
		else {
			Console::WriteLine("API request failed: " + response->StatusCode.ToString());
		}
	}
	else {
		Console::WriteLine("API response failed: " + response->StatusCode.ToString());
	}
}




void Recommed::CreatePictureBoxWithTitle(String^ path, String^ title)
{
	Console::WriteLine("Creating PictureBox for title: " + title);

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
	this->flowLayoutPanel->BringToFront();
	
}

void Recommed::InitializeComponent(void)
{
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
	// Recommed
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->ClientSize = System::Drawing::Size(1290, 518);
	this->Controls->Add(this->flowLayoutPanel);
	this->Name = L"Recommed";
	this->Text = L"Recommed";
	this->ResumeLayout(false);

}
