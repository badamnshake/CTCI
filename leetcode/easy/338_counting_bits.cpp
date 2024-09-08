#include <vector>
using namespace std;
vector<int> countBits(int n)
{
    if (n == 0)
        return {0};
    int biggestP = 1;
    vector<int> ans(n + 1, 0);
    ans[0] = 0;
    ans[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (i == 2 * biggestP)
        {
            ans[i] = 1;
            biggestP = i;
        }
        else
            ans[i] = ans[biggestP] + ans[i - biggestP];
    }
    return ans;
}