

# OPERATING SYSTEMS MEMORY MANAGEMENT TOOL  
---

This repository contains a comprehensive collection of C++ and Python programs that simulate key memory management techniques used in operating systems. The implementations cover paging, segmentation, FIFO and LRU page replacement strategies, virtual memory handling, and real-time memory usage monitoring.  

The project aims to build a tool to simulate and visualize memory management concepts such as paging, segmentation, and virtual memory. It supports user-defined inputs for memory allocation, page faults, and replacement algorithms, offering both terminal-based and GUI-based visualization.

---

## TABLE OF CONTENTS  
---

- [OVERVIEW](#overview)  
- [FEATURES](#features)  
- [PAGE REPLACEMENT TECHNIQUES](#page-replacement-techniques)  
  - [FIFO (First-In-First-Out)](#fifo-first-in-first-out)  
  - [LRU (Least Recently Used)](#lru-least-recently-used)  
- [PAGING AND SEGMENTATION](#paging-and-segmentation)  
- [VISUALIZATION AND MONITORING TOOLS](#visualization-and-monitoring-tools)  
- [INSTALLATION AND USAGE](#installation-and-usage)  
- [AUTHOR](#author)  

---

## OVERVIEW  
---

The repository includes the following key components:

1. Page Replacement Algorithms (FIFO and LRU)  
2. Paging and Segmentation Simulators  
3. Virtual Memory Simulation  
4. Real-Time and Graphical Memory Usage Visualization  
5. Graphical User Interfaces for page replacement algorithms  

---

## FEATURES  
---

- FIFO and LRU page replacement strategy simulations  
- Paging and segmentation logic with address translation  
- Virtual memory overflow handling  
- Real-time memory usage visualization with system-level statistics  
- GUI-based tools for interactive memory replacement visualization  
- Clean, modular, and well-commented source code for easy understanding  

---

## PAGE REPLACEMENT TECHNIQUES  
---

Simulations of key page replacement strategies that demonstrate how an operating system handles memory access and faults.

### FIFO (First-In-First-Out)  
---

**C++ Implementations:**

- `paging_fifo.cpp` – Object-oriented implementation allowing user-defined frame sizes and input.  
- `paging_fifo_dynamic.cpp` – Procedural version with dynamic inputs and frame state display.  
- `PAGEREPLACEMENT3.CPP` – Tracks frame-by-frame output and page faults.  
- `TRACKUPDATES4.CPP` – Basic FIFO using a circular replacement index.  
- `FIFO1.CPP` – Standard FIFO logic with step-wise hit/fault output.  

**Python Implementations:**

- `PAGEFAULTSANDREPLACEMENT.py` – Terminal-based FIFO logic with fault tracking.  
- `GRAPHICALVISUALIZATION.py` – Bar graph visualization of page frame contents.  
- `UI.py` – GUI application for animated page replacement using `tkinter` and `matplotlib`.  

---

### LRU (Least Recently Used)  
---

**C++ Implementations:**

- `paging_lru.cpp` – LRU logic with support for access and deallocation.  
- `paging_lru_dynamic.cpp` – Dynamic LRU simulation with hit/fault tracking.  
- `virtual_memory_lru.cpp` – Simulates virtual memory with LRU replacement.  
- `LRU2.CPP` – Time-based LRU using counters to track page usage.  

These simulations demonstrate how different LRU methods behave under memory constraints and varying workloads.

---

## PAGING AND SEGMENTATION  
---

Simulations for logical memory organization used in OS design.

- `paging_simulation.cpp` – Simulates page allocation, maintains a page table, and translates logical to physical addresses with formatted table display.  
- `segmentation.cpp` – Simulates segmentation using base and limit, with a structured segment table and offset validation.  

---

## VISUALIZATION AND MONITORING TOOLS  
---

Python-based tools for interactive and real-time memory analysis.

- `memory allocation.py` – Monitors real-time system memory usage via `psutil` and renders a live graph using `tkinter`.  
- `UI.py` – GUI-based FIFO visualizer with animated frame-by-frame memory updates.  
- `GRAPHICALVISUALIZATION.py` – Bar chart showing memory frame status after each page access.  
- `PAGEFAULTSANDREPLACEMENT.py` – Step-by-step terminal display of page memory changes.  

---

## INSTALLATION AND USAGE  
---

### Prerequisites

Ensure the following tools are installed on your system:

- A **C++ compiler** (e.g., `g++`)  
- **Python 3.x**  
- Required Python libraries:
  ```bash
  pip install matplotlib psutil
  ```

---

### Running C++ Programs

To compile and run a C++ program:

```bash
g++ filename.cpp -o output
./output
```

**Example:**
```bash
g++ paging_fifo.cpp -o paging_fifo
./paging_fifo
```

---

### Running Python Scripts

To run a Python program:

```bash
python filename.py
```

- GUI-based scripts (e.g., `UI.py`) will launch a window.  
- Console scripts (e.g., `PAGEFAULTSANDREPLACEMENT.py`) will print results in the terminal.

---

### Suggested Workflow

1. Start with `paging_fifo.cpp` or `PAGEFAULTSANDREPLACEMENT.py` to understand basic FIFO logic.  
2. Move to `paging_lru_dynamic.cpp` or `virtual_memory_lru.cpp` for advanced LRU simulations.  
3. Use `UI.py` or `GRAPHICALVISUALIZATION.py` to visualize memory behavior.  
4. Run `memory allocation.py` to monitor your actual system memory live.

---

## AUTHOR  
---

This project was developed by:

- **Erica Joshua Manyama**  
- **Hellencaren Dereck**

As part of the **Operating Systems** course  
**Lovely Professional University**  
Academic Year: 2024–2025
