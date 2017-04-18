#include <stdio.h>
#include <dirent.h>


/**
 * Copyright ? 2016 Authors. All rights reserved.
 *
 * FileName: .cpp
 * Author: Wu_Being <1040003585@qq.com>
 * Date/Time: 2017/04/18
 * Description: 
 */


int main(int argc, char const *argv[])
{
	DIR *dp;
	struct dirent *dirp;

	if(argc != 2){
		fprintf(stderr, "[-] Usage: ls directory_name\n");
	}
	if((dp=opendir(argv[1])) == NULL){
		fprintf(stderr, "[-] Can't open %s\n", argv[1]);
	}
	while((dirp=readdir(dp)) != NULL){
		printf("%s\n", dirp->d_name);
	}

	closedir(dp);
	return 0;
}
