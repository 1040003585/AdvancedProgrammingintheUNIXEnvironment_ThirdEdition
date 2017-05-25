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

static int count = 0;

void *HandleClient(void *arg)
{
    //count++;
    char buf[128] = {0};
    int newfd = *((int *)arg);

    while(1)
    {
        memset(buf, 0, sizeof(buf));

        read(newfd, buf, sizeof(buf));
        if((strncmp(buf, "exit", 4) == 0))
        {
            break;
        }
        
        int tmpfdout = dup(STDOUT_FILENO);
        if(dup2(newfd, STDOUT_FILENO) < 0)
        {
            perror("dup2");
            exit(1);
        }
        system(buf);
        dup2(tmpfdout, STDOUT_FILENO);
        //return;
    }
    
    //close(newfd);
    printf("one client exiting...\n");
    count--;
    pthread_exit(NULL);
}


int main(int argc, char *argv[])
{
    if(argc < 2)
    {
	printf("usage: %s port\n", argv[0]);
	exit(1);
    }	


    //参数定义
    struct sockaddr_in servaddr;
    int connfd = 0;
    int listenfd = 0;
    
    //结构体初始化
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[1]));
    servaddr.sin_addr.s_addr = INADDR_ANY;
    
    //生成socket
    listenfd = socket(AF_INET,SOCK_STREAM,0);
    
    //绑定
    bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    
    //监听
    listen(listenfd, 5);
    
    //线程并发服务器
    pthread_t tid;
    //定义线程属性
    pthread_attr_t attr;
    //对线程属性初始化
    int ret = pthread_attr_init(&attr);
    if(ret != 0)
    {
    	perror("pthread_attr_init");
    	exit(1);
    }
    //设置分离属性
    ret = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    if(ret != 0)
    {
    	perror("pthread_attr_setdetachstate");
    	exit(1);
    }
     
    while(1)
    {
        connfd = accept(listenfd, NULL, NULL);
        if(connfd < 0)
        {
            perror("accept");
            exit(1);
        }
        count++;
        printf("listenfd:%d\tconnfd:%d\n", listenfd, connfd);
        ret = pthread_create(&tid, &attr, HandleClient, (void *)&connfd);
      //  pthread_detach(tid); // 线程分离，结束时自动回收资源 
        if(ret != 0)
        {
            perror("pthread_create");
            exit(1);
        }
        printf("%d clients connected...\ttid:%lu\n", count, tid);
    }
      
   // pthread_join(tid, NULL);分离之后不能调用
   //销毁线程属性
    pthread_attr_destroy(&attr);
    close(connfd);
    return 0;
}










