#include <vector>
#include <unordered_set>
#include <set>
using namespace std;
// class Solution {
bool canPartition(vector<int> &nums)
{
    long long int sum;
    unordered_set<long long int> sums;
    // set<vector<int>> sums;

    for (auto x : nums)
    {
        sum += x;
    }
    if (sum % 2 != 0)
        return false;
    sum = sum / 2;

    for (int i = 0; i < nums.size(); i++)
    {
        if (sums.find(nums[i]) != sums.end())
            return true;

        if (sum - nums[i] == 0)
            return true;
        for (auto it : sums)
        {
            sums.insert(it - nums[i]);
        }
        sums.insert(sum - nums[i]);
    }
    // if(sums.find(0) != sums.end()) return true;
    return false;

    // return cancp(nums,sums, 0, 0, 0);
}

bool cancp(vector<int> nums, set<vector<int>> &sums, int i, int ls, int rs)
{
    if (i == nums.size())
    {
        if (ls == rs)
            return true;
        return false;
    }

    if (sums.find({i, rs, ls}) != sums.end() || sums.find({i, ls, rs}) != sums.end())
        return false;

    bool x = cancp(nums, sums, i + 1, ls + nums[i], rs);

    if (x)
        return true;

    sums.insert({i + 1, ls + nums[i], rs});

    bool y = cancp(nums, sums, i + 1, ls, rs + nums[i]);

    if (y)
        return true;

    sums.insert({i + 1, ls, rs + nums[i]});

    return false;
}
// };