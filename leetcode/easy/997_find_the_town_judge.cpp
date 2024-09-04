#include <vector>
#include <unordered_set>
#include <map>

using namespace std;
int findJudge(int n, vector<vector<int>> &trust)
{
    if (trust.size() == 0 && n == 1)
        return n;
    map<int, int> tCount;
    unordered_set<int> p;

    for (auto t : trust)
    {
        if (p.find(t[0]) == p.end())
            p.insert(t[0]);

        if (tCount.find(t[1]) == tCount.end())
            tCount[t[1]] = 1;
        else
            tCount[t[1]]++;
    }

    for (auto c : tCount)
        if (c.second == n - 1 && p.find(c.first) == p.end())
            return c.first;

    return -1;
}