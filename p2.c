#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
int arr[]={1,2,3,4,5,6,7,8,9};
int pi=fork();
if(pi==0){
int even=0;
for(int i=0;i<9;i++){
  if(arr[i]%2==0){
    even+=arr[i]; }}
printf("sum of even= %d at child_pid= %d and parent_pid= %d\n",even,getpid(),getppid());}
else{
int odd=0;
for(int i=0;i<9;i++){
  if(arr[i]%2!=0){
 odd+=arr[i];}}
printf("sum of odd= %d at child_pid= %d and parent_pid= %d\n",odd,getpid(),getppid());}
return 0;
}
