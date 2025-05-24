# Prims-Algorithm-for-MST-Optimization

A C++ implementation of Prim's algorithm to solve minimum-cost path problems in weighted graphs.


## Overview
This project solves a real-world problem of optimizing a bakery-shopping itinerary using **Prim's Algorithm** to compute the Minimum Spanning Tree (MST). The goal is to minimize travel time while visiting all specified bakeries on route from ULAB Research Building, Dhanmondi 4/A to Officers Club, Baily Road.

## Why Prim's Algorithm?
- Better asymptotic performance for dense graphs (more edges).
- Uses adjacency matrix for deterministic vertex selection.
- **Time Complexity**: O((V + E) log V) 
- **Space Complexity**: O(V + E)

## Features
- **Adjacency Matrix Implementation**: Manually input graph weights for bakeries.
- **MST Calculation**: Computes the least-cost path covering all vertices (bakeries).
- **Output**:
  - Displays edges and weights of the MST.
  - Total cost of the itinerary.

## Tools
- **Programming Language**: C++  
- **Libraries Used**:
  - `<iostream>`: For input/output operations.
  - `<vector>`: For dynamic adjacency matrix representation.
  - `<queue>`: For priority queue in Prim's algorithm implementation.
- **Compiler**: GNU GCC (C++11 standard)
- **Development Environments**:
  - Visual Studio Code (Local development)

## Graph Structure
The graph includes 7 vertices (bakeries) with the following edges and weights:

![Used Graph ](D:\CSE\3.1\CSE306\Project\Project Graph.png)

## Clone the repository:
   ```bash
   git clone https://github.com/AponGhosh/Prims-Algorithm-for-MST-Optimization.git

