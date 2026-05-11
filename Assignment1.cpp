#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
    unordered_map<int, vector<int>> adj;

public:

    // Add edge (undirected graph)
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Print graph
    void printGraph()
    {
        cout << "\nGraph Representation:\n";

        for (auto &node : adj)
        {
            cout << node.first << " -> ";

            for (int nbr : node.second)
                cout << nbr << " ";

            cout << endl;
        }
    }

    // ---------------- DFS (Recursive) ----------------
    void DFS(int node, unordered_map<int, bool> &visited)
    {
        visited[node] = true;
        cout << node << " ";

        for (int nbr : adj[node])
        {
            if (!visited[nbr])
                DFS(nbr, visited);
        }
    }

    // ---------------- BFS (Iterative) ----------------
    void BFS(int start)
    {
        unordered_map<int, bool> visited;
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            cout << node << " ";

            for (int nbr : adj[node])
            {
                if (!visited[nbr])
                {
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }

        cout << endl;
    }
};

int main()
{
    Graph g;

    // Add edges
    g.addEdge(30, 23);
    g.addEdge(30, 45);
    g.addEdge(23, 100);
    g.addEdge(45, 5000);
    g.addEdge(100, 999);

    // Print graph
    g.printGraph();

    // DFS
    cout << "\nDFS Traversal: ";
    unordered_map<int, bool> visitedDFS;
    g.DFS(30, visitedDFS);

    cout << endl;

    // BFS
    g.BFS(30);

    return 0;
}