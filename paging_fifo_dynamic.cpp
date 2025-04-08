#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

int main() {
    int frames, numPages;
    cout << "Enter number of memory frames: ";
    cin >> frames;

    cout << "Enter number of page references: ";
    cin >> numPages;

    int pageRefs[numPages];
    cout << "Enter the page reference string:\n";
    for (int i = 0; i < numPages; ++i) {
        cin >> pageRefs[i];
    }

    unordered_set<int> memory;
    queue<int> fifoQueue;
    int pageFaults = 0;

    for (int i = 0; i < numPages; ++i) {
        int page = pageRefs[i];
        cout << "Accessed Page: " << page;

        // If page not in memory
        if (memory.find(page) == memory.end()) {
            pageFaults++;
            cout << " (Page Fault!)";

            if (memory.size() == frames) {
                // Remove oldest page
                int removed = fifoQueue.front();
                fifoQueue.pop();
                memory.erase(removed);
                cout << " - Removed Page: " << removed;
            }

            // Add new page
            memory.insert(page);
            fifoQueue.push(page);
        }

        // Show current memory
        cout << "\nCurrent Memory: ";
        queue<int> temp = fifoQueue;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << "\n" << endl;
    }

    cout << "Total Page Faults (FIFO): " << pageFaults << endl;
    return 0;
}
