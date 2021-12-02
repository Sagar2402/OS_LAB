#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/msg.h>
#include <limits.h>
#include <fcntl.h>
#include <string.h>
#define FIFO_NAME "myfifo"

int main()
{
	int status;
	
	int n;
	scanf("%d",&n);
	int sum=0;

	int pipe_fd;
	int res;
	int open_mode=O_WRONLY;
    
    if(access(FIFO_NAME, F_OK)==-1)
    {
    	res=mkfifo(FIFO_NAME, 0777);
    	if(res!=0)
    	{
    		fprintf(stderr, "Could not create file%s\n", FIFO_NAME);
    		exit(EXIT_FAILURE);
    	}
    }
    
    
    pid_t pid;
	pid=fork();
	if(pid==-1)
	{
		printf("Error while creating the child process\n");
	}
	else if(pid==0)
	{
		printf("This is the parent process\n");
		open_mode=O_RDONLY;
		pipe_fd=open(FIFO_NAME,open_mode);
		int sum2;
		int res2 = read(pipe_fd,&sum2,sizeof(int));
        printf("%d\n",sum2);
	}
	else
	{
		//wait(&status);
        printf("I'm the child process\n");
        //printf("Child returned status : %d\n",status);
        pipe_fd=open(FIFO_NAME,open_mode);
        for(int i=1;i<=n;i++)
			sum+=i;

		int res1 = write(pipe_fd,&sum,sizeof(int));
	}
	return 0;
}