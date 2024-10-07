#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

int main()
{
    WSADATA wsaData;
    SOCKET listeningSocket;
    struct sockaddr_in serverAddr, clientAddr;
    char buffer[1024];
    int clientAddrSize = sizeof(clientAddr);

    // Khởi tạo Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        std::cerr << "Failed to initialize Winsock." << std::endl;
        return 1;
    }

    // Tạo socket
    listeningSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (listeningSocket == INVALID_SOCKET)
    {
        std::cerr << "Socket creation failed." << std::endl;
        WSACleanup();
        return 1;
    }

    // Thiết lập địa chỉ và cổng cho server
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(54000);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Liên kết socket với địa chỉ
    if (bind(listeningSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
    {
        std::cerr << "Bind failed." << std::endl;
        closesocket(listeningSocket);
        WSACleanup();
        return 1;
    }

    // Nghe kết nối
    listen(listeningSocket, SOMAXCONN);
    std::cout << "Waiting for client connection..." << std::endl;

    // Chấp nhận kết nối
    SOCKET clientSocket = accept(listeningSocket, (struct sockaddr *)&clientAddr, &clientAddrSize);
    if (clientSocket == INVALID_SOCKET)
    {
        std::cerr << "Client connection failed." << std::endl;
        closesocket(listeningSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "Client connected." << std::endl;

    // Nhận dữ liệu từ client
    // Phần mã thêm vào
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

    // Đóng kết nối
    closesocket(clientSocket);
    closesocket(listeningSocket);
    WSACleanup();
    return 0;
}
