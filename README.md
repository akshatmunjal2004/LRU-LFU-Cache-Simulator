# LRU & LFU Cache Simulator

## Project Overview

This project implements a **Cache Simulator** in C++ featuring two popular cache eviction policies:

- **LRU (Least Recently Used)**  
- **LFU (Least Frequently Used)**

The simulator models how real-world caching systems manage limited memory by evicting entries based on recency (LRU) or frequency (LFU). It is designed with efficient data structures to provide constant-time cache operations.

---

## Features

- Interactive command-line interface for cache operations
- Implements LRU and LFU caching algorithms from scratch
- Utilizes `unordered_map` and doubly linked lists for optimal performance
- Modular C++ codebase with clear separation between interface (`.h`) and implementation (`.cpp`)
- Automated build system with Makefile for easy compilation on Windows/Linux using MSYS2 or native Linux environments

---

## Data Structures & Algorithms

- **LRU Cache:**  
  Uses a HashMap (`unordered_map`) for O(1) key lookup and a doubly linked list to track usage order.  
- **LFU Cache:**  
  Uses a combination of HashMaps and frequency lists to maintain usage counts efficiently.

---

## Time Complexities

| Operation | LRU Cache | LFU Cache |
|-----------|------------|-----------|
| Lookup (`get`) | O(1) | O(1) |
| Insert/Update (`put`) | O(1) | O(1) amortized |
| Eviction | O(1) | O(1) amortized |

---

## Technologies Used

- C++11
- Standard Template Library (STL): `unordered_map`, `list`
- Makefile build automation
- MSYS2 for Windows environment compatibility
- VS Code for development

---

## Build & Run Instructions

### Prerequisites

- `g++` compiler with C++11 support
- `make` build tool
- MSYS2 environment on Windows (recommended) or Linux/macOS terminal

### Steps

```bash
# Clone the repository
git clone https://github.com/yourusername/Cache-Simulator.git
cd Cache-Simulator

# Build the project
make

# Run the simulator
./simulator.exe      # On Windows (MSYS2)
./simulator          # On Linux/macOS
