# Internship-project
#include <iostream>
#include <vector>
#include <string>

class User {
private:
    std::string name;
    int age;
    std::vector<std::string> preferredGenres;

public:
    User(std::string name, int age, std::vector<std::string> preferredGenres)
        : name(name), age(age), preferredGenres(preferredGenres) {}

    std::string getName() const { return name; }
    int getAge() const { return age; }
    std::vector<std::string> getPreferredGenres() const { return preferredGenres; }
};

class RegistrationSystem {
private:
    std::vector<User> users;

public:
    void registerUser() {
        std::string name;
        int age;
        std::vector<std::string> preferredGenres;
        std::string genre;

        std::cout << "Enter your name: ";
        std::getline(std::cin, name);
        std::cout << "Enter your age: ";
        std::cin >> age;

        while (true) {
            std::cout << "Enter your preferred movie genre (or 'done' to finish): ";
            std::cin >> genre;
            if (genre == "done") {
                break;
            }
            else {
                preferredGenres.push_back(genre);
            }
        }

        users.emplace_back(name, age, preferredGenres);

        std::cout << "User registered successfully!\n";
    }

    // For demonstration purposes
    void printUsers() {
        for (const User& user : users) {
            std::cout << "Name: " << user.getName() << ", Age: " << user.getAge() << ", Genres: ";
            for (const std::string& genre : user.getPreferredGenres()) {
                std::cout << genre << " ";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    RegistrationSystem system;

    while (true) {
        std::cout << "Press 1 to register a new user, 2 to print all users, or 0 to quit: ";
        int choice;
        std::cin >> choice;

        std::cin.ignore();  // Ignore the newline left in the input buffer

        if (choice == 0) {
            break;
        }
        else if (choice == 1) {
            system.registerUser();
        }
        else if (choice == 2) {
            system.printUsers();
        }
    }

    return 0;
}
