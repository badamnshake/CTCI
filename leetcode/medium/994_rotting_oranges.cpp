#include<vector>
#include<queue>

using namespace std;
int orangesRotting(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int fresh = 0;

    queue<vector<int>> q;

    int r;
    int c;

    vector<int> start = {};

    for (r = 0; r < m; r++)
        for (c = 0; c < n; c++)
        {

            if (grid[r][c] == 2)
                q.push({r, c});

            if (grid[r][c] == 1)
                fresh++;
        }

    if (q.empty() && fresh == 0)
        return 0;

    else if (q.empty())
        return -1;

    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    int ans = -1;
    int x;

    while (!q.empty())
    {
        x = q.size();
        ans++;

        while (x--)
        {
            start = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                r = start[0] + dx[i];
                c = start[1] + dy[i];

                if (r < 0 || c < 0 || r >= m || c >= n)
                    continue;
                if (grid[r][c] != 1)
                    continue;
                q.push({r, c});
                grid[r][c] = 2;
            }
        }
    }

    for (r = 0; r < m; r++)
        for (c = 0; c < n; c++)
            if (grid[r][c] == 1)
                return -1;

    return ans;
}