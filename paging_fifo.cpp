#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

class PagingFIFO {
    int capacity; // Total number of frames
    queue<int> pageQueue; // To store pages in FIFO order
    unordered_set<int> pagesInMemory; // To check if page is already loaded
    int pageFaults;
    int pageHits = 0;


public:
    PagingFIFO(int cap) : capacity(cap), pageFaults(0) {}

    void accessPage(int pageNumber) {
        // If page is not in memory, it's a fault
        if (pagesInMemory.find(pageNumber) == pagesInMemory.end()) {
            pageFaults++;
            if (pageQueue.size() == capacity) {
                int oldestPage = pageQueue.front();
                pageQueue.pop();
                pagesInMemory.erase(oldestPage);
                cout << "Removed Page: " << oldestPage << endl;
            }

            pageQueue.push(pageNumber);
            pagesInMemory.insert(pageNumber);
            cout << "Loaded Page: " << pageNumber << " (Page Fault!)\n";
        } else {
            pageHits++;
            cout << "Accessed Page: " << pageNumber << " (No Fault)\n";
        }
    }

    void displayMemory() {
        queue<int> tempQueue = pageQueue;
        cout << "Current Memory: ";
        while (!tempQueue.empty()) {
            cout << tempQueue.front() << " ";
            tempQueue.pop();
        }
        cout << endl;
    }

    void displayPageFaults() {
        cout << "Total Page Faults: " << pageFaults << endl;
        cout << "Total Page Hits: " << pageHits << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter number of memory frames: ";
    cin >> capacity;

    PagingFIFO sim(capacity);

    int n;
    cout << "Enter number of pages to access: ";
    cin >> n;

    cout << "Enter page numbers:\n";
    for (int i = 0; i < n; ++i) {
        int page;
        cin >> page;
        sim.accessPage(page);
        sim.displayMemory();
    }

    sim.displayPageFaults();

    return 0;
}
