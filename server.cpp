#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

int main() {
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        perror("socket");
        return 1;
    }

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the address and port
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        perror("bind");
        close(serverSocket);
        return 1;
    }

    // Listen for incoming connections
    if (listen(serverSocket, 5) < 0) {
        perror("listen");
        close(serverSocket);
        return 1;
    }

    cout << "Server is listening on port 8080..." << endl;

    sockaddr_in clientAddress;
    socklen_t clientAddressLen = sizeof(clientAddress);
    
    // Accept a connection from a client
    int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddressLen);
    if (clientSocket < 0) {
        perror("accept");
        close(serverSocket);
        return 1;
    }

    cout << "Client connected." << endl;

    // Receive the message from the client
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer)); // Clear the buffer

    ssize_t bytesReceived = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
    if (bytesReceived < 0) {
        perror("recv");
        close(clientSocket);
        close(serverSocket);
        return 1;
    }

    cout << "Received message: " << buffer << endl;

    // Close the client socket
    close(clientSocket);

    // Close the server socket
    close(serverSocket);

    return 0;
}

