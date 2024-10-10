#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")
using namespace std;
int main()
{
    WSADATA wsaData;
    SOCKET clientSocket;
    struct sockaddr_in serverAddr;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        std::cerr << "Failed to initialize Winsock." << std::endl;
        return 1;
    }

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET)
    {
        std::cerr << "Socket creation failed." << std::endl;
        WSACleanup();
        return 1;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(54000);
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);

    if (connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
    {
        std::cerr << "Connection to server failed." << std::endl;
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    while (true)
    {
        std::string message;
        std::cout << "Enter message (type 'exit' to quit): ";
        std::getline(std::cin, message);

        if (message == "exit")
        {
            break;
        }
    }

    closesocket(clientSocket);
    WSACleanup();
    return 0;
}