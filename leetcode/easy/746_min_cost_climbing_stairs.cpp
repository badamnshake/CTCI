#include <vector>
#include <algorithm>

using namespace std;

int minCostClimbingStairs(vector<int> &cost)
{
    int result = 0;
    int i = 2;

    cost.push_back(0);

    for (i; i < cost.size(); i++)
    {
        cost[i] = min(cost[i - 1] + cost[i], cost[i - 2] + cost[i]);
    }
    return cost[i - 1];
}