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