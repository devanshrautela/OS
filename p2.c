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
printf("sum of even= %d \nat Process_id= %d \n",even,getpid());}
else{
int odd=0;
for(int i=0;i<9;i++){
  if(arr[i]%2!=0){
 odd+=arr[i];}}
printf("sum of odd= %d \nat Process_pid= %d \n",odd,getpid());}
return 0;
}
