#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Adjacency matrix for a CONNECTED graph
    bool graph[6][6] = {
        //1,2,3,4,5,6
        /*1*/{0,1,0,1,0,0}, // 0 ? 1, 3
       /*2*/{1,0,1,0,1,0}, // 1 ? 0, 2, 4
       /*3*/{0,1,0,0,0,1}, // 2 ? 1, 5
       /*4*/{1,0,0,0,1,0}, // 3 ? 0, 4
       /*5*/{0,1,0,1,0,1}, // 4 ? 1, 3, 5
       /*6*/{0,0,1,0,1,0}  // 5 ? 2, 4
    };

    bool visited[6] = {false};
    queue<int> q;

    cout << "BFS Traversal (Connected Graph): ";

    // Start from node 0 (could start from any node)
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        // Explore all neighbors
        for (int neighbor = 0; neighbor < 6; neighbor++) {
            if (graph[current][neighbor] && !visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    return 0;
}