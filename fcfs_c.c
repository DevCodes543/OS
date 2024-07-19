#include<stdio.h>



struct Process {

    int process_id;

    int arrival_time;

    int burst_time;

    int completion_time;

    int turnaround_time;

    int waiting_time;

};



void calculateTimes(struct Process proc[], int n) {

    proc[0].completion_time = proc[0].arrival_time + proc[0].burst_time;

    proc[0].turnaround_time = proc[0].completion_time - proc[0].arrival_time;

    proc[0].waiting_time = 0;



    for (int i = 1; i < n; i++) {

        proc[i].completion_time = proc[i - 1].completion_time + proc[i].burst_time;

        proc[i].turnaround_time = proc[i].completion_time - proc[i].arrival_time;

        proc[i].waiting_time = proc[i].turnaround_time - proc[i].burst_time;

    }

}



void displayResults(struct Process proc[], int n)

{

    float avg_turnaround_time = 0, avg_waiting_time = 0;



    for (int i = 0; i < n; i++) 

    {

        avg_turnaround_time += proc[i].turnaround_time;

        avg_waiting_time += proc[i].waiting_time;

    }



    avg_turnaround_time /= n;

    avg_waiting_time /= n;



    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);

    printf("Average Waiting Time: %.2f\n", avg_waiting_time);

}



int main() {

    int n;

    printf("Enter number of processes: ");

    scanf("%d", &n);



    struct Process proc[n];



    printf("Enter process id, arrival and burst time:\n");

    for (int i = 0; i < n; i++) {

        scanf("%d %d %d", &proc[i].process_id, &proc[i].arrival_time, &proc[i].burst_time);

    }



    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (proc[j].arrival_time > proc[j + 1].arrival_time) {

                struct Process temp = proc[j];

                proc[j] = proc[j + 1];

                proc[j + 1] = temp;

            }

        }

    }



    calculateTimes(proc, n);

    displayResults(proc, n);



    return 0;

}


// 
/*
#include <stdio.h>

void findWaitingTime(int n, int bt[], int at[], int wt[]) {
    int service_time[n];
    service_time[0] = at[0];
    wt[0] = 0;

    for (int i = 1; i < n; i++) {
        service_time[i] = service_time[i - 1] + bt[i - 1];
        wt[i] = service_time[i] - at[i];

        if (wt[i] < 0)
            wt[i] = 0;
    }
}

void findTurnaroundTime(int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void findAverageTime(int n, int processes[], int bt[], int at[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    findWaitingTime(n, bt, at, wt);
    findTurnaroundTime(n, bt, wt, tat);

    printf("Processes  Arrival Time  Burst Time  Waiting Time  Turnaround Time\n");

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("  %d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], at[i], bt[i], wt[i], tat[i]);
    }

    printf("Average waiting time = %.2f\n", (float)total_wt / n);
    printf("Average turnaround time = %.2f\n", (float)total_tat / n);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int processes[n], arrival_time[n], burst_time[n];
    
    printf("Enter process id, arrival and burst time:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &processes[i], &arrival_time[i], &burst_time[i]);
    }

    // Sort processes based on arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arrival_time[j] > arrival_time[j + 1]) {
                // Swap arrival time
                int temp = arrival_time[j];
                arrival_time[j] = arrival_time[j + 1];
                arrival_time[j + 1] = temp;

                // Swap burst time
                temp = burst_time[j];
                burst_time[j] = burst_time[j + 1];
                burst_time[j + 1] = temp;

                // Swap process ID
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    findAverageTime(n, processes, burst_time, arrival_time);

    return 0;
}

*/