#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

/**
 * Copyright ? 2016 Authors. All rights reserved.
 *
 * FileName: .cpp
 * Author: Wu_Being <1040003585@qq.com>
 * Date/Time: 2017/04/18
 * Description: non-command the // system(cmd); //!!!
 */


char dirgood[255];

void replace_diremptychar(char *dir){
	int i=0;
	//puts(dir);
	while(*dir){
		if(*dir==' '){
			//putchar(*dir);
			dirgood[i++]='\\';
		}
		dirgood[i++]=*dir++;
	}
	dirgood[i]='\0';
	//puts(dirgood);
}


char postfixname[10];

void delete_file(char *dir, char *file){
	int len=strlen(file);
	int i=0, l=len-strlen(postfixname);
	char postfix[10];
	while(postfix[i++]=file[l++]);//get post char
	if(strcmp(postfix, postfixname) == 0){
		char cmd[255]="rm ";
		replace_diremptychar(dir);//replace_diremptychar()
		strcat(cmd, dirgood);
		strcat(cmd, file);
		printf("> %s\n", cmd);
		//system(cmd); //!!!
	}
}

void print(char *dir,int len){
	len += 2;

	DIR *dp;
	if((dp=opendir(dir)) == NULL){
		fprintf(stderr, "[-] Can't open %s\n", dir);
		fprintf(stderr, "[-] Usage: ./a.out directory_name/ postfixname\n");
	}

	struct dirent *dirp;
	while((dirp=readdir(dp)) != NULL){
		int l=len; while(l--)putchar(' ');
		printf("%s \n", dirp->d_name);
		if(dirp->d_type==8) delete_file(dir, dirp->d_name);//delete_file()// .out/
//		if(dirp->d_type==4 && dirp->d_name[0]!='.'){//dir
		if(dirp->d_type==4 ){//dir
			if( strcmp(dirp->d_name, ".")==0 || strcmp(dirp->d_name, "..")==0 ) continue;
			char dirnew[255];//
			strcpy(dirnew, dir);
			strcat(dirnew, dirp->d_name);
			strcat(dirnew, "/");
			// printf("> %s\n", dirnew);//
			print(dirnew, len);//print()

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
