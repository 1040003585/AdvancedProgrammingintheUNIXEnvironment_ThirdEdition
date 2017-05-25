#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/shm.h>
#include "shm_com.h"

#define TEXT_SZ 2048

int main(int argc, char const *argv[])
{
	int running=1;
	void *shared_memory=(void *)0;
	struct shared_use_st *shared_stuff;

	srand((unsigned int)getpid());

	key_t my_key=ftok("./1234",1);
	int shmid=shmget(my_key,sizeof(struct shared_use_st),0666|IPC_CREAT);
	if(shmid==-1){
		fprintf(stderr, "shmget failed\n");
		exit(EXIT_FAILURE);
	}

	shared_memory=shmat(shmid,(void *)0,0);
	if(shared_memory==(void*)-1){
		fprintf(stderr, "shmat failed\n");
		exit(EXIT_FAILURE);
	}

	printf("Memory attached at %X \n", (int)shared_memory);

	shared_stuff=(struct shared_use_st *)shared_memory;
	shared_stuff->written_by_you=0;
	while(running){
		if(shared_stuff->written_by_you){
			printf("You wrote: %s", shared_stuff->some_text);
			sleep(rand()%4);
			shared_stuff->written_by_you=0;
			if(strncmp(shared_stuff->some_text,"end",3)==0){
				running=0;
			}
		}
		// printf("...\n");
	}

	if(shmdt(shared_memory)==-1){
		fprintf(stderr, "shared memory delete failed\n");
		exit(EXIT_FAILURE);
	}


	exit(EXIT_SUCCESS);
	return 0;
}