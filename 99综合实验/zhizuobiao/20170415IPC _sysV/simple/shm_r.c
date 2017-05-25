#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/shm.h>
#include "shm_com.h"

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
		while(shared_stuff->written_by_you == 1){
			sleep(1);
			printf("Waiting for client ...\n");
		}
		printf("Enter some text:");
		char buffer[BUFSIZ];//
		fgets(buffer, BUFSIZ, stdin);

		strncpy(shared_stuff->some_text, buffer, TEXT_SZ);
		shared_stuff->written_by_you=1;

		if(strncmp(buffer,"end",3)==0){
			running=0;
		}
		// printf("...\n");
	}

	if(shmdt(shared_memory)==-1){
		fprintf(stderr, "shared memory delete failed\n");
		exit(EXIT_FAILURE);
	}

	// only the one client have shmctl rm id is ok..
	if(shmctl(shmid,IPC_RMID,0)==-1){
		fprintf(stderr, "shmctl(IPC_RMID) failed\n");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
	return 0;
}