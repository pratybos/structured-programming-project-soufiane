#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>
#include <algorithm>

using namespace std;

// Define an adjacency list for the graph
class Graph {
public:
    unordered_map<int, vector<pair<int, int>>> adj; // node -> [(neighbor, weight)]

    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight}); // Undirected graph
    }

    void updateEdgeWeight(int u, int v, int newWeight) {
        for (auto &neighbor : adj[u]) {
            if (neighbor.first == v) {
                neighbor.second = newWeight;
                break;
            }
        }
        for (auto &neighbor : adj[v]) {
            if (neighbor.first == u) {
                neighbor.second = newWeight;
                break;
            }
        }
    }

    vector<int> dijkstra(int src, int dest) {
        unordered_map<int, int> dist;
        unordered_map<int, int> parent;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        for (auto &node : adj) {
            dist[node.first] = numeric_limits<int>::max();
        }

        pq.push({0, src});
        dist[src] = 0;
        parent[src] = -1;

        while (!pq.empty()) {
            int currDist = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            if (currNode == dest) break;

            for (auto &neighbor : adj[currNode]) {
                int nextNode = neighbor.first;
                int weight = neighbor.second;

                if (currDist + weight < dist[nextNode]) {
                    dist[nextNode] = currDist + weight;
                    parent[nextNode] = currNode;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        vector<int> path;
        for (int at = dest; at != -1; at = parent[at]) {
            path.push_back(at);
        }
        reverse(path.begin(), path.end());
        return path;
    }
};

int main() {
    Graph cityGraph;

    cityGraph.addEdge(1, 2, 10);
    cityGraph.addEdge(2, 3, 15);
    cityGraph.addEdge(1, 4, 30);
    cityGraph.addEdge(4, 3, 5);
    cityGraph.addEdge(3, 5, 10);
    cityGraph.addEdge(4, 5, 20);

    int start = 1, destination = 5;
    vector<int> shortestPath = cityGraph.dijkstra(start, destination);

    cout << "Shortest path: ";
    for (int node : shortestPath) {
        cout << node << " ";
    }
    cout << endl;

    cityGraph.updateEdgeWeight(2, 3, 5); // Simulating real-time traffic change

    cout << "Updated shortest path: ";
    shortestPath = cityGraph.dijkstra(start, destination);
    for (int node : shortestPath) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
