#include <stdio.h>
#include <limits.h>

typedef struct {
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculateTimes(Process processes[], int n) {
    int time = 0, completed = 0, shortest = 0;
    int min_remaining_time = INT_MAX;
    int finish_time;
    int check = 0;
    float total_wt = 0, total_tat = 0;

    while (completed != n) {
        for (int j = 0; j < n; j++) {
            if ((processes[j].arrival_time <= time) && 
                (processes[j].remaining_time < min_remaining_time) && 
                (processes[j].remaining_time > 0)) {
                min_remaining_time = processes[j].remaining_time;
                shortest = j;
                check = 1;
            }
        }

        if (check == 0) {
            time++;
            continue;
        }

        processes[shortest].remaining_time--;
        min_remaining_time = processes[shortest].remaining_time;
        if (min_remaining_time == 0) {
            min_remaining_time = INT_MAX;
        }

        if (processes[shortest].remaining_time == 0) {
            completed++;
            check = 0;
            finish_time = time + 1;
            processes[shortest].completion_time = finish_time;
            processes[shortest].turnaround_time = finish_time - processes[shortest].arrival_time;
            processes[shortest].waiting_time = processes[shortest].turnaround_time - processes[shortest].burst_time;

            total_wt += processes[shortest].waiting_time;
            total_tat += processes[shortest].turnaround_time;
        }
        time++;
    }

    printf("Average WT = %f\n", total_wt / n);
    printf("Average TAT = %f\n", total_tat / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];

    printf("Enter the arrival times of processes: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &processes[i].arrival_time);
    }

    printf("Enter the CPU burst times of processes: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    calculateTimes(processes, n);

    return 0;
}
