#pragma once

#include "Movie.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace MySql::Data::MySqlClient;

public ref class RecommendationHandler
{
public:
    RecommendationHandler();
    List<Movie^>^ getRecommendedMovies(String^ Username);
private:
    MySqlConnection^ con;
    List<String^>^ getUserGenres(String^ Username);
};
