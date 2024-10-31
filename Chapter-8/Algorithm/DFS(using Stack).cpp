#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool visited[1000]; // boolean array for marking visited nodes

void dfs(int startNode, vector<vector<int>> &adjList) {
    stack<int> s; // Create a stack to manage the nodes
    s.push(startNode); // Start DFS from the startNode
    visited[startNode] = true;

    while (!s.empty()) {
        int node = s.top();
        s.pop();
        cout << node << " "; // Print the current node

        // Visit all unvisited adjacent nodes of the current node
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                s.push(neighbor);
                visited[neighbor] = true; // Mark as visited when added to stack
            }
        }
    }
}

int main() {
    // Number of vertices in the graph
    int n = 6;

    // Adjacency list to represent the graph
    vector<vector<int>> adjList = {{1, 2}, {0, 3, 4}, {0, 5}, {1}, {1}, {2}};

    // Perform DFS starting from node 0
    cout << "DFS traversal starting from node 0: ";
    dfs(0, adjList);
    cout << endl;

    return 0;
}
