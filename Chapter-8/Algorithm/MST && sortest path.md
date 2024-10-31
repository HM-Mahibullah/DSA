# Data Structures and Algorithms (DSA)

## Chapter 8: Algorithms - Shortest Path and Minimum Spanning Tree (MST)

### Shortest Path

**Purpose:**  
Find the shortest (minimum weight) path between two specific vertices, or from one vertex to all others in the case of Single Source Shortest Path algorithms.

**Types:**
- **Single-Source Shortest Path:** Finds the shortest path from a single source to all other vertices (e.g., Dijkstra’s and Bellman-Ford algorithms).
- **Single-Pair Shortest Path:** Finds the shortest path between two specific vertices.
- **All-Pairs Shortest Path:** Finds the shortest paths between every pair of vertices (e.g., Floyd-Warshall algorithm).

**Key Algorithms:**
- **Dijkstra’s Algorithm:** Works well for graphs with non-negative weights.
- **Bellman-Ford Algorithm:** Handles graphs with negative weights and can detect negative weight cycles.
- **Floyd-Warshall Algorithm:** Efficient for finding shortest paths between all pairs of vertices.

**Characteristics:**
- Focuses on the minimum path weight between vertices.
- The path can have varying numbers of edges, depending on the graph’s structure.
- Works on both directed and undirected graphs.

---

### Minimum Spanning Tree (MST)

**Purpose:**  
Connect all vertices in the graph with the minimum possible total edge weight without forming any cycles.

**Key Algorithms:**
- **Kruskal’s Algorithm:** Adds edges in ascending weight order and uses Union-Find to avoid cycles.
- **Prim’s Algorithm:** Grows a tree from a starting vertex, adding the smallest edge that connects a new vertex.

**Characteristics:**
- Connects all vertices with minimal total weight.
- Ensures there are no cycles.
- Used primarily on undirected graphs.

---


