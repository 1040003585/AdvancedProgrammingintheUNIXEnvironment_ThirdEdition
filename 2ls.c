#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

char postfixname[10];

void delete_file(char *dir, char *file){
	int len=strlen(file);
	int i=0, l=len-4;
	char postfix[10];
	while(postfix[i++]=file[l++]);
	if(strcmp(postfix, postfixname) == 0){
		char cmd[255]="rm ";
		strcat(cmd, dir);
		strcat(cmd, file);
		printf("> %s\n", cmd);
		// system(cmd); //!!!
	}
}

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
		delete_file(dir, dirp->d_name);//delete_file()
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
	if(argc != 3){
		fprintf(stderr, "[-] Usage: ./a.out directory_name/ postfixname\n");
	}
	strcpy(postfixname, argv[2]);
	system("ls");
	printf("################\n");
	print(argv[1], 0);
	printf("################\n");
	return 0;
}