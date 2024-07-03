/* ------------------------------- Problem 8.2 ------------------------------ */
// Robot in a Grid: Imagine a robot sitting on the upper left corner of grid with r rows and c columns.
// The robot can only move in two directions, right and down, but certain cells are "off limits" such that
// the robot cannot step on them. Design an algorithm to find a path for the robot from the top left to
// the bottom right.

#include <vector>
#include <iostream>

using namespace std;

vector<pair<int, int>> getPath(vector<vector<int>> grid, vector<vector<bool>> visited, vector<pair<int, int>> path, int r, int c);

int main()
{
    vector<vector<int>> grid;

    vector<int> v0 = {0, 0, 0, 0};
    vector<int> v1 = {1, 1, 1, 0};
    vector<int> v2 = {0, 0, 1, 0};
    vector<int> v3 = {0, 1, 0, 0};
    grid.push_back(v0);
    grid.push_back(v1);
    grid.push_back(v2);
    grid.push_back(v3);

    vector<bool> b0 = {false, false, false, false};
    vector<vector<bool>> visited;
    for (int i = 0; i < grid.size(); i++)
    {
        visited.push_back(b0);
    }
    auto x = getPath(grid, visited, {}, 0, 0);

    for (auto y : x)
    {
        cout << y.first << " - " << y.second << endl;
    }

    return 0;
}

vector<pair<int, int>> getPath(vector<vector<int>> grid, vector<vector<bool>> visited, vector<pair<int, int>> path, int r, int c)
{
    path.push_back({r, c});

    if (r == grid[0].size() - 1 && c == grid.size() - 1)
        return path;

    if (r >= grid.size() || c >= grid.size() || grid[r][c] == 1 || visited[r][c])
    {
        path.pop_back();
        return path;
    }
    visited[r][c] = true;

    path = getPath(grid, visited, path, r + 1, c);

    if (path.back().first == grid[0].size() - 1 && path.back().second == grid.size() - 1)
        return path;

    path = getPath(grid, visited, path, r, c + 1);

    if (path.back().first == grid[0].size() - 1 && path.back().second == grid.size() - 1)
        return path;

    path.pop_back();
    return path;
}