// https://www.youtube.com/watch?v=4ugsMYyjuNE
// https://www.youtube.com/watch?v=I7aVemydDTU   এই ভিডিও তে Backtrack বলতে কী বুঝায় তা বরা হয়েছে.

// এই অ্যালগরিদমটি DFS ব্যবহার করে  Undirected গ্রাফটি Traverse করে কিন্তু এটি এই গ্রাফের জন্য Sortest Path খুঁজে বের করতে পারে না.

#include <iostream>
#include <vector>

using namespace std;
bool visited[1000]; // boolean data type always default value is false

void dfs(int node, vector<vector<int>> &adjList)
{
    // Mark the current node as visited
    visited[node] = true;

    // Print the current node (optional)
    cout << node << " ";

    // Visit all the adjacent nodes
    for (int neighbor : adjList[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, adjList);
        }
    }
}

int main()
{
    // Number of vertices in the graph
    int n = 6;

     // Adjacency list to represent the graph (pre-initialized)
    vector<vector<int>> adjList = {{1, 2}, {0, 3, 4}, {0, 5}, {1}, {1}, {2}};//2D vector
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

    // Perform DFS starting from node 0
    cout << "DFS traversal starting from node 0 : ";
    dfs(0, adjList);// '0' means node 1
    cout << endl;

    return 0;
}
/*

     A
    / \
   B   C
  / \   \
 D   E   F

Initial Values:
visited[] is initialized with all false.
We start DFS traversal from node 0 (A).
Step-by-Step Execution:
First call: dfs(0, adjList)

node = 0 (A).
Mark node 0 (A) as visited: visited[0] = true.
Print node 0: Output: 0.
Explore neighbors of 0: neighbors are 1 (B) and 2 (C).
Next recursive call: Go to neighbor 1 (B).
Second call: dfs(1, adjList)

node = 1 (B).
Mark node 1 (B) as visited: visited[1] = true.
Print node 1: Output: 0 1.
Explore neighbors of 1: neighbors are 0 (A), 3 (D), and 4 (E).
0 is already visited, so we skip it.
Next recursive call: Go to neighbor 3 (D).
Third call: dfs(3, adjList)

node = 3 (D).
Mark node 3 (D) as visited: visited[3] = true.
Print node 3: Output: 0 1 3.
Explore neighbors of 3: only neighbor is 1 (B), which is already visited.
Backtrack to node 1 (B) to continue exploring remaining neighbors.
Back to node 1: Continue exploring neighbor 4 (E).

Next recursive call: Go to neighbor 4 (E).
Fourth call: dfs(4, adjList)

node = 4 (E).
Mark node 4 (E) as visited: visited[4] = true.
Print node 4: Output: 0 1 3 4.
Explore neighbors of 4: only neighbor is 1 (B), which is already visited.
Backtrack to node 1 (B).
Back to node 1: All neighbors of 1 are now visited, so backtrack to node 0 (A) and explore the next neighbor 2 (C).

Fifth call: dfs(2, adjList)

node = 2 (C).
Mark node 2 (C) as visited: visited[2] = true.
Print node 2: Output: 0 1 3 4 2.
Explore neighbors of 2: neighbors are 0 (A) and 5 (F).
0 is already visited, so we skip it.
Next recursive call: Go to neighbor 5 (F).
Sixth call: dfs(5, adjList)

node = 5 (F).
Mark node 5 (F) as visited: visited[5] = true.
Print node 5: Output: 0 1 3 4 2 5.
Explore neighbors of 5: only neighbor is 2 (C), which is already visited.
Backtrack to node 2 (C).
Back to node 2: All neighbors of 2 are now visited, so backtrack to node 0 (A).

All neighbors of 0 are now visited, so DFS traversal is complete.


*/

/*
 Two-Dimensional (2D) Vector:
A 2D vector is a vector of vectors. It represents a grid or matrix where you can think of it as having rows and columns, similar to a table. Each element in a 2D vector requires two indices to access: one for the row and one for the column.

Example:

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> vect = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} }; // 2D vector

    // Accessing elements in a 2D vector
    for (int i = 0; i < vect.size(); i++) {
        for (int j = 0; j < vect[i].size(); j++) {
            cout << vect[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
Output:
1 2 3
4 5 6
7 8 9


*/
