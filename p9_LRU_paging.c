#include <stdio.h>

int main() {
    int ref_string[50], frames[10], temp[10];
    int n, m, count, hit = 0, fault = 0;

    printf("Enter size of reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &ref_string[i]);
    }

    printf("Enter No of Frames: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        frames[i] = -1;  // Initialize frames with -1 (indicating empty)
    }

    int frame_index = 0;
    for (int i = 0; i < n; i++) {
        int page = ref_string[i];
        int is_fault = 1;  // Flag to check if it's a page fault

        // Check if page is already in frames
        for (int j = 0; j < m; j++) {
            if (frames[j] == page) {
                is_fault = 0;
                hit++;
                // Update the recently used position
                for (int k = j; k > 0; k--) {
                    frames[k] = frames[k - 1];
                }
                frames[0] = page;  // Move the page to the front (most recently used)
                break;
            }
        }

        // If page fault occurs
        if (is_fault) {
            fault++;
            // Shift all frames to the right
            for (int j = m - 1; j > 0; j--) {
                frames[j] = frames[j - 1];
            }
            frames[0] = page;  // Place the new page in the most recently used position
        }

        // Display current frames
        // printf("\n\nPage %d -> ", page);
        // for (int j = 0; j < m; j++) {
        //     if (frames[j] == -1) {
        //         printf("  ");
        //     } else {
        //         printf("%d ", frames[j]);
        //     }
        // }
    }

    printf("No of Page Faults: %d\n", fault);

    return 0;
}
