/*Start                                                                                                     Step 1-> In function int waitingtime(int proc[], int n, int burst_time[], int wait_time[])
   Set wait_time[0] = 0
   Loop For i = 1 and i < n and i++
      Set wait_time[i] = burst_time[i-1] + wait_time[i-1]
   End For
Step 2-> In function int turnaroundtime( int proc[], int n, int burst_time[], int wait_time[], int tat[])
   Loop For  i = 0 and i < n and i++
      Set tat[i] = burst_time[i] + wait_time[i]
   End For
Step 3-> In function int avgtime( int proc[], int n, int burst_time[])
   Declare and initialize wait_time[n], tat[n], total_wt = 0, total_tat = 0;
   Call waitingtime(proc, n, burst_time, wait_time)
   Call turnaroundtime(proc, n, burst_time, wait_time, tat)
   Loop For  i=0 and i<n and i++
      Set total_wt = total_wt + wait_time[i]
      Set total_tat = total_tat + tat[i]
      Print process number, burstime wait time and turnaround time
   End For
   Print "Average waiting time =i.e. total_wt / n
   Print "Average turn around time = i.e. total_tat / n
Step 4-> In int main()

   Declare the input int proc[] = { 1, 2, 3}
   Declare and initialize n = sizeof proc / sizeof proc[0]
   Declare and initialize burst_time[] = {10, 5, 8}
   Call avgtime(proc, n, burst_time)
Stop*/
/*  Write a C program of First Come First Serve (FCFS).
    First come first serve (FCFS) scheduling algorithm simply schedules the jobs according to their arrival time. The job which comes first in the ready queue will 
    get the CPU first. The lesser the arrival time of the job, the sooner will the job get the CPU. 
    FCFS scheduling may cause the problem of starvation if the burst time of the first process is the longest among all the jobs.
*/
#include<stdio.h>
#include<stdlib.h>

struct Process
{
    int pid;         // Process ID 
    int at;          // Arrival Time 
    int bt;          // Burst Time
    int ct;          // Completion Time 
    int tat;         // Turn Around Time
    int wt;          // Waiting Time
    int rt;          // Respose Time
    int st;          // Start Time
};

int compare(const void *p1, const void *p2)
{
    int a = ((struct Process *)p1)->at;
    int b = ((struct Process *)p2)->at;

    if(a < b)
       return -1;
    else
       return 1;  
}

int main()
{
    int n;                                // Number of Process 
    float swt = 0, stat = 0;              // Sum of Waiting Time and Sum of Turn Around Time
    float cu = 0;                         // CPU Utilization
    float awt = 0, atat = 0;              // Average Waiting Time and Average Turn Around Time
    int sbt = 0;                          // Sum of Burst Time 
    float srt = 0, art = 0;               // Sum of Response Time and Average Response Time
    float thput = 0;                      // Throughput
    
    printf("Ayush Maheshwari\tSection - C\tRoll No. - 15\n\n");
    
    printf("Enter the number of processes : ");
    scanf("%d", &n);
    
    struct Process p[n];
 
    for(int i = 0; i < n; i++)
    {
        printf("For Process %d: ", i+1);
        p[i].pid = i+1;
  
        printf("Enter the value of AT and BT: ");
        scanf("%d %d", &p[i].at, &p[i].bt);
    }
    
    qsort ((void *)p, n, sizeof(struct Process), compare); 
    
    for(int i = 0; i < n; i++)
    {
        // when first time CPU assign to the process
        if(i == 0)
        {
            p[i].st = p[i].at;
            p[i].ct = p[i].at + p[i].bt;
        }
        // when CPU assign after context switch 
        else if(p[i-1].ct <= p[i].at)
        {
            p[i].st = p[i].at;
            p[i].ct = p[i].at + p[i].bt;
        }
        // when CPU assign after any process
        else
        {
            p[i].st = p[i-1].ct;
            p[i].ct = p[i-1].ct + p[i].bt;
        } 
  
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
  
        sbt += p[i].bt;
        swt += p[i].wt;
        stat += p[i].tat; 
        p[i].rt = p[i].wt;
        srt += p[i].rt;
    }
    
    awt = swt / n;
    atat = stat / n;
    art = srt / n;
    float max;
    
    for(int i = 0; i < n; i++)
    {
        max = 0;
        if(p[i].ct > max)
        {
            max = p[i].ct ;
        }
    }
    
    thput = n / max;
    cu = (sbt / max)*100 ;   
 
    printf("\nPID\tAT\tBT\tST\tCT\tTAT\tWT\tRT\n");
    for(int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].st, p[i].ct, p[i].tat, p[i].wt, p[i].rt);
    } 

    printf("\nAverage Response Time : %f\nAverage of Turn Around Time : %f\n", art, atat); 
    printf("Average of Waiting Time : %f\nThroughput : %f\nCPU utilization : %f", awt, thput, cu);
    
    return 0;
}

