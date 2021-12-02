#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char const *argv[])
{
	pid_t pid;
	pid=fork();
	if(pid<0)
	{
		fprintf(stderr, "Error while creating child process\n");
	}
	else if(pid==0)
	{
		execlp("./first","first",NULL);
	}
	else
	{
		wait(NULL);
        printf("Child complete\n");
        exit(0);
	}
	return 0;
}