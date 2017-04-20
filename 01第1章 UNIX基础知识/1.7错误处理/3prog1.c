#include <stdio.h>

/**
 * Copyright ? 2016 Authors. All rights reserved.
 *
 * FileName: .cpp
 * Author: Wu_Being <1040003585@qq.com>
 * Date Time: 2017-04-20 20:18:1492690727
 * Description: 
 *
 */


int main(int argc, char const *argv[])
{
	fprintf(stderr, "[-] error info start...\n");

	int c;
	while((c=getchar())!=EOF){
		putchar(c);
	}
	fprintf(stderr, "[-] error info end ...\n");

	return 0;
}

/*
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ ./a.out < errno.txt | grep "#include"
[-] error info start...
[-] error info end ...
#include <bits/errno.h>
#include <asm/errno.h>
#include <asm-generic/errno.h>
#include <asm-generic/errno-base.h>
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ ./a.out < errno.txt | grep "#include" >output.txt
[-] error info start...
[-] error info end ...
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ 
*/