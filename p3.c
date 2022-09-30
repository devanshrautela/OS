#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
int pi=fork();
if(pi==0)
{
     printf("child_pid= %d and parent_pid= %d\n",getpid(),getppid());
}
else
{
     sleep(5);
     printf("child_pid= %d and parent_pid= %d\n",getpid(),getppid());
}
return 0;
}
