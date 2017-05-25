#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int pid=fork();
	if(pid==0){
		for (int i = 0; i < 2; i++)
		{
			printf("000\n");
		}
		printf("==0\n");
	}else if(pid<0){
		printf("<0\n");
	}else{
		for (int i = 0; i < 2; ++i)
		{
			printf("111\n");
		}
		printf(">0\n");
	}
	printf("out\n");
	return 0;
}