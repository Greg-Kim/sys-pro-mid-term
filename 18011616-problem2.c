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
	{
		execl("/bin/ls", "ls", (char*)0, (char*)0); // execute execl to "ls"
		perror("execl error");
	}
	else // is this process parent?
	{
		if(wait(&status) != pid) // wait until child is dead
			perror("wait error\n");
		
		printf("execl() function execution\n");
	}
	
	exit(0);
	return 0;
}
