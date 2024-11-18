#include <iostream>
#include <curl/curl.h>
#include "CheckingYourNetwork.h";
#include "DownloadFile.h";
// Function to download a file from a URL using libcurl

int main() {
    // Example URL and output file name
    std::string driverUrl = "Your Link";
    std::string outputFileName = "driver.zip";//you can put whatever you want [RAR] OR [7z] OTHER.
    std::string URL = "google.com";

    if(CheckingYourNetwork(URL) == true){

    // Download the driver
    if (downloadFile(driverUrl, outputFileName)) {
    	std::cout<<"Your File Downloading Here"<<endl;
        std::cout << "Driver downloaded successfully.\n";

        // Now you can proceed with extracting and installing the driver
    } else {
        std::cout << "Failed to download driver.\n";
    }
	}else{
		return 0;
	}
};
