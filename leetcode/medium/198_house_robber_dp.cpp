#include <vector>
#include <algorithm>
using namespace std;
int rob(vector<int> &nums)
{

    int i = 2;

    if (nums.size() == 1)
        return nums[0];

    nums.push_back(0);

    nums[1] = max(nums[0], nums[1]);

    for (i; i < nums.size(); i++)
    {
        nums[i] = max(nums[i - 2] + nums[i], nums[i - 1]);
    }
    return nums[i - 1];
}