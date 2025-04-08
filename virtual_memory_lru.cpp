#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;

class VirtualMemoryLRU {
    int capacity;  // Physical memory size
    list<int> lruList; // Physical memory (ordered by LRU)
    unordered_map<int, list<int>::iterator> memoryMap; // Page to iterator
    vector<int> virtualMemory; // Pages moved to virtual memory
    int pageFaults = 0;

public:
    VirtualMemoryLRU(int size) : capacity(size) {}

    void accessPage(int page) {
        cout << "\nAccessing Page: " << page;

        // Page already in physical memory (hit)
        if (memoryMap.find(page) != memoryMap.end()) {
            lruList.erase(memoryMap[page]);
            lruList.push_front(page);
            memoryMap[page] = lruList.begin();
            cout << " ✅ (Page Hit)";
        } else {
            pageFaults++;
            cout << " ❌ (Page Fault!)";

            // Memory full? Move LRU to virtual memory
            if (lruList.size() == capacity) {
                int lruPage = lruList.back();
                lruList.pop_back();
                memoryMap.erase(lruPage);
                virtualMemory.push_back(lruPage);
                cout << " - Moved Page " << lruPage << " to Virtual Memory";
            }

            // Load new page into physical memory
            lruList.push_front(page);
            memoryMap[page] = lruList.begin();
        }

        showMemoryStatus();
    }

    void showMemoryStatus() {
        cout << "\nPhysical Memory: ";
        for (int page : lruList)
            cout << page << " ";

        cout << "\nVirtual Memory: ";
        for (int vpage : virtualMemory)
            cout << vpage << " ";
        cout << "\n";
    }

    void reportFaults() {
        cout << "\nTotal Page Faults: " << pageFaults << "\n";
    }
};

int main() {
    int capacity, n;
    cout << "Enter size of Physical Memory (number of frames): ";
    cin >> capacity;

    VirtualMemoryLRU vm(capacity);

    cout << "Enter number of pages to access: ";
    cin >> n;

    cout << "Enter page numbers:\n";
    for (int i = 0; i < n; i++) {
        int page;
        cin >> page;
        vm.accessPage(page);
    }

    vm.reportFaults();
    return 0;
}
