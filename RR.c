#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

struct P {
    int AT, BT, ST[20], WT, FT, TAT, pos;
};

int quant;

int main() {
    int n, i, j;

    // Taking Input
    printf("Enter the no of processes: ");
    scanf("%d", &n);
    struct P p[n];

    printf("Enter Time Quantum: ");
    scanf("%d", &quant);

     // Assign process numbers from 1 to n
    for(i = 0; i < n; i++) {
        p[i].pos = i + 1;
    }

    printf("Enter the arrival times of processes: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &(p[i].AT));
    }

    printf("Enter the CPU burst times of processes: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &(p[i].BT));
    }

    // Declaring variables
    int c = n, s[n][20];
    float time = 0, mini = INT_MAX, b[n], a[n];

    // Initializing burst and arrival time arrays
    int index = -1;
    for(i = 0; i < n; i++) {
        b[i] = p[i].BT;
        a[i] = p[i].AT;
        for(j = 0; j < 20; j++) {
            s[i][j] = -1;
        }
    }

    int tot_wt = 0, tot_tat = 0;
    bool flag = false;

    while(c != 0) {
        mini = INT_MAX;
        flag = false;

        for(i = 0; i < n; i++) {
            float p_time = time + 0.1;
            if(a[i] <= p_time && mini > a[i] && b[i] > 0) {
                index = i;
                mini = a[i];
                flag = true;
            }
        }

        // if no process is ready, increment time
        if(!flag) {
            time++;
            continue;
        }

        // calculating start time
        j = 0;
        while(s[index][j] != -1) {
            j++;
        }

        if(s[index][j] == -1) {
            s[index][j] = time;
            p[index].ST[j] = time;
        }

        if(b[index] <= quant) {
            time += b[index];
            b[index] = 0;
        } else {
            time += quant;
            b[index] -= quant;
        }

        if(b[index] > 0) {
            a[index] = time + 0.1;
        }

        // calculating arrival, burst, final times
        if(b[index] == 0) {
            c--;
            p[index].FT = time;
            p[index].WT = p[index].FT - p[index].AT - p[index].BT;
            tot_wt += p[index].WT;
            p[index].TAT = p[index].BT + p[index].WT;
            tot_tat += p[index].TAT;
        }

    } // end of while loop

    // Calculating average wait time and turnaround time
    double avg_wt, avg_tat;
    avg_wt = tot_wt / (float)n;
    avg_tat = tot_tat / (float)n;

    // Printing average wait time and turnaround time
    printf("Average WT = %lf\n", avg_wt);
    printf("Average TAT = %lf\n", avg_tat);

    return 0;
}
