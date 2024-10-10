#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <vector>
#include <thread>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

void handel_client(SOCKET clientSocket)
{
    char buffer[1024];
    while (1)
    {
        int byteReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
        cout << byteReceived << endl;
        if (byteReceived > 0)
        {
            buffer[byteReceived] = '\0';
            cout << "received " << buffer << endl;
            if (strcmp(buffer, "exit") == 0)
            {
                std::cout << "Server shutting down..." << std::endl;
                break;
            }
        }
        else if (byteReceived == 0)
        {
            cout << "Connection closed." << endl;
            break;
        }
        else
        {
            cerr << "recv failed" << endl;
            break;
        }
    }
    closesocket(clientSocket);
}
int main()
{
    WSADATA wsadata;
    SOCKET listenSocket;
    struct sockaddr_in serverAddr, clientAddr;
    int clientSize = sizeof(clientAddr);
    vector<SOCKET> clients;

    WSAStartup(MAKEWORD(2, 2), &wsadata);

    listenSocket = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(54000);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(listenSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    cout << "waiting for connection" << endl;

    listen(listenSocket, SOMAXCONN);
    while (1)
    {
        SOCKET clientSocket = accept(listenSocket, (struct sockaddr *)&clientAddr, &clientSize);
        cout << clientSocket;
        if (clientSocket == INVALID_SOCKET)
        {
            cout << "Error: Couldn't connect" << endl;
            continue;
        }
        cout << "Client connected!" << endl;
        thread clientThread(handel_client, clientSocket);
        clientThread.detach();
        closesocket(clientSocket);
    }

    closesocket(listenSocket);
    WSACleanup();
    return 0;
}
