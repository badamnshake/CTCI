#include <vector>
#include <queue>
using namespace std;
bool canVisitAllRooms(vector<vector<int>> &rooms)
{
    vector<bool> visited(rooms.size(), false);
    queue<int> keys;
    int n;
    int curr;

    keys.push(0);

    while (!keys.empty())
    {
        n = keys.size();
        for (int i = 0; i < n; i++)
        {

            curr = keys.front();
            keys.pop();
            if (!visited[curr])
            {
                visited[curr] = true;
                for (auto k : rooms[curr])
                {
                    keys.push(k);
                }
            }
        }
    }

    for (auto v : visited)
    {
        if (!v)
            return false;
    }
    return true;
}