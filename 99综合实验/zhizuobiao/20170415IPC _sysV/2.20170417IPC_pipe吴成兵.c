#include <stdio.h>
#include <unistd.h>
#define MAXLINE 1000

int main(int argc, char const *argv[])
{
	int		n;
	int		fd[2];
	pid_t	pid;
	char 	line[MAXLINE];

	int num=3;

	if (pipe(fd)){
		fprintf(stderr, "[-] pipe error");
	}
	if((pid = fork()) < 0){
		fprintf(stderr, "[-] fork error");
	}else if(pid > 0){		/* parent */
		//sleep(2);
		close(fd[0]);
		write(fd[1], "hello world\n", 12);
	}else{					/* child */
		sleep(2);
		while(num--){
			close(fd[1]);
			n = read(fd[0], line, MAXLINE);
			printf("%d\n", n);
			write(STDOUT_FILENO, line, n);	
		}
	}

	return 0;
}