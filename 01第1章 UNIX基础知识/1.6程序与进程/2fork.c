#include <stdio.h>
#include <unistd.h>

/**
 * Copyright ? 2016 Authors. All rights reserved.
 *
 * FileName: .cpp
 * Author: Wu_Being <1040003585@qq.com>
 * Date Time: 2017-04-20 16:31:1492677087
 * Description: 
 *
 */


int main(int argc, char const *argv[])
{
	int pid=fork();
	if(pid==0){
		printf("[+] I am child. pid:%d, getpid: %d\n", pid, getpid());
	}else if(pid<0){
		fprintf(stderr, "[-] fork error\n");
	}
	else {
		printf("[+] I am parent. pid:%d, getpid: %d\n", pid, getpid());
	}

	printf("[#] public code ...getpid: %d\n", getpid());
	return 0;
}

/*
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.6程序与进程$ gcc 2fork.c 
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.6程序与进程$ ./a.public code 
[+] I am parent. pid:11790, getpid: 11789
[#] public code ...getpid: 11789
[+] I am child. pid:0, getpid: 11790
[#] public code ...getpid: 11790
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.6程序与进程$ ./a.public code 
[+] I am parent. pid:11792, getpid: 11791
[#] public code ...getpid: 11791
[+] I am child. pid:0, getpid: 11792
[#] public code ...getpid: 11792
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.6程序与进程$ ./a.public code 
[+] I am parent. pid:11794, getpid: 11793
[#] public code ...getpid: 11793
[+] I am child. pid:0, getpid: 11794
[#] public code ...getpid: 11794
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.6程序与进程$ 

*/