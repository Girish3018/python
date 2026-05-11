#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

// ---------------- Node Structure ----------------
struct Node
{
    vector<vector<int>> state;
    int g;        // cost from start
    int h;        // heuristic cost
    int x, y;     // position of blank (0)
    Node *parent;

    int f() const
    {
        return g + h;
    }
};

// ---------------- Goal State ----------------
vector<vector<int>> goal =
{
    {1,2,3},
    {4,5,6},
    {7,8,0}
};

// Directions (up, down, left, right)
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// ---------------- Heuristic (Manhattan Distance) ----------------
int heuristic(vector<vector<int>> &state)
{
    int h = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (state[i][j] != 0)
            {
                int val = state[i][j];

                int targetX = (val - 1) / 3;
                int targetY = (val - 1) % 3;

                h += abs(i - targetX) + abs(j - targetY);
            }
        }
    }

    return h;
}

// ---------------- Convert State to String ----------------
string toString(vector<vector<int>> &state)
{
    string s = "";

    for (auto &row : state)
    {
        for (auto &val : row)
        {
            s += to_string(val);
        }
    }

    return s;
}

// ---------------- Comparator for Priority Queue ----------------
struct Compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->f() > b->f();
    }
};

// ---------------- Print Path ----------------
void printPath(Node *node)
{
    vector<vector<vector<int>>> path;

    while (node)
    {
        path.push_back(node->state);
        node = node->parent;
    }

    reverse(path.begin(), path.end());

    cout << "\nSolution Path:\n";

    for (auto &state : path)
    {
        for (auto &row : state)
        {
            for (auto &val : row)
            {
                cout << val << " ";
            }
            cout << endl;
        }
        cout << "------\n";
    }
}

// ---------------- A* Algorithm ----------------
void AStar(vector<vector<int>> start)
{
    priority_queue<Node*, vector<Node*>, Compare> pq;
    unordered_set<string> visited;

    int x, y;

    // find blank position
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (start[i][j] == 0)
            {
                x = i;
                y = j;
            }
        }
    }

    Node *root = new Node{start, 0, heuristic(start), x, y, NULL};
    pq.push(root);

    while (!pq.empty())
    {
        Node *curr = pq.top();
        pq.pop();

        string key = toString(curr->state);

        if (visited.count(key))
            continue;

        visited.insert(key);

        // goal check
        if (curr->state == goal)
        {
            cout << "Goal Reached!\n";
            printPath(curr);
            return;
        }

        // explore moves
        for (int i = 0; i < 4; i++)
        {
            int nx = curr->x + dx[i];
            int ny = curr->y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < 3 && ny < 3)
            {
                vector<vector<int>> newState = curr->state;

                swap(newState[curr->x][curr->y], newState[nx][ny]);

                string newKey = toString(newState);

                if (!visited.count(newKey))
                {
                    Node *child = new Node{
                        newState,
                        curr->g + 1,
                        heuristic(newState),
                        nx, ny,
                        curr
                    };

                    pq.push(child);
                }
            }
        }
    }

    cout << "No Solution Found!" << endl;
}

// ---------------- Main ----------------
int main()
{
    vector<vector<int>> start =
    {
        {1,2,3},
        {4,0,6},
        {7,5,8}
    };

    cout << "Initial State:\n";

    for (auto &row : start)
    {
        for (auto &val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    AStar(start);

    return 0;
}