#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

int main()
{
    // khai báo
    WSADATA wsadata;
    SOCKET listeningSocket;
    struct sockaddr_in serverAddr, clientAddr;
    char buffer[1024];
    int clientAddrSize = sizeof(clientAddr);

    // khởi tạo
    if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
    {
        std::cerr << "Fail to initialize Winsock" << std::endl;
    }

    // tạo socket
    listeningSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (listeningSocket == INVALID_SOCKET)
    {
        std::cerr << "Socket error" << std::endl;
        WSACleanup();
        return 1;
    }

    // thiết lập địa chỉ cổng
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(54000);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // liên kết socket với địa chỉ cổng
    if (bind(listeningSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
    {
        std::cerr << "Bind failed." << std::endl;
        closesocket(listeningSocket);
        WSACleanup();
        return 1;
    }

    listen(listeningSocket, SOMAXCONN);
    std::cout << "Waiting for client connection..." << std::endl;

    SOCKET clientSocket = accept(listeningSocket, (struct sockaddr *)&clientAddr, &clientAddrSize);
    if (clientSocket == INVALID_SOCKET)
    {
        std::cerr << "Client connection failed." << std::endl;
        closesocket(listeningSocket);
        WSACleanup();
        return 1;
    }

    while (true)
    {
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesReceived > 0)
        {
            buffer[bytesReceived] = '\0';
            std::cout << "Received: " << buffer << std::endl;

            // Nếu nhận được thông điệp "exit", thoát khỏi vòng lặp
            if (strcmp(buffer, "exit") == 0)
            {
                std::cout << "Server shutting down..." << std::endl;
                break;
            }
        }
    }

    return 0;
}