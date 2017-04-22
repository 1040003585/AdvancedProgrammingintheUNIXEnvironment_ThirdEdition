#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <netinet/in.h>  
#include <sys/socket.h>  
#include <arpa/inet.h>  
#include <string.h>  
 
/**
 * Copyright ? 2016 Authors. All rights reserved.
 *
 * FileName: client.c
 * Author: Wu_Being <1040003585@qq.com>
 * Date Time: 2017-04-21 22:02:1492783338
 * Description:客户端
 *
 */

int main (int argc, const char * argv[])  
{  

    if (argc != 3)
    {
        printf("[#] Usage: %s <ip> <port>\n", argv[0]);
        exit(1);
    }

    struct sockaddr_in server_addr;  
    server_addr.sin_family = AF_INET;  
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);  
    server_addr.sin_port = htons(atoi(argv[2]));  
    bzero(&(server_addr.sin_zero),8);  
  
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);  
    if (server_socket == -1) {  
        perror("[-] socket error");  
        return 1;  
    }  
    char recv_msg[1024];  
    char reply_msg[1024];  
  
    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in))==0) {  
    
        while (1) {  
            bzero(recv_msg, 1024);  
            bzero(reply_msg, 1024);  
            long byte_num = recv(server_socket,recv_msg,1024,0);  
            recv_msg[byte_num] = '\0';  
            printf("[+] server said:%s\n",recv_msg);  
  
            if(!strncmp(recv_msg, "end", 3)){
                break;
            }

            printf("[+] reply:");  
            fgets(reply_msg, 1024, stdin);

            if(!strncmp(reply_msg, "end", 3)){
                break;
            }      
            
            if (send(server_socket, reply_msg, 1024, 0) == -1) {  
                perror("[-] send error");  
            }  
        }  
  
    }  

    close(server_socket);
  
    // insert code here...  
    printf("[+] chat end...\n");  
    return 0;  
}