#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
	int status;
	pid_t pid;
	pid=fork();
	if(pid==-1)
	{
		printf("Error while creating the child process\n");
	}
	else if(pid==0)
	{
		printf("This is the child process\n");
	}
	else
	{
		wait(&status);
        printf("I'm the parent process\n");
        printf("Child returned status : %d\n",status);
	}
	return 0;
}