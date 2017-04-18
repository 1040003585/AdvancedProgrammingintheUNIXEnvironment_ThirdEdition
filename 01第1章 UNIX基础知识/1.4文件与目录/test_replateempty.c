#include <stdio.h>
#include <string.h>

char good[255];
void f(char * dir){
	int i=0;
	puts(dir);
	while(*dir){
		if(*dir==' '){
			//putchar(*dir);
			good[i++]='\\';
		}
		good[i++]=*dir++;
	}
	good[i]='\0';
	puts("------");
	puts(good);
	printf("%ld\n", sizeof(good));
	printf("%ld\n", strlen(good));
}

int main(int argc, char const *argv[])
{
	char dir[]="class1 name";
	f(dir);
	return 0;
}