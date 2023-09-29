# Dijkstra's Shortest Path Algorithm in C

This C program implements Dijkstra's algorithm to find the shortest path from a source vertex to all other vertices in a graph. The program also allows you to set a maximum path length radius, which can be beneficial in various applications such as network routing and location-based services.

## Table of Contents
- [Overview](#overview)
- [Usage](#usage)
- [Data Structures](#data-structures)
- [Input](#input)
- [Output](#output)
- [Performance Metrics](#performance-metrics)
- [Dependencies](#dependencies)
- [Contributing](#contributing)
- [License](#license)

## Overview
This program employs Dijkstra's algorithm, a well-known graph algorithm, to determine the shortest path from a specified source vertex to all other vertices in the graph. It takes into account the weight of edges between vertices and respects a maximum allowed path length (radius).

## Usage
1. **Compilation**: Compile the program using a C compiler (e.g., GCC) with the following command:

   ```bash
   gcc -o dijkstra_shortest_path dijkstra_shortest_path.c
   ```

2. **Execution**: Run the compiled program with the following command:

   ```bash
   ./dijkstra_shortest_path
   ```

   - You will be prompted to input the size of a square grid, the number of vertices, the radius, and the source vertex.
   - The program will then generate a random graph, apply Dijkstra's algorithm, and display the results.

## Data Structures
- The program utilizes several data structures to represent the graph and perform Dijkstra's algorithm:
  - `struct AdjListNode`: Represents a node in the adjacency list.
  - `struct AdjList`: Represents an adjacency list.
  - `struct Graph`: Represents the entire graph.
  - `struct MinHeapNode`: Represents a node in the min-heap used for Dijkstra's algorithm.
  - `struct MinHeap`: Represents the min-heap data structure.

## Input
- **Grid Size (l x l)**: The program prompts you to input the size of the square grid (l x l).
- **Number of Vertices (n)**: Specify the number of vertices in the graph.
- **Radius (rad)**: Enter the maximum allowed path length.
- **Source Vertex**: Provide the starting vertex for path computation.

## Output
- The program displays the following information for each vertex:
  - Vertex number.
  - Distance from the source vertex.
- If a vertex is unreachable within the specified radius, it is marked as "unreachable."

## Performance Metrics
The program measures the execution time for path computation and displays it in milliseconds. This allows you to assess the efficiency of Dijkstra's algorithm and its performance on different input sizes.

## Dependencies
The code has no external dependencies and relies solely on standard C library functions.

## Contributing
Contributions to the project are encouraged. You can contribute by providing enhancements, reporting issues, or suggesting improvements.

## License
This project is open-source and released under the [MIT License](LICENSE). You are free to use and modify the code according to the terms of the license.
