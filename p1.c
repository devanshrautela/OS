#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

int main(){
fork();
printf("Process id = %d\n",getpid()); 
return 0;
}

