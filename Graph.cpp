#include <iostream>
#define MAX 100

using namespace std;

int adjMatrix[MAX][MAX];
int nodes;

void addEdge(int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1; // Remove this line for directed graph
}

void displayMatrix() {
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << "Enter number of nodes: ";
    cin >> nodes;

    int edges;
    cout << "Enter number of edges: ";
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        int u, v;
        cout << "Enter edge (u v): ";
        cin >> u >> v;
        addEdge(u, v);
    }

    displayMatrix();
    return 0;
}