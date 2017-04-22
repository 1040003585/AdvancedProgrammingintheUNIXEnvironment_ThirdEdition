#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

/**
 * Copyright ? 2016 Authors. All rights reserved.
 *
 * FileName: server.c
 * Author: Wu_Being <1040003585@qq.com>
 * Date Time: 2017-04-21 21:37:1492781830
 * Description: 服务端
 *
 */


int main(int argc, char *argv[])
{
    int serv_sock;
    int clnt_sock;

    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size;

    char message[] = "Hello, I am server!";

    if (argc != 2)
    {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    serv_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (serv_sock == -1){
      fprintf(stderr, "[-] sock() error.\n");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1){
      fprintf(stderr, "[-] bind() error.\n");
    }

    if (listen(serv_sock, 5) == -1){
      fprintf(stderr, "[-] listen() error.\n");
    }

    clnt_addr_size = sizeof(clnt_addr);
    clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
    if (clnt_sock == -1){
      fprintf(stderr, "[-] accept() error\n");
    }

    write(clnt_sock, message, sizeof(message));
    close(clnt_sock);
    close(serv_sock);

    return 0;
}
