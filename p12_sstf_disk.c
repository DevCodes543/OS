#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int abs_diff(int a, int b) {
    return abs(a - b);
}

int find_closest(int blocks[], int n, int head, int visited[]) {
    int min_dist = INT_MAX;
    int index = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int distance = abs_diff(head, blocks[i]);
            if (distance < min_dist) {
                min_dist = distance;
                index = i;
            }
        }
    }

    return index;
}

int main() {
    int n, head, blocks[50], visited[50] = {0};
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

    int current = head;
    for (int i = 0; i < n; i++) {
        int next_index = find_closest(blocks, n, current, visited);
        visited[next_index] = 1;

        printf("%d ", blocks[next_index]);
        total_movement += abs_diff(current, blocks[next_index]);
        current = blocks[next_index];
    }

    printf("\nTotal head movement: %d\n", total_movement);

    return 0;
}
