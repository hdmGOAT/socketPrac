#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]){
    
    if(argc < 2){
        fprintf(stderr, "Port number not provided. Program terminated\n");
        exit(1);
    }

    int sockfd, newsockfd, port;
    char buffer[255];

    struct sockaddr_in serv_addr, cli_addr;
    int clilen = sizeof(cli_addr);

    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
    printf("WSAStartup failed.\n");
    return 1;
}

    int result;
    result = WSAStartup(MAKEWORD(2, 2), &wsaData);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0){
        error(" Eroor opening socket");
    };
    bzero((serv_addr, sizeof(serv_addr)));

    port = atoi(argv[1]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
        error("Binding failed");
    }
    

    //
}