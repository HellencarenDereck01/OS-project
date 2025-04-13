#include <stdio.h>
#include <stdbool.h>

#define MAX 3

int main() {
    int pages[] = {1, 2, 3, 2, 4, 1, 5};
    int n = sizeof(pages)/sizeof(pages[0]);
    int frames[MAX], index = 0, pageFaults = 0;
    bool found;

    for (int i = 0; i < MAX; i++)
        frames[i] = -1;

    for (int i = 0; i < n; i++) {
        found = false;
        for (int j = 0; j < MAX; j++) {
            if (frames[j] == pages[i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            frames[index] = pages[i];
            index = (index + 1) % MAX;
            pageFaults++;
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);
    return 0;
}
