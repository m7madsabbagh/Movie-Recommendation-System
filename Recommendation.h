#pragma once

#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>
#include "Movie.h"
#include "User.h"

using namespace System;
using namespace System::IO;
using namespace System::Net;
using namespace MySql::Data::MySqlClient;
using namespace System::Net::Http;
using namespace System::Threading::Tasks;
using namespace System::Collections::Generic;

namespace LoginForm {

    public ref class Recommed : public System::Windows::Forms::Form
    {
    private:
    private:

        List<String^>^ userGenrePreferences;
        List<Movie^>^ allMovies;
        HttpClient^ client;
        System::String^ Username;
    private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel;


        System::ComponentModel::Container^ components;



    public:
        Recommed(List<String^>^ userGenres, List<Movie^>^ allMovies, String^ LoggedInUsername);
        void LoadLikedGenres(String^ username);
        void GetMovieListAsync(String^ genre);
        String^ GetGenreId(String^ genre);
        void HandleMovieListResponse(Task<HttpResponseMessage^>^ responseTask);
        void CreatePictureBoxWithTitle(String^ path, String^ title);
        void InitializeComponent(void);
        delegate void PictureBoxWithTitleDelegate(String^ path, String^ title);

    
   
    };

}
