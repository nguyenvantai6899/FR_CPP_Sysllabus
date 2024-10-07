#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

int main()
{
    WSADATA wsaData;
    SOCKET clientSocket;
    struct sockaddr_in serverAddr;

    // Khởi tạo Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        std::cerr << "Failed to initialize Winsock." << std::endl;
        return 1;
    }

    // Tạo socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET)
    {
        std::cerr << "Socket creation failed." << std::endl;
        WSACleanup();
        return 1;
    }

    // Thiết lập địa chỉ của server
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(54000);
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);

    // Kết nối đến server
    if (connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
    {
        std::cerr << "Connection to server failed." << std::endl;
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    // Gửi dữ liệu đến server
    while (true)
    {
        std::string message; // Sử dụng std::string để nhận thông điệp
        std::cout << "Enter message (type 'exit' to quit): ";
        std::getline(std::cin, message); // Nhận toàn bộ dòng

        // Gửi thông điệp
        send(clientSocket, message.c_str(), message.length(), 0);

        // Kiểm tra nếu người dùng muốn thoát
        if (message == "exit")
        {
            break; // Thoát vòng lặp
        }
    }

    // Đóng kết nối
    closesocket(clientSocket);
    WSACleanup();
    return 0;
}
