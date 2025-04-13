#include <stdio.h>

#define MAX_FRAMES 3
#define MAX_PAGES 20

int findLRU(int time[], int n) {
    int min = time[0], pos = 0;
    for (int i = 1; i < n; i++) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int pages[MAX_PAGES], frames[MAX_FRAMES], time[MAX_FRAMES];
    int n, pageFaults = 0, count = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page references: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    printf("\nLRU Page Replacement Process:\n");
    for (int i = 0; i < n; i++) {
        int found = 0;

        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                time[j] = ++count;
                break;
            }
        }

        if (!found) {
            int pos = -1;

            for (int j = 0; j < MAX_FRAMES; j++) {
                if (frames[j] == -1) {
                    pos = j;
                    break;
                }
            }

            if (pos == -1)
                pos = findLRU(time, MAX_FRAMES);

            frames[pos] = pages[i];
            time[pos] = ++count;
            pageFaults++;

            printf("Page %d -> ", pages[i]);
            for (int j = 0; j < MAX_FRAMES; j++) {
                if (frames[j] == -1)
                    printf("[ ] ");
                else
                    printf("[%d] ", frames[j]);
            }
            printf(" (Page Fault)\n");
        } else {
            printf("Page %d -> Hit\n", pages[i]);
        }
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
    return 0;
}
