#include <httplib.h> // HTTP server functionality
#include <iostream>  // Console output

using namespace httplib; // httplib namespace for convenience

int main() {
    
    Server webServer;

    // Define what happens when someone visits the root URL ("/")
    webServer.Get("/", [](const Request& req, Response& res) {
        // Create a simple HTML page as a response
        std::string htmlContent = R"(
            <html>
                <body>
                    <h1>Affiliate Metris Calculator</h1>
                    <p>This is a simple web page served by a C++ server.</p>
                    <p>The following will help you with your affiliate & general marketing calculations</p>
                </body>
            </html>
        )";

        // Set HTML, send page
        res.set_content(htmlContent, "text/html");
    });

    // Start the server
    std::cout << "Starting the web server...\n";
    std::cout << "Visit http://localhost:8080 in your browser to see the magic!\n";

    // Make the server listen on localhost at port 8080
    webServer.listen("localhost", 8080);

    // If the server stops, this line will be reached
    std::cout << "Server has stopped. Goodbye!\n";

    return 0; // Exit the program
}
