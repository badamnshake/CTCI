/* -------------------------------------------------------------------------- */
/*                                   Graphs                                   */
/* -------------------------------------------------------------------------- */

// vertices: v, edges: e
// e <= v^2
// adjacency matrix::
// adjacency list::
// adjacency matrix:: in some thing:: 0 is free, 1 is blocked

#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <list>
#include <queue>

using namespace std;

vector<vector<int>> matrix;

vector<vector<int>> edges = {{1, 2}, {2, 3}, {2, 5}, {3, 5}, {5, 4}};

class Graph
{
public:
    map<int, list<int>> adjList;
    Graph()
    {
    }
};

int matrixPathsDFS(vector<vector<int>> matrix, int x, int y, vector<vector<bool>> visited);

int matrixPathsBFS(vector<vector<int>> matrix);

Graph *makeGraphFromEdges(vector<vector<int>> edges);

bool graphDFS(Graph *g, int start, int value, unordered_set<int> visited);
void graphBFS(Graph *g, int start);

int main()
{
    Graph *g = makeGraphFromEdges(edges);
    unordered_set<int> visited;
    if (graphDFS(g, 1, 5, visited))
    {
        cout << "DFS" << endl;
    }
    graphBFS(g, 1);
    // vector<int> v0 = {0, 0, 0, 0};
    // vector<int> v1 = {1, 1, 0, 0};
    // vector<int> v2 = {0, 0, 0, 0};
    // vector<int> v3 = {0, 1, 0, 0};
    // matrix.push_back(v0);
    // matrix.push_back(v1);
    // matrix.push_back(v2);
    // matrix.push_back(v3);

    // vector<bool> b0 = {false, false, false, false};
    // vector<vector<bool>> visited;
    // for (int i = 0; i < matrix.size(); i++)
    // {
    //     visited.push_back(b0);
    // }
    // cout << matrixPathsDFS(matrix, 0, 0, visited) << endl;
    // cout << matrixPathsBFS(matrix) << endl;

    return 0;
}

Graph *makeGraphFromEdges(vector<vector<int>> edges)
{
    Graph *g = new Graph();
    list<int> empty;
    for (auto edge : edges)
    {
        if (g->adjList.find(edge[0]) == g->adjList.end())
            g->adjList.insert({edge[0], empty});
        if (g->adjList.find(edge[1]) == g->adjList.end())
            g->adjList.insert({edge[1], empty});

        g->adjList.find(edge[0])->second.push_back(edge[1]);
    }
    return g;
}

// dfs in graph
bool graphDFS(Graph *g, int start, int value, unordered_set<int> visited)
{
    visited.insert(start);
    auto arr = g->adjList.find(start)->second;

    for (auto x : arr)
    {
        if (visited.find(x) != visited.end())
            continue;

        if (x == value)
            return true;

        if (graphDFS(g, x, value, visited))
            return true;
    }

    return false;
}

// bfs in graph
void graphBFS(Graph *g, int start)
{
    queue<int> q;
    unordered_set<int> visited;
    list<int> arr;
    int n;
    int x;
    visited.insert(start);
    q.push(start);

    while (!q.empty())
    {
        n = q.size();

        for (int i = 0; i < n; i++)
        {
            x = q.front();
            q.pop();
            arr = g->adjList.find(x)->second;
            for (auto elem : arr)
            {
                if (visited.find(elem) == visited.end())
                {
                    q.push(elem);
                    cout << elem << " - ";
                    visited.insert(elem);
                }
                
            }
        }
        cout << endl;
    }
}

// you can only traverse through zeros in a matrix
// count how many paths exist without visiting the same cell from top left to bottom right
int matrixPathsDFS(vector<vector<int>> matrix, int x, int y, vector<vector<bool>> visited)
{

    if (x < 0 || y < 0 || x >= matrix.size() || y >= matrix[0].size() || visited[x][y] || matrix[x][y] == 1)
    {
        return 0;
    }
    else if (x == matrix[0].size() - 1 && y == matrix.size() - 1)
    {
        return 1;
    }

    visited[x][y] = true;

    int count = 0;
    count += matrixPathsDFS(matrix, x, y + 1, visited);
    count += matrixPathsDFS(matrix, x, y - 1, visited);
    count += matrixPathsDFS(matrix, x + 1, y, visited);
    count += matrixPathsDFS(matrix, x - 1, y, visited);

    return count;
}

// shortest path from top left to right
int matrixPathsBFS(vector<vector<int>> matrix)
{
    int x = 0;
    int y = 0;
    vector<vector<bool>> visited;
    vector<bool> b0;
    for (auto x : matrix[0])
        b0.push_back(false);

    for (auto x : matrix)
        visited.push_back(b0);

    queue<pair<int, int>> q;
    vector<pair<int, int>> neighbors;
    q.push({x, y});
    int n;
    int count = 0;

    while (!q.empty())
    {
        n = q.size();

        for (int i = 0; i < n; i++)
        {
            auto curr = q.front();
            q.pop();
            x = curr.first;
            y = curr.second;
            neighbors = {{x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}};
            for (auto z : neighbors)
            {
                x = z.first;
                y = z.second;

                if (x == matrix.size() - 1 && y == matrix.size() - 1)
                    return count;

                if (x < 0 || y < 0 || x >= matrix.size() || y >= matrix[0].size() || visited[x][y] || matrix[x][y] == 1)
                    continue;

                q.push({x, y});
                visited[x][y] = true;
            }
            count++;
        }
    }

    return count;
}