#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

void print(char *dir,int len){
	len += 2;

	DIR *dp;
	if((dp=opendir(dir)) == NULL){
		fprintf(stderr, "[-] Can't open %s\n", dir);
	}

	struct dirent *dirp;
	while((dirp=readdir(dp)) != NULL){
		int l=len; while(l--)putchar(' ');
		printf("%s \n", dirp->d_name);
		if(dirp->d_type==4 && dirp->d_name[0]!='.'){//dir
			strcat(dir,dirp->d_name);
			strcat(dir,"/");
			print(dir, len);//print()
			strcat(dir,"../");
		}
	}
	closedir(dp);
}

int main(int argc, char  *argv[])
{
	if(argc != 2){
		fprintf(stderr, "[-] Usage: ls directory_name/ \n");
	}
	system("ls");
	printf("################\n");
	print(argv[1], 0);
	printf("################\n");
	return 0;
}