// https://www.youtube.com/watch?v=4ugsMYyjuNE
// https://www.youtube.com/watch?v=I7aVemydDTU   এই ভিডিও তে Backtrack বলতে কী বুঝায় তা বরা হয়েছে.

// এই অ্যালগরিদমটি DFS ব্যবহার করে  Undirected গ্রাফটি Traverse করে .

#include <iostream>
#include <vector>
#include <queue> // Required for using queue

using namespace std;
bool visited[1000]; // boolean data type always default value is false

void bfs(int startNode, vector<vector<int>> &adjList)
{
    queue<int> q; // Queue to store the nodes for BFS traversal

    // Mark the start node as visited and enqueue it
    visited[startNode] = true;
    q.push(startNode);

    // Traverse the graph using BFS
    while (!q.empty())
    {
        int node = q.front(); // Get the front node in the queue
        q.pop();              // Remove the front node from the queue

        // Print the current node (optional)
        cout << node << " ";

        // Visit all the adjacent nodes of the current node
        for (int neighbor : adjList[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true; // Mark as visited
                q.push(neighbor);         // Enqueue the unvisited neighbor
            }
        }
    }
}

int main()
{
    // Number of vertices in the graph
    int n = 6;

    // Adjacency list to represent the graph (pre-initialized)
    vector<vector<int>> adjList = {{1, 2}, {0, 3, 4}, {0, 5}, {1}, {1}, {2}};
    //    https://www.youtube.com/watch?v=sog-o5F-vLg
    /*
           অথবা এই রকম লেখা যায়
        vector<vector<int>> adjList(n); // 2D vector requires two indices to access: one for the row and one for the column.
                                        // 2D vector ব্যাখ্যা নিচে দেওয়া আছে
        // Example graph (undirected)
        adjList[0] = {1, 2};
        adjList[1] = {0, 3, 4};
        adjList[2] = {0, 5};
        adjList[3] = {1};
        adjList[4] = {1};
        adjList[5] = {2};
        */

    cout << "BFS traversal starting from node 0: ";
    bfs(0, adjList); // Start BFS from node 0
    cout << endl;

    return 0;
}
/*

     A
    / \
   B   C
  / \   \
 D   E   F


The vector repersent that
1 2
0 3 4
0 5
1
1
2


 Step-by-Step Execution:
Initial State:

Queue q = {} (empty).
Start BFS traversal from node 0 (A).
Mark node 0 as visited: visited[0] = true.
Enqueue node 0: q = {0}.
Output: BFS traversal starting from node 0: 0.
First Iteration:

Dequeue node 0 (A) from the front of the queue: q = {}.
Explore neighbors of node 0: neighbors are 1 (B) and 2 (C).
Neighbor 1 (B) is unvisited, mark as visited: visited[1] = true, enqueue 1: q = {1}.
Neighbor 2 (C) is unvisited, mark as visited: visited[2] = true, enqueue 2: q = {1, 2}.
Output:{1 2}.

Second Iteration:

Dequeue node 1 (B) from the front of the queue: q = {2}.
Explore neighbors of node 1: neighbors are 0 (A), 3 (D), and 4 (E).
Neighbor 0 (A) is already visited, skip.
Neighbor 3 (D) is unvisited, mark as visited: visited[3] = true, enqueue 3: q = {2, 3}.
Neighbor 4 (E) is unvisited, mark as visited: visited[4] = true, enqueue 4: q = {2, 3, 4}.
Output: {2 3 4}.

Third Iteration:

Dequeue node 2 (C) from the front of the queue: q = {3, 4}.
Explore neighbors of node 2: neighbors are 0 (A) and 5 (F).
Neighbor 0 (A) is already visited, skip.
Neighbor 5 (F) is unvisited, mark as visited: visited[5] = true, enqueue 5: q = {3, 4, 5}.
Output: { 3 4 5}.

Fourth Iteration:

Dequeue node 3 (D) from the front of the queue: q = {4, 5}.
Explore neighbors of node 3: neighbor is 1 (B).
Neighbor 1 (B) is already visited, skip.
Output remains unchanged:  {4 5}.

Fifth Iteration:

Dequeue node 4 (E) from the front of the queue: q = {5}.
Explore neighbors of node 4: neighbor is 1 (B).
Neighbor 1 (B) is already visited, skip.
Output remains unchanged:{5}

Sixth Iteration:

Dequeue node 5 (F) from the front of the queue: q = {} (empty).
Explore neighbors of node 5: neighbor is 2 (C).
Neighbor 2 (C) is already visited, skip.
Output remains unchanged:{}.

Termination:

Queue is now empty, meaning BFS traversal is complete.
Final output: BFS traversal starting from node 0: 0 1 2 3 4 5.
BFS Traversal Order:
0 (A) -> 1 (B) -> 2 (C) -> 3 (D) -> 4 (E) -> 5 (F)


Key Differences Between DFS and BFS:
1. DFS explores as deep as possible before backtracking.

2. BFS explores all nodes level by level (or layer by layer), visiting all nodes at the current level
   before moving to the next.

*/
