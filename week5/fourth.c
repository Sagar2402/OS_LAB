#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/msg.h>
#include <limits.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	FILE* fptr;
	int num=0;
	fptr=fopen("test.bin", "wb+");
	printf("Enter some numbers : \n");

	for(int i=0; i<4; i++)
	{
		scanf("%d", &num);
		fwrite(&num, sizeof(int), 1, fptr);
	}

	printf("Writing done ! \n");
	fclose(fptr);

	fptr=fopen("test.bin", "rb");

	for(int i=0; i<4; i++)
	{
		fread(&num, sizeof(int), 1, fptr);
		printf("%d\n", num);
	}
	return 0;
}