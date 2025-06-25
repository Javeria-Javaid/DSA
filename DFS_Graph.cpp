#include <iostream>
using namespace std;

// Adjacency matrix for a CONNECTED graph
bool graph[6][6] = {
    {0, 1, 1, 0, 0, 0}, // 0 ? 1, 2
    {1, 0, 0, 1, 0, 0}, // 1 ? 0, 3
    {1, 0, 0, 1, 0, 0}, // 2 ? 0, 3
    {0, 1, 1, 0, 1, 0}, // 3 ? 1, 2, 4
    {0, 0, 0, 1, 0, 1}, // 4 ? 3, 5
    {0, 0, 0, 0, 1, 0}  // 5 ? 4
};

bool visited[6] = {false}; // Tracks visited nodes

void dfs(int node) {
    cout << node << " ";  // Print current node
    visited[node] = true; // Mark as visited

    // Visit all connected nodes (depth-first)
    for (int i = 0; i < 6; i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(i); // Recursive call
        }
    }
}

int main() {
    cout << "DFS Traversal (Connected Graph): ";
    dfs(0); // Start DFS from Node 0 (covers entire graph)
    return 0;
}