// #include <stdio.h>
 
// void swap(int *a,int *b)
// {
//     int temp=*a;
//     *a=*b;
//     *b=temp;
// }
// int main()
// {
//     int n;
//     printf("Enter number of processes ");
//     scanf("%d",&n);

//     int burst[n],priority[n],index[n];
//         printf("Enter process id, priority and burst time of each process ");
//     for(int i=0;i<n;i++)
//     {
//         scanf("%d %d %d",&index[i],&priority[i],&burst[i]);
//         // index[i]=i+1;
//     }
//     for(int i=0;i<n;i++)
//     {
//         int temp=priority[i],m=i;
 
//         for(int j=i;j<n;j++)
//         {
//             if(priority[j] < temp)
//             {
//                 temp=priority[j];
//                 m=j;
//             }
//         }
 
//         swap(&priority[i], &priority[m]);
//         swap(&burst[i], &burst[m]);
//         swap(&index[i],&index[m]);
//     }
 
//     int t=0;
 
//     printf("Order of process Execution is\n");
//     for(int i=0;i<n;i++)
//     {
//         printf("P%d is executed from %d to %d\n",index[i],t,t+burst[i]);
//         t+=burst[i];
//     }
//     printf("\n");
//     printf("Process Id\tBurst Time\tWait Time\n");
//     int wait_time=0;
//     int total_wait_time = 0;
//     for(int i=0;i<n;i++)
//     {
//         printf("P%d\t\t%d\t\t%d\n",index[i],burst[i],wait_time);
//         total_wait_time += wait_time;
//         wait_time += burst[i];
//     }
    
//     float avg_wait_time = (float) total_wait_time / n;
//     printf("Average waiting time is %f\n", avg_wait_time);
    
//     int total_Turn_Around = 0;
//     for(int i=0; i < n; i++){
//         total_Turn_Around += burst[i];
//     }
//     float avg_Turn_Around = (float) total_Turn_Around / n;
//     printf("Average TurnAround Time is %f",avg_Turn_Around);
//     return 0;
// }

#include<stdio.h>  
#include<stdlib.h>  
  
struct process {  
    int process_id;  
    int burst_time;  
    int priority;  
    int waiting_time;  
    int turnaround_time;  
};  
  
void find_waiting_time(struct process[], int, int[]);  
void find_turnaround_time(struct process[], int, int[], int[]);  
  
void find_average_time(struct process[], int);  
  
void priority_scheduling(struct process[], int);  
  
int main()  
{  
    int n, i;  
    struct process proc[10];  
  
printf("Enter number of processes ");  
scanf("%d", &n);  
printf("Enter process id, priority and burst time of each process ");  
 
  
for(i = 0; i< n; i++)  
    {  
scanf("%d", &proc[i].process_id);  
  
scanf("%d", &proc[i].priority);  
scanf("%d", &proc[i].burst_time);  
  
    }  
  
priority_scheduling(proc, n);  
    return 0;  
}  
  
void find_waiting_time(struct process proc[], int n, int wt[])  
{  
    int i;  
wt[0] = 0;  
  
for(i = 1; i< n; i++)  
    {  
wt[i] = proc[i - 1].burst_time + wt[i - 1];  
    }  
}  
  
void find_turnaround_time(struct process proc[], int n, int wt[], int tat[])  
{  
    int i;  
for(i = 0; i< n; i++)  
    {  
tat[i] = proc[i].burst_time + wt[i];  
    }  
}  
  
void find_average_time(struct process proc[], int n)  
{  
    int wt[10], tat[10], total_wt = 0, total_tat = 0, i;  
  
find_waiting_time(proc, n, wt);  
find_turnaround_time(proc, n, wt, tat);  
  
// printf("\nProcess ID\tBurst Time\tPriority\tWaiting Time\tTurnaround Time");  
  
for(i = 0; i< n; i++)  
    {  
total_wt = total_wt + wt[i];  
total_tat = total_tat + tat[i];  
// printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", proc[i].process_id, proc[i].burst_time, proc[i].priority, wt[i], tat[i]);  
    }  
  
printf("\nAverage Turnaround Time = %.2f\n", (float)total_tat/n);  
printf("\nAverage WT = %.2f", (float)total_wt/n);  
}  
  
void priority_scheduling(struct process proc[], int n)  
{  
int i, j, pos;  
struct process temp;  
for(i = 0; i< n; i++)  
{  
    pos = i;  
for(j = i + 1; j < n; j++)  
    {  
        if(proc[j].priority< proc[pos].priority)  
            pos = j;  
    }  
  
    temp = proc[i];  
    proc[i] = proc[pos];  
    proc[pos] = temp;  
}  
  
find_average_time(proc, n);  
}  