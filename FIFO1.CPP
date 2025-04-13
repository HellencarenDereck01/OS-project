#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 3 

int main() {
    int pages[100], frames[MAX_FRAMES];
    int n, i, j;
    int pageFaults = 0;
    int index = 0;  

    printf("Enter number of pages: ");
    scanf("%d", &n);

    
    printf("Enter page references:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    
    for (i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }
    printf("\nPage Replacement Process:\n");
    for (i = 0; i < n; i++) {
        bool found = false;

        
        for (j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == pages[i]) {
                found = true;
                break;
            }
        }

    
        if (!found) {
            frames[index] = pages[i];  
            index = (index + 1) % MAX_FRAMES;  
            pageFaults++;

            
            printf("Page %d -> ", pages[i]);
            for (j = 0; j < MAX_FRAMES; j++) {
                if (frames[j] == -1)
                    printf("[ ] ");
                else
                    printf("[%d] ", frames[j]);
            }
            printf("  (Page Fault)\n");
        } else {
            
            printf("Page %d -> Hit\n", pages[i]);
        }
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);

    return 0;
}
