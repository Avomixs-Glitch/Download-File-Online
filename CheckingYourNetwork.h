#include <iostream>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

using namespace boost::asio;

void CheckingYourNetwork(string URL){
	ip::tcp::resolver resolver(io);
    ip::tcp::socket socket(io);

    // Resolve the host name and port number
    std::string url = URL;
    ip::tcp::resolver::query query(url, "http");
    ip::tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);

    // Connect the socket to the server
    connect(socket, endpoint_iterator);

    // Form the HTTP request
    std::string request = "GET / HTTP/1.1\r\nHost: www.example.com\r\nConnection: close\r\n\r\n";

    // Send the request
    write(socket, buffer(request));

    // Read and print the response
    streambuf response;
    read_until(socket, response, "\r\n");
    std::cout << &response;

};