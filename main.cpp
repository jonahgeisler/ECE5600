#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>

/********************************************************************
COMPILING INSTRUCTIONS:

g++ -o server main.cpp
make tcp_test
./server
./tcp_test <Ip address> (EL216-06 is 129.123.85.1)
********************************************************************/

constexpr int PORT = 5600;
constexpr int BUFFER_SIZE = 1024;

int main() {
    // Create socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Set up server address structure
    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the specified port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "#ERROR: Could not bind socket to port " << PORT << ".\n";
        close(server_socket);
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        std::cerr << "#EROR: Failed to listen on port " << PORT << ".\n";
        close(server_socket);
        return EXIT_FAILURE;
    }

    std::cout << "Server listening on port " << PORT << "...\n";

    // Accept a connection from the client
    sockaddr_in client_addr{};
    socklen_t client_len = sizeof(client_addr);
    int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len);

    // Open file
    std::ofstream out_file("received_data.txt", std::ios::binary);
    if (out_file) {

    	// Receive data from the client and write to the file
    	char buffer[BUFFER_SIZE];
    	ssize_t bytes_received;
    	while ((bytes_received = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        	out_file.write(buffer, bytes_received);
    	}

    	std::cout << "Data successfully written to 'received_data.txt'.\n";
    
    }
    else
    {
    	std::cout << "#ERROR: File did not open";
    }

    // Close sockets and file
    close(client_socket);
    close(server_socket);
    out_file.close();

    return EXIT_SUCCESS;
}

