#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
	pid_t pid;
	pid = fork();
	if(pid<0)
	{
		fprintf(stderr, "Error creating the child process\n");
	}
	else if(pid==0)
	{
		printf("In child process\nPID = %d\n",getpid());
        printf("Parent PID = %d\n",getppid());
        printf("Child PID = %d\n",pid);
	}
	else
	{
		wait(NULL);
        printf("\nIn the parent process\nPID = %d\n",getpid());
        printf("Parent PID = %d\n",getppid());
        printf("Child PID = %d\n",pid);
	}

	return 0;
}