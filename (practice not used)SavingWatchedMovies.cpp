#include <string>
#include <map>

class Movie {
private:
    std::string title;
    double rating;
    // other attributes
public:
    Movie(const std::string& title, double rating)
        : title(title), rating(rating) {}

    // getters
    std::string getTitle() const { return title; }
    double getRating() const { return rating; }

    // setters
    void setTitle(const std::string& title) { this->title = title; }
    void setRating(double rating) { this->rating = rating; }
};

// You need to define operator< for the map key type (Movie in this case)
bool operator<(const Movie& lhs, const Movie& rhs) {
    return lhs.getTitle() < rhs.getTitle();
}

class User {
    //...
    std::map<Movie, int> watched_movies;  // mapping movie to user's rating

public:
    void addWatchedMovie(const Movie& movie, int user_rating) {
        watched_movies[movie] = user_rating;
    }

    std::map<Movie, int> getWatchedMovies() const {
        return watched_movies;
    }
};
