#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Graph
{
    // Adjacency List
    unordered_map<int, vector<int>> adj;

    // Store color of each node
    unordered_map<int, int> color;

public:

    // Add Edge
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Check whether color can be assigned
    bool isSafe(int node, int col)
    {
        for (int neighbor : adj[node])
        {
            // Adjacent node has same color
            if (color[neighbor] == col)
            {
                return false;
            }
        }

        return true;
    }

    // Backtracking Function
    bool graphColoring(vector<int> &nodes,int m,int index)
    {
        // All nodes colored
        if (index == nodes.size())
        {
            return true;
        }

        int node = nodes[index];

        // Try all colors
        for (int col = 1; col <= m; col++)
        {
            // Check safe
            if (isSafe(node, col))
            {
                // Assign color
                color[node] = col;

                // Recursive Call
                if (graphColoring(nodes,m,index + 1))
                {
                    return true;
                }

                // Backtracking
                color[node] = 0;
            }
        }

        return false;
    }

    // Solve Function
    void solveGraphColoring(int m)
    {
        vector<int> nodes;

        // Store all graph nodes
        for (auto node : adj)
        {
            nodes.push_back(node.first);
        }

        // Start Backtracking
        if (graphColoring(nodes, m, 0))
        {
            cout << "Solution Exists\n\n";

            cout << "Node -> Color\n";

            for (auto node : nodes)
            {
                cout << node
                     << " -> "
                     << color[node]
                     << endl;
            }
        }
        else
        {
            cout << "No Solution Exists\n";
        }
    }
};

int main()
{
    Graph g;

    // Create Graph
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);

    int totalColors = 3;

    // Solve Graph Coloring
    g.solveGraphColoring(totalColors);

    return 0;
}