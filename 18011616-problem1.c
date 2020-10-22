#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
	pid_t pid;
	int status;
	
	if( (pid = fork()) < 0 ) // fork() to create child
		perror("fork error");
		
	
	else if( pid == 0 ) // is this process child?
		printf("Child PID is %d, Parent PID is %d\n", getpid(), getppid());
	
	else // is this process parent?
	{
		if(wait(&status) != pid) // wait until child is dead
			perror("wait error\n");
		
		printf("Parent PID is %d\n", getpid());
	}
	
	exit(0);
	return 0;
}
