#include <iostream>
using namespace std;

struct Segment {
    string name;
    int base;
    int limit;
};

int main() {
    int n;
    cout << "Enter number of segments: ";
    cin >> n;

    Segment segments[n];

    // Input segment info
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for segment " << i + 1 << ":\n";
        cout << "Segment name: ";
        cin >> segments[i].name;
        cout << "Base address: ";
        cin >> segments[i].base;
        cout << "Limit (size): ";
        cin >> segments[i].limit;
    }
      cout << "\nSEGMENT TABLE:\n";
    cout << "----------------------------------------\n";
    cout << "Name\t|\tBase\t|\tLimit\n";
    cout << "----------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << segments[i].name << "\t|\t" << segments[i].base << "\t|\t" << segments[i].limit << "\n";
    }
    cout << "----------------------------------------\n";
    char cont = 'y';
    while (cont == 'y' || cont == 'Y') {
        string name;
        int offset;

        cout << "\nEnter segment name to access: ";
        cin >> name;
        cout << "Enter offset: ";
        cin >> offset;

        bool found = false;
        for (int i = 0; i < n; i++) {
            if (segments[i].name == name) {
                found = true;
                if (offset < segments[i].limit) {
                    int physicalAddress = segments[i].base + offset;
                    cout << " Access Granted. Physical Address: " << physicalAddress << "\n";
                } else {
                    cout << " Segmentation Fault: Offset exceeds limit.\n";
                }
                break;
            }
        }

        if (!found) {
            cout << " Segment not found.\n";
        }

        cout << "\nDo you want to access another segment? (y/n): ";
        cin >> cont;
    }

    return 0;
}
