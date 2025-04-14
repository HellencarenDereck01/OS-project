#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <list>
using namespace std;

int main() {
    int capacity, n;

    cout << "Enter number of memory frames: ";
    cin >> capacity;

    cout << "Enter number of page references: ";
    cin >> n;

    int pages[n];
    cout << "Enter the page reference string:\n";
    for (int i = 0; i < n; ++i) {
        cin >> pages[i];
    }

    unordered_set<int> memory;
    unordered_map<int, list<int>::iterator> positions;
    list<int> lruList;

    int pageFaults = 0;
    int pageHits = 0;

    for (int i = 0; i < n; ++i) {
        int page = pages[i];
        cout << "Accessed Page: " << page;

        if (memory.find(page) == memory.end()) {
            // Page fault
            pageFaults++;
            cout << " (Page Fault!)";

            if (memory.size() == capacity) {
                int lruPage = lruList.back();
                lruList.pop_back();
                memory.erase(lruPage);
                positions.erase(lruPage);
                cout << " - Removed LRU Page: " << lruPage;
            }

            memory.insert(page);
        } else {
            // Page hit, remove old usage
            pageHits++; //  Count page hit
            cout << " (Page Hit!)"; 
            lruList.erase(positions[page]);
        }

        // Move to front (most recently used)
        lruList.push_front(page);
        positions[page] = lruList.begin();

        // Show current memory
        cout << "\nCurrent Memory: ";
        for (int val : lruList)
            cout << val << " ";
        cout << "\n\n";
    }

    cout << "Total Page Faults (LRU): " << pageFaults << endl;
    cout << "Total Page Hits (LRU): " << pageHits << endl;

    return 0;
}
