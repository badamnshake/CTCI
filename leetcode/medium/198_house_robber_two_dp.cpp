#include <vector>
#include <algorithm>
using namespace std;
int rob(vector<int> &nums)
{
    int n = nums.size();
    int i = 1;

    int adj;
    int far;
    int tmp;
    int pmax;

    if (n == 1)
        return nums[0];
    if (n == 2)
        return max(nums[0], nums[1]);
    if (n == 3)
        return max(max(nums[0], nums[1]), nums[2]);

    adj = nums[1];
    far = 0;
    for (int i = 2; i < n; i++)
    {
        tmp = max(adj, nums[i] + far);
        far = adj;
        adj = tmp;
    }
    pmax = tmp;

    adj = nums[0];
    far = 0;
    for (int i = 1; i < n - 1; i++)
    {
        tmp = max(adj, nums[i] + far);
        far = adj;
        adj = tmp;
    }
    return max(tmp, pmax);
}