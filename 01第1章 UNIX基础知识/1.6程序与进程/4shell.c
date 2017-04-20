#include <stdio.h>
#include <string.h>
#include <unistd.h>	//fork()
#include <stdlib.h>	//exit()
#include <wait.h>	//waitpid()
#define MAXLINE 4096

/**
 * Copyright ? 2016 Authors. All rights reserved.
 *
 * FileName: .cpp
 * Author: Wu_Being <1040003585@qq.com>
 * Date Time: 2017-04-20 16:53:1492678405
 * Description: 
 *
 */



int main(int argc, char const *argv[])
{
	char buf[MAXLINE];
	pid_t pid;
	int status;

	printf("%% ");//print prompt
	while(fgets(buf, MAXLINE, stdin) != NULL){
		if(buf[strlen(buf)-1] == '\n'){
			buf[strlen(buf)-1] = 0;//good
		}
		if((pid=fork()) < 0){
			fprintf(stderr, "[-] fork error\n");
		}else if(pid == 0){		/* child */
			execlp(buf, buf, (char*)0);
			fprintf(stderr, "[-] couldn't execute: %s\n", buf);
			fprintf(stderr, "[#] can't pass to parameter to execlp\n");
			exit(127);
		}

		/* parent */
		if((pid=waitpid(pid, &status, 0)) < 0){
			fprintf(stderr, "[-] waitpid error\n");
		}printf("%d\n\n", status);

		printf("%% ");
	}
	return 0;
}

/*
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.6程序与进程$ gcc 4shell.c 
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.6程序与进程$ ./a.out 
% ls
1getpid.c  2fork.c  3fork.c  4shell.c  a2.out  a.out
0

% who
wu_being tty7         2017-04-19 16:23 (:0)
0

% pwd
/home/wu_being/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.6程序与进程
0

% dir
1getpid.c  2fork.c  3fork.c  4shell.c  a2.out  a.out
0

% mv a2.out a3.out
[-] couldn't execute: mv a2.out a3.out
32512
[#] can't pass to parameter to execlp
% wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.6程序与进程$ 
*/