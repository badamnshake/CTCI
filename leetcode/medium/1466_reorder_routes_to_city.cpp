#include <vector>

using namespace std;
int minReorder(int n, vector<vector<int>> &connections)
{
    vector<vector<pair<int, bool>>> adj(n);
    vector<bool> v(n, false);
    v[0] = true;
    int ans = 0;
    for (auto c : connections)
    {
        adj[c[0]].push_back({c[1], false});
        adj[c[1]].push_back({c[0], true});
    }
    dfs(0, adj, v, ans);
    return ans;
}
void dfs(int curr, vector<vector<pair<int, bool>>> &adj, vector<bool> &v, int &swaps)
{
    for (auto p : adj[curr])
    {
        if (v[p.first])
            continue;
        if (!p.second)
            swaps++;
        v[p.first] = true;
        dfs(p.first, adj, v, swaps);
    }
}