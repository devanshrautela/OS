#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
    int n;
    printf("Enter the Number of Process\n");
    scanf("%d",&n);
    printf("Process ID: %d \n",getpid());

    return 0;
}