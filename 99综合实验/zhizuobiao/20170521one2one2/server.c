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
 * FileName: server.c
 * Author: Wu_Being <1040003585@qq.com>
 * Date Time: 2017-04-21 22:02:1492783331
 * Description: 服务端
 *
 */


    
int main(int argc, const char * argv[])  
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
    bzero(&(server_addr.sin_zero), 8);  
  
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);  
    if(server_socket == -1)  
    {  
       perror("[-] socket error");  
       return 1;  
    }  
  
    int bind_result = bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));  
    if(bind_result == -1)  
    {  
        perror("[-] bind error");  
        return -1;  
    }  
  
    if(listen(server_socket, 5) == -1)  
    {  
        perror("[-] listen error");  
        return -1;  
    }  
  
    struct sockaddr_in client_address;  
    socklen_t address_len;  
    int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &address_len);  
    if(client_socket == -1)  
    {  
        perror("[-] accept error");  
        return -1;  
    }  
  
    char recv_msg[1024];  
    char reply_msg[1024];  
      
    while(1)  
    {  
        bzero(recv_msg, 1024);  
        bzero(reply_msg, 1024);  
      
        printf("[+] reply:");  
        fgets(reply_msg, 1024, stdin);
        send(client_socket, reply_msg, 1024, 0);  
        
        if(!strncmp(reply_msg, "end", 3)){
            break;
        }      
        
        long byte_num = recv(client_socket, recv_msg, 1024, 0);  
        recv_msg[byte_num] = '\0';  
        printf("[+] client said:%s\n", recv_msg);  

        if(!strncmp(recv_msg, "end", 3)){
            break;
        }
    }  

    close(client_socket);
    
    return 0;  
}  