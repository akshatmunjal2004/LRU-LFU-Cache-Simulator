# LRU and LFU Cache Simulator

## Description

A fully interactive command-line simulator that implements two popular caching algorithms:

- **LRU (Least Recently Used) Cache**
- **LFU (Least Frequently Used) Cache**

Built entirely in C++ using HashMaps and Doubly Linked Lists, simulating how real-world systems manage memory, cache eviction policies, and storage optimization.

## Features

- Add and retrieve keys from cache
- Simulates eviction on cache overflow
- CLI-based user interaction
- Clean modular object-oriented design
- Fully automated build using Makefile

## Technologies Used

- C++
- STL: `unordered_map`, `list`
- Build Automation: Makefile
- MSYS2 for Windows compatibility

## Build Instructions

### Prerequisites

- `g++` compiler (C++11 or higher)
- `make`

### Build and Run

```bash
# Navigate to project directory
cd /path/to/Cache-Simulator

# Build the project
make

# Run the simulator
./simulator.exe
