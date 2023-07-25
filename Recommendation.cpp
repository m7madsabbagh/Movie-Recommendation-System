#include "Recommendation.h"
#include "Movie.h"

RecommendationHandler::RecommendationHandler()
{
    String^ constr = "Server=127.0.0.1;Uid=root;Pwd=;Database=database";
    con = gcnew MySqlConnection(constr);
}

List<Movie^>^ RecommendationHandler::getRecommendedMovies(String^ Username)
{
    List<String^>^ userGenres = getUserGenres(Username);
    List<Movie^>^ recommendedMovies = gcnew List<Movie^>();

    for each (String ^ genre in userGenres) {
        MySqlCommand^ cmd = gcnew MySqlCommand("SELECT * FROM Movies WHERE Genre = @Genre", con);
        cmd->Parameters->AddWithValue("@Genre", genre);

        con->Open();
        MySqlDataReader^ dr = cmd->ExecuteReader();

        while (dr->Read())
        {
            Movie^ movie = gcnew Movie();
            movie->Id = Convert::ToInt32(dr["Id"]);
            movie->Title = dr["Title"]->ToString();
            movie->Genre = dr["Genre"]->ToString();
            movie->ImageUrl = dr["ImageUrl"]->ToString();
            recommendedMovies->Add(movie);
        }
        con->Close();
    }

    return recommendedMovies;
}

List<String^>^ RecommendationHandler::getUserGenres(String^ Username)
{
    List<String^>^ userGenres = gcnew List<String^>();

    MySqlCommand^ cmd = gcnew MySqlCommand("SELECT * FROM user_reg WHERE Username=@Username", con);
    cmd->Parameters->AddWithValue("@Username", Username);

    con->Open();
    MySqlDataReader^ dr = cmd->ExecuteReader();
    while (dr->Read())
    {
        for (int i = 0; i < dr->FieldCount; i++)
        {
            // If the field is a genre and the value is 1, add the genre to the list
            if (dr->GetName(i) != "Username" && dr->GetBoolean(i))
            {
                userGenres->Add(dr->GetName(i));
            }
        }
    }
    con->Close();

    return userGenres;
}
