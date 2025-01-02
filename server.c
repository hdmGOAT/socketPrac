#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <winsock2.h>

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
    
}