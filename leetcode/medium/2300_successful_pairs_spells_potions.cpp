#include <vector>
#include <algorithm>

using namespace std;

vector<int> successfulPairs(vector<int> &spells, vector<int> &potions,
                            long long success)
{
    sort(potions.begin(), potions.end());
    int p = potions.size();
    int n = spells.size();
    int i = 0;
    vector<int> result(n, 0);
    int l = 0;
    int r = p - 1;
    int mid;
    int currMin = 0;

    while (i < n)
    {
        currMin = p;
        l = 0;
        r = p - 1;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (success <= (long long)potions[mid] * spells[i])
            {
                currMin = min(mid, currMin);
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        result[i] = p - currMin;
        i++;
    }
    return result;
}