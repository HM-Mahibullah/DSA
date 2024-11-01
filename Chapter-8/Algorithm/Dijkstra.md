
![image](https://github.com/user-attachments/assets/0ad8dd90-98f2-4fa8-b4aa-85d9a819a5ea)
![image](https://github.com/user-attachments/assets/b3ae9cd6-028a-41b2-9524-b9f9218a5332)
# Shortest Path Problem in a Graph

## Input Graph

We have a directed graph with the following edges and weights:

- **0 → 1** with weight **2**
- **0 → 2** with weight **6**
- **1 → 3** with weight **5**
- **2 → 3** with weight **8**
- **3 → 4** with weight **10**
- **3 → 5** with weight **15**
- **4 → 6** with weight **2**
- **5 → 6** with weight **6**

## Problem Statement

Assuming node **0** is the source node, the goal is to find the shortest path from node **0** to all other nodes in the graph.

## Approach

You can implement Dijkstra's algorithm or any other shortest path algorithm to solve this problem. Below is a brief outline of the steps involved:

1. Initialize distances from the source to all nodes as infinite, except for the source node which is set to 0.
2. Use a priority queue to explore the nearest unvisited node.
3. Update the distances of neighboring nodes.
4. Repeat until all nodes have been visited.

## Conclusion

Once the algorithm is executed, you will have the shortest path from node **0** to all other nodes in the graph.
