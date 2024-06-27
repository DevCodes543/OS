#include <stdio.h>
#include <stdbool.h>

int main() {
    int ref_string[50], frames[10];
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

    for (int i = 0; i < n; i++) {
        int page = ref_string[i];
        bool is_fault = true;  // Flag to check if it's a page fault

        // Check if page is already in frames
        for (int j = 0; j < m; j++) {
            if (frames[j] == page) {
                is_fault = false;
                hit++;
                break;
            }
        }

        // If page fault occurs
        if (is_fault) {
            fault++;
            // Find the page in frames that will not be used for the longest period in the future
            int farthest = -1, replace_index = -1;
            for (int j = 0; j < m; j++) {
                int page_in_frame = frames[j];
                int farthest_occurrence = n + 1;  // Initialize with a large value

                for (int k = i + 1; k < n; k++) {
                    if (page_in_frame == ref_string[k]) {
                        farthest_occurrence = k;
                        break;
                    }
                }

                if (farthest_occurrence > farthest) {
                    farthest = farthest_occurrence;
                    replace_index = j;
                }
            }

            frames[replace_index] = page;  // Replace the page in the frame
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
