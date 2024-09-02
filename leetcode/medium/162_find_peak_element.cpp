#include <vector>

using namespace std;
int findPeakElement(vector<int> &nums)
{
    int n = nums.size();
    int l = 0;
    int r = n - 1;

    int mid;

    while (l <= r)
    {
        mid = l + (r - l) / 2;

        if (mid > 0 && nums[mid] < nums[mid - 1])
        {
            r = mid - 1;
        }
        else if (mid < n - 1 && nums[mid] < nums[mid + 1])
        {
            l = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return 0;
}
