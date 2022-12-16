#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int x = fork();
    
    // Parent process
    if(x>0)
    {
        printf("Parent Process is Running.\n");
        printf("Main PID : %d \n", getpid());
        sleep(5);
        printf("Parent's PID : %d after sleep\n", getpid());
    }
    else if(x=0) {
        // parent process
        sleep(10);
        printf("\nChild Process is Running.\n");
        printf("PID : %d\n", getpid());
        printf("Child Prinmting Parent PID : %d \n",getppid());
    }
    return 0;
}