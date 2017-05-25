#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>

#include <pthread.h>

/**
 * Copyright ? 2016 Authors. All rights reserved.
 *
 * FileName: server.c
 * Author: Wu_Being <1040003585@qq.com>
 * Date Time: 2017-04-24 22:02:1492783331
 * Description: 服务端 (建立TCP服务器和客户端
 * 客户端向服务器输入shell命令,服务器执行并返回结果。
 * 要求1：要求使用dup返回结果 ???文件
 * 要求2：要求使用线程实现，并且对多客户端进行管理)
 *
 */

#define MAX_MSG_LEN     1024

/* 处理客户端命令行线程函数 */
void *client_thread(void *arg)
{
    // 获取参数
    int sockfd = *(int *)arg;
    char recv_msg[MAX_MSG_LEN];
    char result[MAX_MSG_LEN] ;

    while(1)
    {
        bzero(recv_msg, MAX_MSG_LEN);
        bzero(result, MAX_MSG_LEN);
        // 接收客户端命令并处理
        long byte_num = recv(sockfd, recv_msg, MAX_MSG_LEN, 0);
        recv_msg[byte_num] = '\0';
        // printf("\t [+] ------------------------------\n");
        // printf("\t [+] connect at sockfd = %d\n", sockfd);
        // printf("\t [+] client command: %s", recv_msg);

        if(!strncmp(recv_msg, "end", 3)){
            printf("\t [#] sockfd %d end ~~~~~~~~~~~~~~~\n", sockfd);
            break;
        }


        int fd[2];
        if (pipe(fd)){
	    fprintf(stderr, "[-] pipe error");
        }
        if(fork() == 0) {
            close(fd[0]);
            dup2(fd[1], STDOUT_FILENO);
            close(fd[1]);
            // 服务器执行命令
            system(recv_msg);      
        }else {
            //sleep(1);
            close(fd[1]);
            int readCount ;
            while ((readCount = read(fd[0], result, MAX_MSG_LEN -1)) > 0) {
                result[readCount] = '\0';
                //puts(result);
                //printf("write1: %s \n",result);
                // 服务器回复客户端信息
                //strcpy(result, "ok...");
                send(sockfd, result, MAX_MSG_LEN, 0);
            }
            close(fd[0]);
    
        }
      
        
    }
    close(sockfd); 
   
    return NULL;
}


int main(int argc, const char * argv[])
{

    if (argc != 3)
    {
        fprintf(stderr, "[#] Usage: %s <server ip> <server port>\n", argv[0]);
        exit(1);
    }

    // 获取服务器地址和端口
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));
    bzero(&(server_addr.sin_zero), 8);

    // 创建服务器socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == -1)
    {
       perror("[-] server socket error");
       return 1;
    }

    // 服务器socket绑定地址端口
    int bind_result = bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if(bind_result == -1)
    {
        perror("[-] server socket bind server addr error");
        return -1;
    }

    // 服务器监听连接地址端口信息
    if(listen(server_socket, 5) == -1)
    {
        perror("[-] server listen port error");
        return -1;
    }

    
    struct sockaddr_in client_address;
    socklen_t address_len = sizeof(struct sockaddr_in);

    while(1)
    {
        printf("[#] server waiting accept connect .............................................\n");

        // 服务器每接受一个连接就创建一个线程处理
        int client_sockfd = accept(server_socket, (struct sockaddr *)&client_address, &address_len);
        pthread_t   tid;
        int err = pthread_create(&tid, NULL, client_thread, &client_sockfd);
        if(err == 0){
            printf("[#] hello, client = %d at thread tid = 0x%lx .............\n", client_sockfd, tid);
        }
        else{
            fprintf(stderr, "[#] can't create thread of sockfd = %d with err = %d.\n", client_sockfd, err);
        }

    }

    close(server_socket);

    return 0;
}

