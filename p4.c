#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
int pi=fork();
if(pi==0)
{
     sleep(5);
     printf("\nProcess_pid= %d \nParent_pid= %d\n",getpid(),getppid());}
else{
     printf("Process_pid= %d \nParent_pid= %d\n",getpid(),getppid());}
return 0;
}
