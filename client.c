#include <winsock2.h>
#include <stdio.h>

#pragma comment(lib, "ws2_32.lib")

#define PORT 8888
#define BUFFER_SIZE 1024

int main() {
    // Initialize Winsock
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed: %d\n", iResult);
        return 1;
    }

    // Create a socket
    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (clientSocket == INVALID_SOCKET) {
        printf("Error at socket(): %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    // Connect to the server
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr("10.5.105.55");
    serverAddress.sin_port = htons(PORT);
    if (connect(clientSocket, (SOCKADDR *) & serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        printf("connect() failed: %d\n", WSAGetLastError());
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    // Send messages to the server and receive the same message back
    char sendBuffer[BUFFER_SIZE];
    char recvBuffer[BUFFER_SIZE];
    int bytesSent;
    int bytesReceived;
    while (1) {
        printf("masukkan pesan: ");
        fgets(sendBuffer, BUFFER_SIZE, stdin);
        bytesSent = send(clientSocket, sendBuffer, strlen(sendBuffer), 0);
        if (bytesSent == SOCKET_ERROR) {
            printf("send() failed: %d\n", WSAGetLastError());
            break;
        }
        bytesReceived = recv(clientSocket, recvBuffer, BUFFER_SIZE, 0);
        if (bytesReceived == SOCKET_ERROR) {
            printf("recv() failed: %d\n", WSAGetLastError());
            break;
        }
        if (bytesReceived == 0) {
            printf("Connection closed\n");
            break;
        }
        recvBuffer[bytesReceived] = '\0';
        printf("Received from server: %s\n", recvBuffer);
    }

    // Cleanup
    closesocket(clientSocket);
    WSACleanup();
    return 0;
}
