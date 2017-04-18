#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void my_exit1(void);
static void my_exit2(void);

int main(int argc, char const *argv[])
{
	/* code */
	atexit(my_exit1);
	atexit(my_exit1);
	atexit(my_exit2);
	printf("main is done! \n");
	// return 0;
	// exit (0);
	_exit(0);
}

static void my_exit1(void){
	printf("first exit handle\n");
}

static void my_exit2(void){
	printf("second exit handle\n");
}

/*

wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/07第7章 进程环境/7.3进程终止$ gcc 1atexit.c 
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/07第7章 进程环境/7.3进程终止$ ./a.out 
main is done! 
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/07第7章 进程环境/7.3进程终止$ 
*/