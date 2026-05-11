#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
    // Adjacency List
    unordered_map<int, vector<pair<int, int>>> adj;

public:

    // Function to add edge
    void addEdge(int u, int v, int w)
    {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Prim's MST Algorithm
    void primMST(int start)
    {
        // {weight, node, parent}
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;

        unordered_map<int, bool> visited;

        int totalWeight = 0;

        // Store MST edges
        vector<vector<int>> mst;

        // {weight, node, parent}
        pq.push({0, start, -1});

        while (!pq.empty())
        {
            int weight = pq.top()[0];
            int node = pq.top()[1];
            int parent = pq.top()[2];

            pq.pop();

            // Skip visited nodes
            if (visited[node])
            {
                continue;
            }

            visited[node] = true;

            totalWeight += weight;

            // Store edge in MST
            if (parent != -1)
            {
                mst.push_back({parent, node, weight});
            }

            // Traverse neighbors
            for (auto neighbor : adj[node])
            {
                int adjNode = neighbor.first;
                int edgeWeight = neighbor.second;

                if (!visited[adjNode])
                {
                    pq.push({edgeWeight, adjNode, node});
                }
            }
        }

        // Print MST
        cout << "Edges in MST:\n";

        for (auto edge : mst)
        {
            cout << edge[0]
                 << " - "
                 << edge[1]
                 << " : "
                 << edge[2]
                 << endl;
        }

        cout << "\nTotal Weight of MST = "
             << totalWeight
             << endl;
    }
};

int main()
{
    Graph g;

    // Add edges
    g.addEdge(30, 23, 2);
    g.addEdge(30, 45, 6);
    g.addEdge(23, 100, 3);
    g.addEdge(23, 5000, 5);
    g.addEdge(100, 999, 7);
    g.addEdge(45, 5000, 8);

    // Run Prim's Algorithm
    g.primMST(30);

    return 0;
}