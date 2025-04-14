import tkinter as tk
import psutil
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import matplotlib.animation as animation
import datetime


# Global data store for memory values
memory_percent = []
time_ticks = []

# GUI setup
root = tk.Tk()
root.title("Real-Time Memory Allocation Monitor")
root.geometry("800x500")

fig, ax = plt.subplots(figsize=(8, 4))
line, = ax.plot([], [], label="Memory Used (%)", color="blue")
ax.set_ylim(0, 100)
ax.set_xlim(0, 60)
ax.set_title("Memory Usage Over Time")
ax.set_xlabel("Time (seconds)")
ax.set_ylabel("Usage (%)")
ax.legend(loc="upper right")

canvas = FigureCanvasTkAgg(fig, master=root)
canvas.draw()
canvas.get_tk_widget().pack()

# Function to update the plot every second
def update(frame):
    mem = psutil.virtual_memory()
    print(f"[{datetime.datetime.now().strftime('%H:%M:%S')}] Memory Usage: {mem.percent}%")

    memory_percent.append(mem.percent)
    time_ticks.append(frame)

    if len(memory_percent) > 60:
        memory_percent.pop(0)
        time_ticks.pop(0)

    line.set_data(time_ticks, memory_percent)
    ax.set_xlim(max(0, frame - 60), frame + 1)
    return line,

ani = animation.FuncAnimation(fig, update, interval=1000)

root.mainloop()
