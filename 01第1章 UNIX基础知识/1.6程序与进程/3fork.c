#include <stdio.h>
#include <unistd.h>

/**
 * Copyright ? 2016 Authors. All rights reserved.
 *
 * FileName: .cpp
 * Author: Wu_Being <1040003585@qq.com>
 * Date Time: 2017-04-20 16:35:1492677312
 * Description: 
 *
 */



int main(int argc, char const *argv[])
{
	int pid=fork();
	if(pid==0){
		printf("[+] I am child. pid:%d, getpid: %d, getppid: %d\n", pid, getpid(), getppid());
	}else if(pid<0){
		fprintf(stderr, "[-] fork error\n");
	}
	else {
		printf("[+] I am parent. pid:%d, getpid: %d, getppid: %d\n", pid, getpid(), getppid());
	}

	printf("[#] public code ...getpid: %d, getppid: %d\n", getpid(), getppid());
	return 0;
}

/*
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.6程序与进程$ gcc 3fork.c 
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.6程序与进程$ ./a.public code 
[+] I am parent. pid:11694, getpid: 11693, getppid: 3031
[#] public code ...getpid: 11693, getppid: 3031
[+] I am child. pid:0, getpid: 11694, getppid: 1283
[#] public code ...getpid: 11694, getppid: 1283
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.6程序与进程$ ./a.public code 
[+] I am parent. pid:11700, getpid: 11699, getppid: 3031
[#] public code ...getpid: 11699, getppid: 3031
[+] I am child. pid:0, getpid: 11700, getppid: 11699
[#] public code ...getpid: 11700, getppid: 11699
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.6程序与进程$ ./a.public code 
[+] I am parent. pid:11702, getpid: 11701, getppid: 3031
[#] public code ...getpid: 11701, getppid: 3031
[+] I am child. pid:0, getpid: 11702, getppid: 11701
[#] public code ...getpid: 11702, getppid: 11701
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.6程序与进程$ ./a.public code 
[+] I am parent. pid:11704, getpid: 11703, getppid: 3031
[#] public code ...getpid: 11703, getppid: 3031
[+] I am child. pid:0, getpid: 11704, getppid: 11703
[#] public code ...getpid: 11704, getppid: 1283
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.6程序与进程$ ./a.public code 
[+] I am parent. pid:11713, getpid: 11712, getppid: 3031
[#] public code ...getpid: 11712, getppid: 3031
[+] I am child. pid:0, getpid: 11713, getppid: 11712
[#] public code ...getpid: 11713, getppid: 11712
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.6程序与进程$ 

*/