#include <vector>
using namespace std;
int findTargetSumWays(vector<int> &nums, int target)
{
    vector<int> sums;
    sums.push_back(nums[0]);
    sums.push_back(0 - nums[0]);

    int n = sums.size();

    for (int i = 1; i < nums.size(); i++)
    {

        n = sums.size();
        for (int j = 0; j < n; j++)
        {
            sums.push_back(sums[j] - nums[i]);
            sums[j] += nums[i];
        }
    }
    n = 0;
    for (auto x : sums)
    {
        if (x == target)
            n++;
    }
    return n;
}