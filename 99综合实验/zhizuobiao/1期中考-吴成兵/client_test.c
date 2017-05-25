/*
建立TCP服务器和客户端
客户端向服务器输入shell命令,服务器执行并返回结果。
要求1：要求使用dup返回结果
要求2：要求使用线程实现，并且对多客户端进行管理
相关函数可以man

*/
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <memory.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <pthread.h>


int main(int argc,char *argv[])
{
    //命令行参数判断
    if(argc < 3)
    {
        printf("usage:%s ip port\n", argv[0]);
        exit(0);
    }
    
    //参数定义
    struct sockaddr_in servaddr;
    char buf[2048] = {0};
    int sockfd = 0;
    
    //结构体初始化
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    inet_aton(argv[1], &servaddr.sin_addr);
    
    //生成socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    //连接服务器
    if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
    	perror("connect");
    	exit(1);
    }
    
    //循环收发数据
    while(1)
    {
        memset(buf, 0, sizeof(buf));
        printf("input a shell cmd(input exit to quit):");
        fgets(buf, sizeof(buf), stdin);
        write(sockfd, buf, sizeof(buf));
        if(strncmp(buf, "exit", 4) == 0)
        {
            break;
        }
        memset(buf, 0, sizeof(buf));

        read(sockfd, buf, sizeof(buf));
        printf("recv from server:\n%s\n", buf);
    }

    //关闭socket
    close(sockfd);
    return 0;    
}



