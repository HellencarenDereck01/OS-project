import matplotlib.pyplot as plt
import numpy as np

MAX_FRAMES = 3

def visualize_memory(frames, colors):
    # Creating a bar plot to visualize memory frames
    plt.clf()  # Clear previous plot
    plt.bar(range(MAX_FRAMES), frames, color=colors)
    plt.ylim(0, 5)  # Adjust the Y-axis limit to fit frame size
    plt.xticks(range(MAX_FRAMES), ['Frame 1', 'Frame 2', 'Frame 3'])
    plt.yticks(np.arange(0, 6, 1))
    plt.xlabel("Memory Frames")
    plt.ylabel("Page ID")
    plt.title("Memory Usage Visualization")
    plt.show()

def fifo_page_replacement(pages):
    frames = [-1] * MAX_FRAMES
    index = 0
    page_faults = 0

    for page in pages:
        if page not in frames:
            frames[index] = page
            index = (index + 1) % MAX_FRAMES
            page_faults += 1
            colors = ['red'] * MAX_FRAMES  # Red = Page Fault
        else:
            colors = ['green'] * MAX_FRAMES  # Green = Page Hit

        visualize_memory(frames, colors)

    return page_faults

# Sample page references
pages = [1, 2, 3, 2, 4, 1, 5]
page_faults = fifo_page_replacement(pages)
print(f"Total Page Faults: {page_faults}")
