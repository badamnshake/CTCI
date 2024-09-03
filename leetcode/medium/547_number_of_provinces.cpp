#include <vector>
#include <queue>
using namespace std;
int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    int provinces = 0;
    queue<int> conn;
    int curr;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;

        provinces++;
        conn.push(i);

        while (!conn.empty())
        {
            curr = conn.front();
            conn.pop();

            for (int j = 0; j < n; j++)
                if (isConnected[curr][j] && !visited[j])
                {
                    visited[j] = true;
                    conn.push(j);
                }
        }
    }
    return provinces;
}