#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int isPrime(int a)
{
	for(int i=2;i<a/2;i++)
	{
		if(a%i==0)
			return 0;
	}
	return 1;
}
void* primegen(void *param)
{
	int *arr=(int*)param;
	int a=arr[0];
	int b=arr[1];
	int cnt=0;
	int ptr=3;
	arr[2]=cnt;
	for(int i=a+1;i<b;i++)
	{
		if(isPrime(i)==1)
		{
			arr[ptr]=i;
			ptr++;
			cnt++;
		}
	}
	arr[2]=cnt;
	return NULL;
}
int main()
{
	int a,b;
	printf("Enter the range bw which you want to find the primes\n");
	scanf("%d%d",&a,&b);

	int *arr;
	arr=(int*)malloc((100)*sizeof(int));
	arr[0]=a;
	arr[1]=b;
	arr[2]=0;

	pthread_t thread;
	pthread_create(&thread, 0, &primegen, (void*)arr);
	pthread_join(thread,0);

	printf("List of prime numbers between %d --- %d are :\n",a,b);
	for(int i=3;i<3+arr[2];i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}