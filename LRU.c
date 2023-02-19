
#include<stdio.h>
void main()
{
    int i,j,k,min,rs[25],m[10],count[10],flag[25],n,f,pf=0,next=0;
    printf("Enter the length of the reference string --");
    scanf("%d",&n);
    printf("Enter the reference string -- ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&rs[i]);
        flag[i]=0;
    }
    printf("Enter the number of frames -- ");
    scanf("%d",&f);
    for(i=0;i<f;i++)
    {
        count[i]=0;
        m[i]=-1;
    }
printf("\nThe Page Replacement process is -- \n");
for(i=0;i<n;i++)
{
    for(j=0;j<f;j++)
    {
        if(m[j]==rs[i])
        {
            flag[i]=1;
            count[j]=next;
            next++;
        }
    }
    if(flag[i]==0)
    {
        if(i<f)
        {
            m[i]=rs[i];
            count[i]=next;
            next++;
        }
        else
        {
            min=0;
            for(j=0;j<f;j++)
            if(count[min] > count[j])
                min=j;
            m[min]=rs[i];
            count[min]=next;
            next++;
        }
        pf++;
    }
    for(j=0;j<f;j++)
    printf("%d\t",m[j]);
    if(flag[i]==0)
    printf("PF no. -- %d",pf);
    printf("\n");
}
printf("\nThe number of page faults using LRU are %d",pf);
}
/*#include<stdio.h>
int findLRU(int time[], int n)
{
int i, minimum = time[0], pos = 0;
for(i = 1; i < n; ++i){
 if(time[i] < minimum){
 minimum = time[i];
 pos = i;
 }
 }
return pos;
}
int main()
{
 int no_of_frames, no_of_pages, counter = 0, flag1, flag2, i, j, pos, 
faults = 0;
printf("Enter total number of pages : ");
scanf("%d", &no_of_pages);
printf("Enter number of frames: ");
scanf("%d", &no_of_frames);
int pages[no_of_pages] , frames[no_of_frames] 
,time[no_of_frames] ;
printf("Enter all the pages : ");
 for(i = 0; i < no_of_pages; ++i){
 scanf("%d", &pages[i]);
 }
 
for(i = 0; i < no_of_frames; ++i){
 frames[i] = -1;
 }
 
 for(i = 0; i < no_of_pages; ++i){
 flag1 = flag2 = 0;
 
 for(j = 0; j < no_of_frames; ++j){
 if(frames[j] == pages[i]){
 counter++;
 time[j] = counter;
 flag1 = flag2 = 1;
 break;
 }
 }
 
 if(flag1 == 0){
 for(j = 0; j < no_of_frames; ++j){
 if(frames[j] == -1){
 counter++;
 faults++;
 frames[j] = pages[i];
 time[j] = counter;
 flag2 = 1;
 break;
 } 
 }
 } 
 //find position of least recently used page from frame 
 if(flag2 == 0){
 pos = findLRU(time, no_of_frames);
 counter++;
 faults++;
 frames[pos] = pages[i];
 time[pos] = counter;
 }
 
 printf("\n %d : " , pages[i]);
 
 for(j = 0; j < no_of_frames; ++j){
 printf("\t%d ", frames[j]);
 }
 }
printf("\n\nTotal Page Faults = %d", faults);
 
 return 0;
}
*/