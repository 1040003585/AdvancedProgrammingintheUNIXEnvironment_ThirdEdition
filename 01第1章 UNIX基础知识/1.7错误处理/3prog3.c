#include <stdio.h>

/**
 * Copyright ? 2016 Authors. All rights reserved.
 *
 * FileName: .cpp
 * Author: Wu_Being <1040003585@qq.com>
 * Date Time: 2017-04-20 20:23:1492690982
 * Description: 
 *
 */


int main(int argc, char const *argv[])
{
	fprintf(stderr, "[-] error info start...3333333\n");

	int c;
	while((c=getchar())!=EOF){
		putchar(c);
	}
	fprintf(stderr, "[-] error info end ...3333333\n");

	return 0;
}

/*
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ gcc 3prog1.c -o prog1
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ gcc 3prog3.c -o prog3
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ ./prog1 < errno.txt | grep "#include" | ./prog3 
[-] error info start...
[-] error info end ...
[-] error info start...3333333
#include <bits/errno.h>
#include <asm/errno.h>
#include <asm-generic/errno.h>
#include <asm-generic/errno-base.h>
[-] error info end ...3333333
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ 
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ ./prog1 < errno.txt | grep "#include" | ./prog3 > output3.txt
[-] error info start...
[-] error info end ...
[-] error info start...3333333
[-] error info end ...3333333
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ 

*/