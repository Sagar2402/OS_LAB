#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
	pid_t pid;
	pid=fork();
	if(pid<0)
	{
		fprintf(stderr, "ERROR !\n");
	}
	else if(pid==0)
	{ 
        printf("child process\n");
        exit(0);
    }
    else
    {  	
    	sleep(2);
        printf("parent process\n");
    }
	return 0;
}