#include <nlohmann/json.hpp>
#include <curl/curl.h>
#include <sstream>

class MovieAPI {
public:
    // Method to send a GET request and return the body of the response
    std::string sendGETRequest(const std::string& url) {
        CURL* curl = curl_easy_init();
        std::string response_string;

        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
            curl_easy_perform(curl);
            curl_easy_cleanup(curl);
        }

        return response_string;
    }

    // Method to parse a JSON response
    nlohmann::json parseJSON(const std::string& json_string) {
        return nlohmann::json::parse(json_string);
    }

private:
    static size_t writeCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
        userp->append((char*)contents, size * nmemb);
        return size * nmemb;
    }
};
