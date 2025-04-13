import tkinter as tk
from tkinter import messagebox
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg

def fifo_page_replacement(reference_string, num_frames):
    frames = []
    page_faults = 0
    fault_log = []

    for i, page in enumerate(reference_string):
        if page not in frames:
            if len(frames) < num_frames:
                frames.append(page)
            else:
                frames.pop(0)
                frames.append(page)
            page_faults += 1
            fault_log.append((list(frames), True))
        else:
            fault_log.append((list(frames), False))

    return fault_log, page_faults

def visualize():
    try:
        reference_string = list(map(int, entry_ref.get().split()))
        num_frames = int(entry_frames.get())

        if num_frames <= 0:
            raise ValueError("Number of frames must be greater than 0")

        fault_log, total_faults = fifo_page_replacement(reference_string, num_frames)

        # Clear previous canvas if any
        for widget in frame_vis.winfo_children():
            widget.destroy()

        fig, ax = plt.subplots(figsize=(10, 5))
        ax.set_title("FIFO Page Replacement Visualization")
        ax.set_xlabel("Step")
        ax.set_ylabel("Frame Content")

        for step, (frames, is_fault) in enumerate(fault_log):
            y = [f"F{i+1}" for i in range(len(frames))]
            x = [step] * len(frames)
            ax.scatter(x, y, c='red' if is_fault else 'green', s=100)
            for i, f in enumerate(frames):
                ax.text(step, f"F{i+1}", str(f), fontsize=9,
                        ha='center', va='center', color='white',
                        bbox=dict(facecolor='black', boxstyle='circle'))

        ax.set_xticks(range(len(fault_log)))
        ax.set_yticks([f"F{i+1}" for i in range(num_frames)])
        fig.tight_layout()

        canvas = FigureCanvasTkAgg(fig, master=frame_vis)
        canvas.draw()
        canvas.get_tk_widget().pack()

        label_result.config(text=f"Total Page Faults: {total_faults}")

    except Exception as e:
        messagebox.showerror("Input Error", f"Error: {e}")

# GUI Setup
root = tk.Tk()
root.title("Page Replacement Visualizer - FIFO")
root.geometry("1000x600")

tk.Label(root, text="Enter Reference String (space-separated):").pack()
entry_ref = tk.Entry(root, width=50)
entry_ref.pack(pady=5)

tk.Label(root, text="Enter Number of Frames:").pack()
entry_frames = tk.Entry(root, width=10)
entry_frames.pack(pady=5)

tk.Button(root, text="Visualize FIFO", command=visualize).pack(pady=10)

label_result = tk.Label(root, text="", font=("Arial", 12))
label_result.pack()

frame_vis = tk.Frame(root)
frame_vis.pack(fill=tk.BOTH, expand=True)

root.mainloop()
