#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define V 6  // Number of vertices (stations)

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Dijkstra's algorithm to find the shortest path in the graph
void dijkstra(int graph[V][V], int src) {
    int dist[V];  // Array to store the shortest distance from source
    bool sptSet[V];  // Boolean array to track the shortest path tree

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;  // Distance from source to itself is 0

    // Find the shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);  // Get the vertex with the minimum distance
        sptSet[u] = true;

        // Update the distance of the adjacent vertices of the selected vertex
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    cout << "Charging Station\tDistance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t\t" << dist[i] << "\n";
    }
}

int main() {
    // Representation of the charging network (graph) with distances (adjacency matrix)
    int graph[V][V] = {
        {0, 10, 0, 0, 0, 20},
        {10, 0, 30, 0, 0, 0},
        {0, 30, 0, 50, 0, 0},
        {0, 0, 50, 0, 60, 0},
        {0, 0, 0, 60, 0, 10},
        {20, 0, 0, 0, 10, 0}
    };

    int sourceStation = 0;  // Start from charging station 0 (can be set dynamically)

    dijkstra(graph, sourceStation);  // Run Dijkstra's Algorithm

    return 0;
}
