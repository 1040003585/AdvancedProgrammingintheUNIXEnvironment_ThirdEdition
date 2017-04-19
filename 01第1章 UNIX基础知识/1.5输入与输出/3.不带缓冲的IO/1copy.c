#include <stdio.h>
#include <unistd.h>

#define BUFFSIZE 4096

/**
 * Copyright ? 2016 Authors. All rights reserved.
 *
 * FileName: .cpp
 * Author: Wu_Being <1040003585@qq.com>
 * Date Time: 2017-04-19 22:12:1492611136
 * Description: 
 *
 */


int main(int argc, char const *argv[])
{
	int n;
	char buf[BUFFSIZE];

	while((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0){
		if(write(STDOUT_FILENO, buf, n) != n){
			fprintf(stderr, "[-] write error\n");
		}
	}

	if(n < 0){
		fprintf(stderr, "[-] read error\n");
	}

	fprintf(stderr, "end...\n");

	return 0;
}

/*
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.5输入与输出$ gcc 1copy.c 

# stdin : is ternimal 
# stdout: is file data
# stderr: is ternimal
# Ctrl + D
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.5输入与输出$ ./a.out > data
fsdf
erweasdfasd

sdf
end...


# stdin : is file file.list 
# stdout: is file data
# stderr: is ternimal
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.5输入与输出$ ./a.out < file.list > data
end...
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.5输入与输出$ 

*/