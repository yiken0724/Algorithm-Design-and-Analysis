# Algorithm Design & Analysis — Example Class Projects

This repository contains the three example class projects completed for **SC2001 Algorithm Design & Analysis** by **Group 8** (Florian, Min Jie, Yi Rou, Yi Ken). Each project explores a key algorithmic paradigm — divide-and-conquer, greedy algorithms, and dynamic programming — through implementation, empirical analysis, and comparison of performance.

---

## Project 1 — Hybrid Sort: Integration of MergeSort & InsertionSort

**Language:** Java

A hybrid sorting algorithm that combines MergeSort and InsertionSort. The algorithm introduces a threshold `S`: when the size of a subarray in a recursive MergeSort call falls to `S` or below, it switches to InsertionSort, which is more efficient for small inputs.

The project involves:
- Implementing the hybrid sort algorithm
- Generating test arrays of sizes ranging from 1,000 to 80 million
- Recording key comparisons to analyse time complexity
- Plotting key comparisons against input size `n` (with fixed `S`) and against different values of `S` (with fixed `n`)
- Determining the optimal value of `S`
- Comparing performance (key comparisons and CPU time) against standard MergeSort

---

## Project 2 — Dijkstra's Shortest Path Algorithm

**Language:** C++

An empirical study of Dijkstra's algorithm implemented in two ways:
1. **Adjacency matrix** with an array-based priority queue
2. **Adjacency list** with a min-heap priority queue

The project involves:
- Implementing both versions of the algorithm
- Analysing performance by varying the number of vertices `V` and edges `E`
- Comparing CPU time and operation counts across both implementations

---

## Project 3 — Unbounded Knapsack Problem (Dynamic Programming)

**Language:** Java

A dynamic programming solution to the **Unbounded Knapsack Problem**: given a knapsack of capacity `C` and `n` item types (each with a weight and a profit), find the combination of items — with unlimited quantities of each — that maximises total profit without exceeding the capacity.

The project involves:
- Implementing the DP algorithm
- Tracing through example inputs to verify correctness
- Analysing time and space complexity

---

## Repository Structure

```
sc2001-projects/
├── lab1/                  # Hybrid Sort (Java)
│   ├── hybridSort.java
│   ├── mergeSort.java
│   ├── insertionSort.java
│   ├── implementationApp.java
│   └── SC2001 Project 1_ Integration.pdf
│
├── lab2/                  # Dijkstra's Algorithm (C++)
│   ├── dijkstraFinalVer2.c++
│   ├── test.cpp
│   ├── *.xlsx             # Performance analysis data & graphs
│   └── SC2001 Project 2_ The Dijkstra Algo.pdf
│
└── lab3/                  # Unbounded Knapsack (Java)
    ├── Knapsack.java
    ├── Items.java
    ├── implementationClass.java
    └── SC2001 Project 3_ DP.pdf
```

---

## Languages

- Java (Projects 1 & 3)
- C++ (Project 2)
