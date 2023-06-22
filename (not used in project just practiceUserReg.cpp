#include <string>
#include <vector>
#include <algorithm>

class User {
private:
    std::string name;
    int age;
    std::vector<std::string> preferred_genres;
public:
    User(const std::string& name, int age, const std::vector<std::string>& preferred_genres)
        : name(name), age(age), preferred_genres(preferred_genres) {}

    // getters
    std::string getName() const { return name; }
    int getAge() const { return age; }
    std::vector<std::string> getPreferredGenres() const { return preferred_genres; }

    // setters
    void setName(const std::string& name) { this->name = name; }
    void setAge(int age) { this->age = age; }
    void setPreferredGenres(const std::vector<std::string>& preferred_genres) { this->preferred_genres = preferred_genres; }
};

class UserManager {
private:
    std::vector<User> users;
public:
    UserManager() {}

    // method to add new user
    void addUser(const User& user) { users.push_back(user); }

    // method to check if a user exists
    bool isUserExists(const std::string& name) {
        return std::any_of(users.begin(), users.end(), [&](const User& user) { return user.getName() == name; });
    }

    // get all users
    std::vector<User> getUsers() const { return users; }
};
