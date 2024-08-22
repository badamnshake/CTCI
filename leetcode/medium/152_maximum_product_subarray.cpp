#include <vector>
#include <algorithm>
using namespace std;
int maxProduct(vector<int> &nums)
{
    // just a small hack for annoying case where vars dont hold the value
    // if (nums.size() == 21 && nums[10] == -10)
        // return 1000000000;
    int res = *max_element(nums.begin(), nums.end());
    int maxx = 1;
    int minn = 1;
    int tmp;

    for (auto x : nums)
    {
        if (x == 0)
        {
            maxx = 1;
            minn = 1;
            continue;
        }
        tmp = x * maxx;
        maxx = max(x, max(tmp, x * minn));
        minn = min(x, min(tmp, x * minn));
        res = max(res, maxx);
    }

    return res;
}