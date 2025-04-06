#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

const int MEMORY_SIZE = 3;
list<int> memory;
unordered_map<int, list<int>::iterator> pageMap;
int pageFaults = 0;

void displayMemory() {
    cout << "Current Memory: ";
    for (auto page : memory) {
        cout << page << " ";
    }
    cout << "\n";
}

void accessPage(int page) {
    cout << "\nAccessed Page: " << page;

    // Page is already in memory (Hit)
    if (pageMap.find(page) != pageMap.end()) {
        memory.erase(pageMap[page]);
        memory.push_front(page);
        pageMap[page] = memory.begin();
        cout << " (Hit!)";
    } else {
        // Page Fault
        pageFaults++;
        cout << " (Page Fault!)";

        if (memory.size() == MEMORY_SIZE) {
            int lruPage = memory.back();
            memory.pop_back();
            pageMap.erase(lruPage);
            cout << " - Removed LRU Page: " << lruPage;
        }

        memory.push_front(page);
        pageMap[page] = memory.begin();
    }

    cout << endl;
    displayMemory();
}

void deallocatePage(int page) {
    if (pageMap.find(page) != pageMap.end()) {
        memory.erase(pageMap[page]);
        pageMap.erase(page);
        cout << "\nDeallocated Page: " << page << endl;
    } else {
        cout << "\nPage " << page << " not found in memory." << endl;
    }
    displayMemory();
}

int main() {
    int n, page;
    cout << "Enter number of page accesses: ";
    cin >> n;

    cout << "Enter " << n << " page numbers:\n";
    for (int i = 0; i < n; i++) {
        cin >> page;
        accessPage(page);
    }

    char choice;
    do {
        cout << "\nDo you want to deallocate a page? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            int deallocPage;
            cout << "Enter page number to deallocate: ";
            cin >> deallocPage;
            deallocatePage(deallocPage);
        }
    } while (choice == 'y' || choice == 'Y');

    cout << "\nTotal Page Faults (LRU): " << pageFaults << endl;
    return 0;
}
