/*  Write a C program to demonstrate Zombie Process.
    
    A process which has finished the execution but still has entry in the process table to report to its parent process is known as a zombie process.
    
    In this, the parent process is put to sleep for a long time while the child process is terminated using exit(0). 
    When a child process is terminated using exit(0) then the parent process still reads the status of the child process.
*/
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