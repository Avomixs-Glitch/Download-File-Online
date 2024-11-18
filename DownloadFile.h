#include <iostream>
#include <curl/curl.h>
using namespace std;

bool downloadFile(const std::string& url, const std::string& outputFileName) {
    // Initialize libcurl
    curl_global_init(CURL_GLOBAL_ALL);
    CURL* curl = curl_easy_init();
    if (curl) {
        // Set URL to download
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        // Set output file
        FILE* outputFile = fopen(outputFileName.c_str(), "wb");
        if (outputFile) {
            // Set callback to write data to file
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, outputFile);
            // Perform the download
            CURLcode res = curl_easy_perform(curl);
            // Cleanup
            fclose(outputFile);
            curl_easy_cleanup(curl);
            if (res == CURLE_OK) {
                return true; // Download successfull
            }
        }
    }
    return false; // Download failed
};