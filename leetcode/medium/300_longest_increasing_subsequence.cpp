#include <vector>
using namespace std;
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> inc(n, 1);
    int res = 0;
    int currmax = 1;
    int maxx = 1;

    for (int i = 0; i < n; i++)
    {
        currmax = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[j] < nums[i])
            {
                currmax = max(currmax, inc[j] + 1);
            }
        }
        inc[i] = currmax;
        maxx = max(currmax, maxx);
    }
    return maxx;
}