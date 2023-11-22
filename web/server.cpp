//
// Created by maxgi on 11/22/2023.
//
#ifdef _WIN32
#include <winsock.h>
#include <sys/types.h>

void server(){
    WSAData m_wsaData;
    WSAStartup(MAKEWORD(2, 0), &m_wsaData);
    int port = 8800;
    auto winSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(winSocket != 0){
        exit(12);
    }

    sockaddr_in sockInfo;
    sockInfo.sin_family = AF_INET;
    sockInfo.sin_port = htons(8800);
    sockInfo.sin_addr.s_addr = inet_addr("0.0.0.0");



    closesocket(winSocket);
    WSACleanup();
}
#elif
#include <sys/socket.h>
void server(){
    return;
}
#endif

int main(){

}