#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

/**
 * Copyright ? 2016 Authors. All rights reserved.
 *
 * FileName: .cpp
 * Author: Wu_Being <1040003585@qq.com>
 * Date Time: 2017-04-22 21:41:1492868491
 * Description: 
 *
 */


pthread_t ntid;

void printids(const char *s){
	pid_t pid;
	pthread_t tid;

	pid = getpid();
	tid = pthread_self();
	printf("[+] %s pid: %lu, ntid: %lu, tid: %lu  (0x%lx) \n", s, 
		(unsigned long)pid, (unsigned long)ntid, (unsigned long)tid, (unsigned long)tid);
}

void * thr_fn(void *arg){
	printids("[+] new thread : ");
	return ((void *)0);
}

int main(int argc, char const *argv[])
{
	int err;

	//printf("[+] ntid: %lu \n", (unsigned long)ntid);
	err = pthread_create(&ntid, NULL, thr_fn, NULL);
	if(err != 0){
		fprintf(stderr, "[-] can't create thread.\n");
	}
	printf("[+] ntid: %lu \n", (unsigned long)ntid);
	printids("[+] main thread: ");
	sleep(1);//

	return 0;
}

/*
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/11第11章 线程/11.4线程创建$ gcc 1pthread_create.c -pthread
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/11第11章 线程/11.4线程创建$ ./a.out 
[+] ntid: 140616560572160 
[+] [+] main thread:  pid: 7314, ntid: 140616560572160, tid: 140616568862464  (0x7fe3d8a2f700) 
[+] [+] new thread :  pid: 7314, ntid: 140616560572160, tid: 140616560572160  (0x7fe3d8247700) 
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/11第11章 线程/11.4线程创建$ ./a.out 
[+] ntid: 139832949753600 
[+] [+] main thread:  pid: 7316, ntid: 139832949753600, tid: 139832958043904  (0x7f2d65cac700) 
[+] [+] new thread :  pid: 7316, ntid: 139832949753600, tid: 139832949753600  (0x7f2d654c4700) 
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/11第11章 线程/11.4线程创建$ ./a.out 
[+] ntid: 140408089609984 
[+] [+] main thread:  pid: 7318, ntid: 140408089609984, tid: 140408097900288  (0x7fb34ecc8700) 
[+] [+] new thread :  pid: 7318, ntid: 140408089609984, tid: 140408089609984  (0x7fb34e4e0700) 
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/11第11章 线程/11.4线程创建$ ./a.out 
[+] ntid: 139676332619520 
[+] [+] main thread:  pid: 7320, ntid: 139676332619520, tid: 139676340909824  (0x7f08eeaef700) 
[+] [+] new thread :  pid: 7320, ntid: 139676332619520, tid: 139676332619520  (0x7f08ee307700) 
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/11第11章 线程/11.4线程创建$


// sleep(1);//

wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/11第11章 线程/11.4线程创建$ gcc 1pthread_create.c -pthread
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/11第11章 线程/11.4线程创建$ ./a.out 
[+] ntid: 140182333441792 
[+] [+] main thread:  pid: 7366, ntid: 140182333441792, tid: 140182341732096  (0x7f7ebeaec700) 
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/11第11章 线程/11.4线程创建$ ./a.out 
[+] ntid: 140506623244032 
[+] [+] main thread:  pid: 7368, ntid: 140506623244032, tid: 140506631534336  (0x7fca3fdc7700) 
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/11第11章 线程/11.4线程创建$ 

*/