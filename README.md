

# OPERATING SYSTEMS MEMORY MANAGEMENT TOOL  
---

This repository contains a comprehensive collection of C++ and Python programs that simulate key memory management techniques used in operating systems. The implementations include paging, segmentation, FIFO and LRU page replacement strategies, virtual memory handling, and real-time memory usage monitoring. The project aims to build a tool to simulate and visualize memory management techniques like paging, segmentation, and virtual memory. It also handles user-defined inputs for memory allocation, page faults, and replacement algorithms.

---

## TABLE OF CONTENTS  
---

- [OVERVIEW](#overview)  
- [FEATURES](#features)  
- [PAGE REPLACEMENT TECHNIQUES](#page-replacement-techniques)  
  - [FIFO (FIRST-IN-FIRST-OUT)](#fifo-first-in-first-out)  
  - [LRU (LEAST-RECENTLY-USED)](#lru-least-recently-used)  
- [PAGING AND SEGMENTATION](#paging-and-segmentation)  
- [VISUALIZATION AND MONITORING TOOLS](#visualization-and-monitoring-tools)  
- [INSTALLATION AND USAGE](#installation-and-usage)  
- [AUTHOR](#author)

---

## OVERVIEW  
---

The repository includes the following components:

1. Page Replacement Algorithms (FIFO and LRU)  
2. Paging and Segmentation Simulators  
3. Virtual Memory Simulation  
4. Real-Time and Graphical Memory Usage Visualization  
5. Graphical User Interface

---

## FEATURES  
---

- FIFO and LRU page replacement simulations  
- Paging and segmentation logic  
- Virtual memory overflow handling  
- Real-time and graphical memory visualizations  
- GUI-based page replacement visualization  
- Modular and well-commented source code  

---

## PAGE REPLACEMENT TECHNIQUES  
---

This section provides implementations of various page replacement strategies to demonstrate how an operating system handles memory when page faults occur.

### FIFO (FIRST-IN-FIRST-OUT)  
---

**C++ Implementations:**

- `paging_fifo.cpp`: Object-oriented implementation allowing user-defined frame sizes and page access input.  
- `paging_fifo_dynamic.cpp`: Procedural version accepting dynamic inputs and printing frame states.  
- `PAGEREPLACEMENT3.CPP`: Provides frame-by-frame output and page fault tracking.  
- `TRACKUPDATES4.CPP`: Minimal implementation of FIFO using a circular replacement index.  
- `FIFO1.CPP`: Standard implementation with step-wise output indicating page hits and faults.  

**Python Implementations:**

- `PAGEFAULTSANDREPLACEMENT.py`: Basic FIFO logic showing total faults and page replacements.  
- `GRAPHICALVISUALIZATION.py`: Visual representation of frame changes using bar plots.  
- `UI.py`: GUI application with page fault visualization using `tkinter` and `matplotlib`.  

---

### LRU (LEAST RECENTLY USED)  
---

**C++ Implementations:**

- `paging_lru.cpp`: Includes page access and deallocation capabilities using LRU logic.  
- `paging_lru_dynamic.cpp`: Supports dynamic memory size and tracks least recently used pages.  
- `virtual_memory_lru.cpp`: Simulates LRU with a virtual memory layer for overflow.  
- `LRU2.CPP`: Time-based LRU implementation using counters to determine which page to evict.  

These implementations offer insight into how page faults are managed and how each replacement strategy behaves under memory constraints.

---

## PAGING AND SEGMENTATION  
---

This section provides simulations of logical memory organization techniques in operating systems.

- `paging_simulation.cpp`: Simulates a paging system by allocating pages, maintaining a page table, and translating logical addresses to physical ones.  
- `segmentation.cpp`: Simulates segmented memory management by assigning base and limit values to named segments and validating offset access.  

---

## VISUALIZATION AND MONITORING TOOLS  
---

The following Python scripts provide visual and interactive tools to better understand memory usage and replacement mechanisms.

- `memory allocation.py`: Monitors real-time system memory usage using `psutil` and renders a live graph in a `tkinter` window.  
- `UI.py`: A GUI tool for visualizing FIFO page replacement with a reference string input and frame-by-frame animation.  
- `GRAPHICALVISUALIZATION.py`: Displays frame contents after each page access using a bar chart to represent memory state.  
- `PAGEFAULTSANDREPLACEMENT.py`: Prints memory contents step-by-step after each page access for terminal-based visualization.  

---

## INSTALLATION AND USAGE  
---

### Prerequisites

Ensure the following are installed on your system:

- A **C++ compiler** (e.g., `g++`)  
- **Python 3**  
- Required Python libraries:
  ```bash
  pip install matplotlib psutil
  ```

### Running C++ Programs

To compile and run any C++ file:

```bash
g++ filename.cpp -o output
./output
```

> Example:
```bash
g++ paging_fifo.cpp -o paging_fifo
./paging_fifo
```

### Running Python Scripts

To execute a Python script:

```bash
python filename.py
```

- GUI scripts (like `UI.py`) will open a new window.  
- Console-based scripts (like `PAGEFAULTSANDREPLACEMENT.py`) display output directly in the terminal.  

### Suggested Workflow

1. Start with `paging_fifo.cpp` or `PAGEFAULTSANDREPLACEMENT.py` to understand basic page replacement.  
2. Experiment with `paging_lru.cpp` and `virtual_memory_lru.cpp` to see LRU in action.  
3. Run `UI.py` for a visual demonstration of FIFO.  
4. Use `memory allocation.py` to observe real-time system memory usage.  

---

## AUTHOR  
---

This project was developed by:

- **Erica Joshua Manyama**  
- **Hellencaren Dereck**

As part of the **Operating Systems** course  
**Lovely Professional University**  
Academic Year: 2024–2025

---

