#include <vector>
using namespace std;

bool increasingTriplet(vector<int> &nums)
{
    int n = nums.size();
    vector<int> smallest;
    vector<int> greatest(n, 0);
    smallest.push_back(nums[0]);
    greatest[n - 1] = nums[n - 1];

    for (int i = n - 2; i >= 0; i--)
        greatest[i] = max(greatest[i + 1], nums[i]);

    for (int i = 1; i < n - 1; i++)
    {
        smallest.push_back(min(smallest[i - 1], nums[i]));
        if (smallest[i] < nums[i] && nums[i] < greatest[i])
            return true;
    }

    return false;
}