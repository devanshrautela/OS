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
#include <stdio.h>
#include <stdlib.h>
struct Process
{
    int pid;
    int atime;
    int btime;
    int ctime;
    int tatime;
    int wtime;
    int rtime;
    int stime;
};
int compare(const void *p1, const void *p2)
{
    int a = ((struct Process *)p1)->atime;
    int b = ((struct Process *)p2)->atime;
    if (a < b)
        return -1;
    else
        return 1;
}
int main()
{
    int n;
    int swtime = 0, statime = 0, awtime = 0, atatime = 0, cyclelength = 0;
    float cpu_ut, thro;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process p[n];
    for (int i = 0; i < n; i++)
    {
        printf("For Process %d ", i + 1);
        p[i].pid = i + 1;
        printf("Enter the value of AT & BT: ");
        scanf("%d %d", &p[i].atime, &p[i].btime);
    }
    qsort((void *)p, n, sizeof(struct Process), compare);
    int idle = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            p[i].ctime = p[i].atime + p[i].btime;
            p[i].stime = p[i].atime;
        }
        else if (p[i - 1].ctime <= p[i].atime)
        {
            p[i].ctime = p[i].atime + p[i].btime;
            idle += p[i].atime - p[i - 1].ctime;
            p[i].stime = p[i].atime;
        }
        else
        {
            p[i].ctime = p[i - 1].ctime + p[i].btime;
            p[i].stime = p[i - 1].ctime;
        }
        p[i].tatime = p[i].ctime - p[i].atime;
        p[i].wtime = p[i].tatime - p[i].btime;
        swtime += p[i].wtime;
        statime += p[i].tatime;
        p[i].rtime = p[i].stime - p[i].atime;
    }
    awtime = swtime / n;
    atatime = statime / n;
    cyclelength = p[n - 1].ctime - p[0].stime;
    cpu_ut = (cyclelength - idle) * 100;
    thro = (float)n / cyclelength;

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].atime, p[i].btime, p[i].ctime, p[i].tatime, p[i].wtime, p[i].rtime);
    }
printf("\nSum of Turn Around Time: %d\nAverage of Turn Around Time: %d\n",statime, atatime);
printf("Sum of Waiting Time: %d\nAverage of Waiting Time:%d\n",swtime,awtime);
printf("CPU Utilization: %6.2f\nThroughput: %f\n",cpu_ut,thro);
return 0;
}