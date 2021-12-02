#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <inttypes.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(int argc, char const *argv[])
{
	if(argc<2)
	{
		printf("Insufficient arguments\n");
		return 0;
	}
	char new_path[100]="second.c";
	struct stat start;
	int ret1=stat(argv[1],&start);
	system("ls");
	printf("Linking ..\n");

	int ret2=symlink(argv[1],new_path);
	struct stat intermediate;
	
	int ret3=stat(argv[1], &intermediate);
	printf("New path : %s\n", new_path);
	system("ls");

	int ret4=unlink(argv[1]);
	struct stat ending;

	int ret5=stat(new_path, &ending);
	printf("Unlinking...\n");
	system("ls");
	return 0;
}