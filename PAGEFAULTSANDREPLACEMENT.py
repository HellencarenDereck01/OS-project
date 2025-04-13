def fifo_page_replacement(pages, capacity):
    memory = []
    page_faults = 0
    replacements = []

    for page in pages:
        if page not in memory:
            page_faults += 1
            if len(memory) < capacity:
                memory.append(page)
            else:
                removed = memory.pop(0)
                memory.append(page)
                replacements.append((removed, page))
        print(f"Memory: {memory}")

    print(f"\nTotal Page Faults: {page_faults}")
    print("Replacements:", replacements)

# Example usage
pages = [1, 2, 3, 1, 4, 5]
capacity = 3
fifo_page_replacement(pages, capacity)
