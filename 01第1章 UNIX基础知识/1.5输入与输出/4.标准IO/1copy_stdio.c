#include <stdio.h>
/**
 * Copyright ? 2016 Authors. All rights reserved.
 *
 * FileName: .cpp
 * Author: Wu_Being <1040003585@qq.com>
 * Date Time: 2017-04-20 00:01:1492617711
 * Description: 
 *
 */


int main(int argc, char const *argv[])
{
	int c;
	while((c=getc(stdin)) !=EOF ){
		if(putc(c,stdout) ==EOF ){
			fprintf(stderr, "[-] output error\n");
		}
	}

	if(ferror(stdin)){
		fprintf(stderr, "[-] input error\n");
	}
	
	return 0;
}

/*
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.5输入与输出/4.标准IO$ ./a.out > out.txt
sfsf sdfs
fs
f
s
dfsd
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.5输入与输出/4.标准IO$ more out.txt 
sfsf sdfs
fs
f
s
dfsd
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.5输入与输出/4.标准IO$ mv out.txt in.txt
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.5输入与输出/4.标准IO$ ./a.out <in.txt >out2.txt
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.5输入与输出/4.标准IO$ l
1copy_stdio.c  a.out*  in.txt  out2.txt
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.5输入与输出/4.标准IO$ more out2.txt 
sfsf sdfs
fs
f
s
dfsd
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.5输入与输出/4.标准IO$ 

*/