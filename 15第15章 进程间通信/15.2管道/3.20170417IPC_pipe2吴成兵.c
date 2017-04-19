#include <stdio.h>
#include <unistd.h>
#define MAXLINE 1000

int main(int argc, char const *argv[])
{
	int	n;
	int	fd[2];
	pid_t	pid1, pid2;
	char 	line[MAXLINE];

	if (pipe(fd)){
		fprintf(stderr, "[-] pipe error");
	}

	if((pid1=fork()) < 0){
		fprintf(stderr, "[-] fork error");
	}else if(pid1 >0){

		if ((pid2=fork()) == 0 ){		/* child2 */				
			close(fd[0]);
			write(fd[1], "hello world\n", 12);
			// printf("p1\n");
		}

	}else{						/* child1 */
		close(fd[1]);
		n = read(fd[0], line, MAXLINE);
		write(STDOUT_FILENO, line, n);		
	}

	return 0;
}
