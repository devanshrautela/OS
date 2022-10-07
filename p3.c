#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
int pi=fork();
if(pi==0)
{
     printf("Process_id= %d \nParent_pid= %d\n",getpid(),getppid());
}
else
{
     sleep(5);
     printf("Process_id= %d \nParent_pid= %d\n",getpid(),getppid());
}
return 0;
}
