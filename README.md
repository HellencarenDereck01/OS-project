OPERATING SYSTEMS MEMORY MANAGEMENT TOOL

This repository contains a comprehensive collection of C++ and Python programs that simulate key memory management techniques used in operating systems. The implementations include paging, segmentation, FIFO and LRU page replacement strategies, virtual memory handling, and real-time memory usage monitoring. The project aims to build a tool to simulate and visualiza memomory manangement techniques like paging,segmentation and virtual memory.Also to hande user-defined inputs for memory allocation,page faults and replacement algorithms.


## Table of Contents

- [Overview](#overview)  
- [Features](#features)  
- [Page Replacement Algorithms](#page-replacement-algorithms)  
  - [FIFO (First-In-First-Out)](#fifo-first-in-first-out)  
  - [LRU (Least-Recently-Used)](#lru-least-recently-used)  
- [Paging and Segmentation](#paging-and-segmentation)  
- [Visualization and Monitoring Tools](#visualization-and-monitoring-tools)  
- [Installation and Usage](#installation-and-usage)  
- [Screenshots](#screenshots)  
- [Author](#author)


OVERVIEW

The repository includes the following components:

1:Page Replacement Algorithms (FIFO and LRU)

2:Paging and Segmentation Simulators

3:Virtual Memory Simulation

4:Real-Time and Graphical Memory Usage Visualization

5:Graphical  User Interface

FEATURES:

FIFO and LRU page replacement simulations

Paging and segmentation logic

Virtual memory overflow handling

Real-time and graphical memory visualizations

GUI-based page replacement visualization

Modular and well-commented source code

PAGE REPLACEMENT TECHNIQUES:

This section provides implementations of various page replacement strategies to demonstrate how an operating system handles memory when page faults occur.

FIFO (First-In-First-Out)

C++ Implementations:

paging_fifo.cpp: Object-oriented implementation allowing user-defined frame sizes and page access input.

paging_fifo_dynamic.cpp: Procedural version accepting dynamic inputs and printing frame states.

PAGEREPLACEMENT3.CPP: Provides frame-by-frame output and page fault tracking.

TRACKUPDATES4.CPP: Minimal implementation of FIFO using a circular replacement index.

FIFO1.CPP: Standard implementation with step-wise output indicating page hits and faults.

Python Implementations:


PAGEFAULTSANDREPLACEMENT.py: Basic FIFO logic showing total faults and page replacements.

GRAPHICALVISUALIZATION.py: Visual representation of frame changes using bar plots.

UI.py: GUI application with page fault visualization using tkinter and matplotlib.

LRU (Least Recently Used):

C++ Implementations:

paging_lru.cpp: Includes page access and deallocation capabilities using LRU logic.

paging_lru_dynamic.cpp: Supports dynamic memory size and tracks least recently used pages.

virtual_memory_lru.cpp: Simulates LRU with a virtual memory layer for overflow.

LRU2.CPP: Time-based LRU implementation using counters to determine which page to evict.

These implementations offer insight into how page faults are managed and how each replacement strategy behaves under memory constraints.

PAGING AND SEGMENTATION:

This section provides simulations of logical memory organization techniques in operating systems.

paging_simulation.cpp: Simulates a paging system by allocating pages, maintaining a page table, and translating logical addresses to physical ones.

segmentation.cpp: Simulates segmented memory management by assigning base and limit values to named segments and validating offset access.

VISUALISATION AND MONITORING TOOLS

The following Python scripts provide visual and interactive tools to better understand memory usage and replacement mechanisms.

memory allocation.py: Monitors real-time system memory usage using psutil and renders a live graph in a tkinter window.

UI.py: A GUI tool for visualizing FIFO page replacement with a reference string input and frame-by-frame animation.

GRAPHICALVISUALIZATION.py: Displays frame contents after each page access using a bar chart to represent memory state.

## Installation and Usage

### Prerequisites

Ensure the following are installed on your system:

- A **C++ compiler** (e.g., `g++`)
- **Python 3**
- Python dependencies:
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

Certainly! Here's the **Screenshots** section, ready to be added to your `README.md`. It includes placeholder examples with captions—you can replace the image URLs after uploading your own screenshots.

---

## Screenshots

### FIFO Page Replacement GUI (`UI.py`)
![FIFO Visualizer](https://user-images.githubusercontent.com/your-id/fifo_gui.png)  
*Graphical interface showing how pages are loaded and replaced using FIFO strategy.*


### Real-Time Memory Monitor (`memory allocation.py`)
![Memory Monitor](https://user-images.githubusercontent.com/your-id/memory_monitor.png)  
*Live system memory usage graph plotted over time.*


### Bar Chart Visualization (`GRAPHICALVISUALIZATION.py`)
![Bar Chart](https://user-images.githubusercontent.com/your-id/bar_chart.png)  
*Bar chart view of memory frames showing which pages are loaded during FIFO replacement.*


