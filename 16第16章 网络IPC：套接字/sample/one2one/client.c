#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

/**
 * Copyright ? 2016 Authors. All rights reserved.
 *
 * FileName: client.c
 * Author: Wu_Being <1040003585@qq.com>
 * Date Time: 2017-04-21 21:37:1492781839
 * Description:客户端
 *
 */
 

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in serv_addr;
    char message[30];
    int str_len;

    if (argc != 3)
    {
        printf("[#] Usage: %s <ip> <port>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1){
      fprintf(stderr, "[-] sock() error.\n");
      exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1){
      fprintf(stderr, "[-] connect() error.\n");
      exit(1);
    }

    str_len = read(sock, message, sizeof(message) - 1);
    if (str_len == -1){
      fprintf(stderr, "[-] read() error.\n");
      exit(1);
    }

    printf("Message from server: %s\n", message);


    close(sock);

    return 0;
}
