#include <stdio.h>
#include <string.h>	//strerror()
#include <errno.h>

/**
 * Copyright ? 2016 Authors. All rights reserved.
 *
 * FileName: .cpp
 * Author: Wu_Being <1040003585@qq.com>
 * Date Time: 2017-04-21 00:36:1492706189
 * Description: 
 *
 */


int main(int argc, char const *argv[])
{
	fprintf(stderr, "[-] error info start...111111\n");

	int c;
	while((c=getchar()) != EOF){
		putchar(c);
	}

	fprintf(stderr, "EACCES: %s\n", strerror(EPERM));
	errno = EPERM;//2
	perror(argv[0]);

	fprintf(stderr, "[-] error info end ...111111\n");

	return 0;
}

/*
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ l
1strerror_perror.c  3prog3.c  4prog3.c   output3.txt  prog3*
2all_errno.c        4prog1.c  a.out*     output.txt
3prog1.c            4prog2.c  errno.txt  prog1*
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ gcc 4prog1.c -o 4prog1
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ gcc 4prog2.c -o 4prog2
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ gcc 4prog3.c -o 4prog3
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ ./4prog1 <errno.txt | ./4prog2 | ./4prog3 >4errno_out.txt 
[-] error info start...33333
[-] error info start...22222
[-] error info start...111111
EACCES: Operation not permitted
./4prog1: Operation not permitted
[-] error info end ...111111
EACCES: No locks available
./4prog2: No locks available
[-] error info end ...22222
EACCES: Function not implemented
./4prog3: Function not implemented
[-] error info end ...33333
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ l
1strerror_perror.c  3prog1.c  4errno_out.txt  4prog1.c  4prog2.c  4prog3.c  errno.txt    output.txt  prog3*
2all_errno.c        3prog3.c  4prog1*         4prog2*   4prog3*   a.out*    output3.txt  prog1*
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ ll
总用量 152
drwxrwxr-x 2 wu_being wu_being  4096 4月  21 00:44 ./
drwxrwxr-x 6 wu_being wu_being  4096 4月  20 19:23 ../
-rw-rw-r-- 1 wu_being wu_being   763 4月  21 00:42 1strerror_perror.c
-rw-rw-r-- 1 wu_being wu_being  5347 4月  20 19:47 2all_errno.c
-rw-rw-r-- 1 wu_being wu_being  1095 4月  20 20:21 3prog1.c
-rw-rw-r-- 1 wu_being wu_being  1687 4月  20 20:26 3prog3.c
-rw-rw-r-- 1 wu_being wu_being 13538 4月  21 00:44 4errno_out.txt
-rwxrwxr-x 1 wu_being wu_being  8976 4月  21 00:43 4prog1*
-rw-rw-r-- 1 wu_being wu_being   562 4月  21 00:42 4prog1.c
-rwxrwxr-x 1 wu_being wu_being  8976 4月  21 00:43 4prog2*
-rw-rw-r-- 1 wu_being wu_being   563 4月  21 00:42 4prog2.c
-rwxrwxr-x 1 wu_being wu_being  8976 4月  21 00:43 4prog3*
-rw-rw-r-- 1 wu_being wu_being   563 4月  21 00:42 4prog3.c
-rwxrwxr-x 1 wu_being wu_being  8976 4月  21 00:37 a.out*
-rw-rw-r-- 1 wu_being wu_being 13538 4月  20 19:47 errno.txt
-rw-rw-r-- 1 wu_being wu_being   114 4月  20 20:24 output3.txt
-rw-rw-r-- 1 wu_being wu_being   114 4月  20 20:21 output.txt
-rwxrwxr-x 1 wu_being wu_being  8760 4月  20 20:21 prog1*
-rwxrwxr-x 1 wu_being wu_being  8760 4月  20 20:22 prog3*
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ 

*/