#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Floyd-Warshall Algorithm to find shortest paths between all pairs
void floydWarshall(vector<vector<int>>& graph) {
    int V = graph.size();

    // Create a distance matrix and initialize it with the graph values
    vector<vector<int>> dist = graph;

    // Applying the Floyd-Warshall Algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest path distance matrix
    cout << "Shortest Path Distance Matrix:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == numeric_limits<int>::max())
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example graph (parking spaces with road distances)
    // INF represents no direct connection between two parking spaces
    vector<vector<int>> graph = {
        {0, 3, numeric_limits<int>::max(), 7},
        {3, 0, 2, numeric_limits<int>::max()},
        {numeric_limits<int>::max(), 2, 0, 4},
        {7, numeric_limits<int>::max(), 4, 0}
    };

    floydWarshall(graph);

    return 0;
}
