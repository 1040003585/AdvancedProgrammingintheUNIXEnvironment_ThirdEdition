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
	fprintf(stderr, "[-] error info start...33333\n");

	int c;
	while((c=getchar()) != EOF){
		putchar(c);
	}

	fprintf(stderr, "EACCES: %s\n", strerror(ENOSYS));
	errno = ENOSYS;//38
	perror(argv[0]);

	fprintf(stderr, "[-] error info end ...33333\n");

	return 0;
}

