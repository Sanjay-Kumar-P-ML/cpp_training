#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstdlib> // For exit()
#include <cerrno>  // For errno

using namespace std;

int main() {
    // Creating socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        cerr << "Socket creation failed!" << endl;
    }

    // Specifying address
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // Sending connection request
    try {
        if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
            throw strerror(errno);  // Throwing the system error message
        } else {
            // Sending data
            const char* message = "Hello, server!";
            send(clientSocket, message, strlen(message), 0);
        }
    }
    catch (const char* msg) {
        cout<<"Errno: "<<errno<<endl;
        cerr << "Connection failed: " << msg << endl;  // Printing system error message
                                                       //
    }

    // Closing socket
    close(clientSocket);

    cout << "Reached End" << endl;
    return 0;
}
