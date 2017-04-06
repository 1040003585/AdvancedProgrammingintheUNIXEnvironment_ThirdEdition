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