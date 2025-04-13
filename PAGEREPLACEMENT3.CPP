#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 3
#define MAX_PAGES 20

int main() {
    int pages[MAX_PAGES], frames[MAX_FRAMES];
    int n, pageFaults = 0;
    int index = 0; // To track FIFO replacement

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page references: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // Initialize frames to -1 (empty)
    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }

    printf("\nPage Replacement Process:\n");
    for (int i = 0; i < n; i++) {
        bool found = false;

        // Check if page already in frame
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == pages[i]) {
                found = true;
                break;
            }
        }

        if (!found) {
            // Replace page using FIFO
            frames[index] = pages[i];
            index = (index + 1) % MAX_FRAMES;
            pageFaults++;

            // Print current frame status
            printf("Page %d -> ", pages[i]);
            for (int k = 0; k < MAX_FRAMES; k++) {
                if (frames[k] == -1)
                    printf("[ ] ");
                else
                    printf("[%d] ", frames[k]);
            }
            printf("  (Page Fault)\n");
        } else {
            printf("Page %d -> Hit\n", pages[i]);
        }
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
    return 0;
}
