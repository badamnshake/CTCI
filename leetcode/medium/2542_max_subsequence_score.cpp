#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
{
    vector<pair<int, int>> se;
    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < nums1.size(); i++)
    {
        se.push_back({nums2[i], nums1[i]});
    }
    sort(se.begin(), se.end(),
         [](const pair<int, int> &a, const pair<int, int> &b)
         {
             return a.first > b.first;
         });

    long long sum = 0;
    long long ans = 0;
    for (int i = 0; i < k; i++)
    {
        q.push(se[i].second);
        sum += se[i].second;
    }

    ans = max(sum * se[k - 1].first, ans);

    for (int i = k; i < se.size(); i++)
    {

        sum += se[i].second - q.top();
        q.pop();
        q.push(se[i].second);
        ans = max(sum * se[i].first, ans);
    }
    return ans;
}