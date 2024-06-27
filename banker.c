#include<stdio.h>
#include<stdbool.h>

int main()
{
    int n , m , i , j , k;
    n = 5; // processes
    m = 3; //  resources
    int alloc[ 5 ][ 3 ] = { { 0 , 1 , 0 }, 
                            { 2 , 0 , 0 } , 
                            { 3 , 0 , 2 } , 
                            { 2 , 1 , 1 } , 
                            { 0 , 0 , 2 } }; 
    int max[ 5 ][ 3 ] = { { 7 , 5 , 3 } ,
                        { 3 , 2 , 2 } , 
                        { 9 , 0 , 2 } , 
                        { 2 , 2 , 2 } ,
                        { 4 , 3 , 3 } }; 
    int avail[3] = { 3 , 3 , 2 }; // Available Resources
    int need[5][3];

    // Calculating the Need matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    bool finish[5] = {false}; // Initially all processes are not finished

    // Safe sequence array to store the safe sequence
    int safeSeq[5], count = 0;

    // Work array to simulate the available resources
    int work[3];
    for (i = 0; i < 3; i++) {
        work[i] = avail[i];
    }

    // Banker's Algorithm for deadlock avoidance and detection
    while (count < n) {
        bool found = false;
        for (i = 0; i < n; i++) {
            if (finish[i] == false) {
                int j;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > work[j])
                        break;
                }
                if (j == m) {
                    // If all resources needed by i are available
                    for (int k = 0; k < m; k++) {
                        work[k] += alloc[i][k];
                    }
                    safeSeq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if (found == false) {
            printf("State is not safe\n");
            return 0; // Deadlock detected
        }
    }

    // If the program reaches this point, a safe sequence is found
    printf("Safe Sequence is: ");
    for (i = 0; i < n - 1; i++) {
        printf("P%d -> ", safeSeq[i]);
    }
    printf("P%d\n", safeSeq[n - 1]);

    return 0;
}
