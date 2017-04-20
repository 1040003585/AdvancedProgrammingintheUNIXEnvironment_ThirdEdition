#include <stdio.h>
#include <string.h>
#include <errno.h>
// #include <asm/errno.h>


/**
 * Copyright ? 2016 Authors. All rights reserved.
 *
 * FileName: .cpp
 * Author: Wu_Being <1040003585@qq.com>
 * Date Time: 2017-04-20 19:35:1492688154
 * Description: 
 *
 */


int main(int argc, char const *argv[])
{
	fprintf(stderr, "EACCES: %s\n", strerror(EACCES));

	errno=ENOENT;//2
	perror(argv[0]);

	return 0;
}


/*
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ ./a.out 
EACCES: Permission denied
./a.out: No such file or directory
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ 
*/
