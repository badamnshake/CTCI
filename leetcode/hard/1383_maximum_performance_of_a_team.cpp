#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency,
                   int k)
{
    vector<pair<int, int>> se;
    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < speed.size(); i++)
    {
        se.push_back({efficiency[i], speed[i]});
    }
    sort(se.begin(), se.end(),
         [](const pair<int, int> &a, const pair<int, int> &b)
         {
             return a.first > b.first;
         });

    long long int sum = 0;
    long long int ans = 1;
    int m = 1000000007;
    for (int i = 0; i < k; i++)
    {
        q.push(se[i].second);
        sum += se[i].second;
        ans = max(sum * se[i].first, ans);
    }

    for (int i = k; i < n; i++)
    {

        sum += se[i].second - q.top();
        q.pop();
        q.push(se[i].second);
        ans = max(sum * se[i].first, ans);
    }
    return ans % m;
}