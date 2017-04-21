#include <stdio.h>
#include <string.h>
#include <unistd.h>	//fork()
#include <stdlib.h>	//exit()
#include <wait.h>	//waitpid(), signal()
#include <signal.h>	//signal() //+
#define MAXLINE 4096

/**
 * Copyright ? 2016 Authors. All rights reserved.
 *
 * FileName: .cpp
 * Author: Wu_Being <1040003585@qq.com>
 * Date Time: 2017-04-21 11:54:1492746868
 * Description: 
 *
 */


static void sig_int(int );//+ out signal-catching function

int main(int argc, char const *argv[])
{
	char buf[MAXLINE];
	pid_t pid;
	int status;

	if(signal(SIGINT, sig_int) == SIG_ERR){	//+
		fprintf(stderr, "[-] signal error.\n");
	}

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
		}//printf("%d\n\n", status);

		printf("%% ");
	}
	return 0;
}

void sig_int(int signo){ //+
	printf("[#] interrupt \n ");
	printf("%% ");
}

/*
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.9信号$ gcc 1shell.c 
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.9信号$ ./a.out 
% l
[-] couldn't execute: l
[#] can't pass to parameter to execlp
% ls
1shell.c  a.out
% ^C[#] interrupt 
ls
1shell.c  a.out
 % % who
wu_being tty7         2017-04-21 00:27 (:0)
% ^\退出 (核心已转储)
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.9信号$ 
*/