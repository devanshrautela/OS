/*#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

int main(){
fork();
printf("Process id = %d\n",getpid()); 
return 0;
}
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
  
    // make two process which run same
    // program after this instruction
    fork();
  
    printf("Hello world!\n");
    return 0;
}
