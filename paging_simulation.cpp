#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class PagingSystem {
    int pageSize;
    int numFrames;
    vector<int> freeFrames;
    unordered_map<int, int> pageTable; // pageNumber -> frameNumber

public:
    PagingSystem(int memorySizeKB, int pageSizeKB) {
        pageSize = pageSizeKB;
        numFrames = memorySizeKB / pageSize;
        for (int i = 0; i < numFrames; ++i)
            freeFrames.push_back(i);
        cout << "System initialized with " << numFrames << " frames.\n";
    }

    void allocatePage(int pageNumber) {
        if (pageTable.find(pageNumber) != pageTable.end()) {
            cout << "Page " << pageNumber << " is already allocated.\n";
            return;
        }

        if (freeFrames.empty()) {
            cout << "No free frames available. Page fault will occur.\n";
            return;
        }

        int frame = freeFrames.front();
        freeFrames.erase(freeFrames.begin());
        pageTable[pageNumber] = frame;
        cout << "Allocated page " << pageNumber << " to frame " << frame << ".\n";
    }

    void translateAddress(int logicalAddressKB) {
        int pageNumber = logicalAddressKB / pageSize;
        int offset = logicalAddressKB % pageSize;

        if (pageTable.find(pageNumber) == pageTable.end()) {
            cout << "Page fault! Page " << pageNumber << " not in memory.\n";
            return;
        }

        int frameNumber = pageTable[pageNumber];
        int physicalAddress = frameNumber * pageSize + offset;
        cout << "Logical Address " << logicalAddressKB << " KB -> Physical Address " << physicalAddress << " KB\n";
    }

    void showPageTable() {
        cout << "\nPAGE TABLE:\n"; //  Updated heading
    cout << "------------------------\n"; //  Formatting
    cout << "Page\t|\tFrame\n";           // Table headers
    cout << "------------------------\n";
    for (auto entry : pageTable) {
        cout << entry.first << "\t|\t" << entry.second << "\n"; //  Table rows
    }
    cout << "------------------------\n";
    }
};

int main() {
    PagingSystem system(16, 4); // 16KB memory, 4KB page size

    system.allocatePage(0);
    system.allocatePage(1);
    system.allocatePage(2);

    system.translateAddress(6);   // Should be Page 1
    system.translateAddress(20);  // Should trigger page fault

    system.showPageTable();

    return 0;
}
