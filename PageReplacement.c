#include<stdio.h>
int check( int mem[], int cap , int key );
void push(int mem[] , int cap , int key , int *ind);
//int index = -1;
void push(int mem[] , int cap , int key , int *index)
{
 *index = * index +1;
 *index = *index%cap;
 mem[*index] = key ;
 printf("\t");
 for( int i = 0; i< cap ; i++)
 {
 printf(" %d ",mem[i] );
 }printf("\n");
}
int check( int mem[], int cap , int key )
{
 int c=0;
 for( int i=0;i<cap;i++)
 {
 if(key == mem[i])
 { c++;
 break;}
 }
 
 if(c==1)
 return 1;
 else 
 return 0;
}
int main()
{
 int n , cap , fault = 0 ;
 printf("Enter the page : ");
 scanf("%d",&n);
 int pages[n];
 printf("enter the pages : ");
 for( int i=0;i<n ;i++)
 scanf("%d",&pages[i]);
 
 printf("enter the capacity : ");
 scanf("%d",&cap);
 int mem[cap];
 fault = 0;
 int index = -1;
 int * ind = & index;
 
 for( int i = 0; i< cap ; i++)
 {
 mem[i] = pages [i];
 printf("page fault for %d at index %d ",pages[i] , i);
 printf("\n");
 fault ++;
 }
 for( int i = 0; i< cap ; i++)
 {
 printf(" %d ",mem[i] );
 }printf("\n");
 for( int i=cap ; i <n ;i++)
 {
 int yn = check(mem , cap , pages[i]);
 if( yn == 0)
 {
 printf(" fault for %d at index %d --> ",pages[i] , i);
 push(mem , cap , pages[i] , ind);
 //printf(" \n");
 fault ++;
 }else
 printf("no change at index %d\n",i);
 
 }
 printf("\n page fault are %d \n ",fault);
 }
