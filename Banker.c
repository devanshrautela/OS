#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100
struct Process{
 int allocation[MAX],max[MAX],need[MAX];
};
int main(){
 int n,r;
 printf("Enter number of Process: ");
 scanf("%d",&n);
 printf("Enter the number of resoures: ");
 scanf("%d",&r);
 int av[r];
 printf("Enter the total instances of resources: ");
 for(int i=0;i<r;i++){
 scanf("%d",&av[i]);
 }
 bool ft[n];
 struct Process p[n];
 for(int i=0;i<n;i++){
 printf("Enter the max need of process: ");
 for(int j=0;j<r;j++){
 scanf("%d",&p[i].max[j]);
 }
 printf("Enter the allocation of process: ");
 for(int j=0;j<r;j++){
 scanf("%d",&p[i].allocation[j]);
 p[i].need[j]=p[i].max[j]-p[i].allocation[j];
 av[j]-=p[i].allocation[j];
 }
 ft[i]=false;
 }
 int np=0;
 bool flag=true;
 int sq[n];
 int sqi=0;
 while(np<n){
 int i=0,j=0;
 for(i=0;i<n;i++){
 if(ft[i]==true){
 continue;
 }
 for(j=0;j<r;j++){
 if(av[j]<p[i].need[j]){
 break;
 }
 }
 if(j==r){
 ft[i]=true;
 break;
 }
 }
 if(i==n){
 flag=false;
 break;
 }
 np++;
 for(int k=0;k<r;k++){
 av[k]+=p[i].allocation[k];
 }
 // printf("%d ",i+1);
 sq[sqi++]=i+1;
 }
 if(flag){
 printf("\nSafe squence!");
 printf("Sequence is: ");
 for(int i=0;i<n;i++){
 printf("%d ",sq[i]);
 }
 }
 else{
 printf("Not a safe sequence!");
 }
}