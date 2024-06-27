#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, head, blocks[50];
    int total_movement = 0;

    printf("Enter the number of blocks: ");
    scanf("%d", &n);

    printf("Enter the sequence of blocks: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &blocks[i]);
    }

    printf("Enter the current block of the head: ");
    scanf("%d", &head);

    printf("Sequence of head movement:\n");
    printf("%d ", head);

    total_movement += abs(head - blocks[0]);

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%d ", blocks[i]);
        } else {
            printf("%d ", blocks[i]);
            total_movement += abs(blocks[i] - blocks[i-1]);
        }
    }

    printf("\nTotal head movement: %d\n", total_movement);

    return 0;
}
