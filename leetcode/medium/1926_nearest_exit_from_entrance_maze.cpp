#include <vector>
#include <queue>
#include <set>

using namespace std;

int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
{
    int m = maze.size();
    int n = maze[0].size();
    set<vector<int>> visited;
    queue<vector<int>> q;
    q.push({entrance[0], entrance[1]});
    vector<int> p;
    visited.insert(p);
    int d = 0;
    int x;

    while (!q.empty())
    {
        x = q.size();
        for (int i = 0; i < x; i++)
        {
            p = q.front();
            visited.insert(p);
            q.pop();

            int r = p[0];
            int c = p[1];

            if (d != 0 && (r == 0 || c == 0 || r == m - 1 || c == n - 1))
                return d;

            p = {r - 1, c};
            if (r - 1 >= 0 && maze[r - 1][c] == '.' &&
                visited.find(p) == visited.end())
            {
                visited.insert(p);
                q.push(p);
            }

            p = {r + 1, c};
            if (r + 1 < m && maze[r + 1][c] == '.' &&
                visited.find(p) == visited.end())
            {

                visited.insert(p);
                q.push(p);
            }

            p = {r, c - 1};
            if (c - 1 >= 0 && maze[r][c - 1] == '.' &&
                visited.find(p) == visited.end())
            {

                visited.insert(p);

                q.push(p);
            }

            p = {r, c + 1};
            if (c + 1 < n && maze[r][c + 1] == '.' &&
                visited.find(p) == visited.end())
            {

                visited.insert(p);

                q.push(p);
            }
        }

        d++;
    }
    return -1;
}