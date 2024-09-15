#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

vector<double> calcEquation(vector<vector<string>> &equations,
                            vector<double> &values,
                            vector<vector<string>> &queries)
{
    map<string, int> m;
    int curr = 0;

    string l;
    string r;

    for (auto e : equations)
    {
        if (m.find(e[0]) == m.end())
            m[e[0]] = curr++;
        if (m.find(e[1]) == m.end())
            m[e[1]] = curr++;
    }

    vector<vector<pair<int, double>>> adj(m.size());

    for (int i = 0; i < equations.size(); i++)
    {
        l = equations[i][0];
        r = equations[i][1];

        adj[m[l]].push_back(make_pair(m[r], values[i]));
        adj[m[r]].push_back(make_pair(m[l], 1 / values[i]));
    }

    vector<vector<double>> costs(m.size());
    for (int i = 0; i < costs.size(); i++)
        costs[i] = bfs(i, adj);
    vector<double> res;

    for (auto q : queries)
    {
        if (m.find(q[0]) == m.end() || m.find(q[1]) == m.end())
            res.push_back(-1);
        else
            res.push_back(costs[m[q[0]]][m[q[1]]]);
    }
    return res;
}

vector<double> bfs(int c, vector<vector<pair<int, double>>> adj)
{
    vector<bool> v(adj.size(), false);
    v[c] = true;
    vector<double> result(adj.size(), -1);
    result[c] = 1;
    queue<int> q;
    q.push(c);
    int n;
    while (!q.empty())
    {
        n = q.size();
        for (int i = 0; i < n; i++)
        {
            for (auto a : adj[q.front()])
            {
                if (v[a.first])
                    continue;
                result[a.first] = result[q.front()] * a.second;

                q.push(a.first);
                v[a.first] = true;
            }

            q.pop();
        }
    }

    return result;
}