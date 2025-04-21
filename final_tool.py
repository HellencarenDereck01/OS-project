import os

def show_menu():
    print("\n OPERATING SYSTEM MEMORY MANAGEMENT TOOL")
    print("------------------------------------------")
    print("1. FIFO Simulation ")
    print("2. FIFO Visualization ")
    print("3. FIFO Visualization ")
    print("4. LRU Page Replacement ")
    print("5. Paging Simulation ")
    print("6. Segmentation Simulation ")
    print("7. Real-Time Memory Monitor ")
    print("0. Exit")
    print("------------------------------------------")

while True:
    show_menu()
    choice = input("Select an option (0–7): ")

    if choice == '1':
        os.system("python PAGEFAULTSANDREPLACEMENT.py")
    elif choice == '2':
        os.system("python UI.py")
    elif choice == '3':
        os.system("python GRAPHICALVISUALIZATION.py")
    elif choice == '4':
        os.system("lru.exe")  # make sure paging_lru.cpp is compiled to lru.exe
    elif choice == '5':
        os.system("paging_sim.exe")  # compile paging_simulation.cpp to this
    elif choice == '6':
        os.system("segment.exe")  # compile segmentation.cpp to this
    elif choice == '7':
        os.system("python \"memory allocation.py\"")
    elif choice == '0':
        print(" Exiting the tool. Goodbye!")
        break
    else:
        print(" Invalid choice. Please try again.")
