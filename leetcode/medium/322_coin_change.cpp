#include <vector>
#include <algorithm>
using namespace std;

int coinChange(vector<int> &coins, int amount)
{
    if (amount == 0)
        return 0;
    vector<int> v(amount + 1, INT_MAX - 1);

    sort(coins.begin(), coins.end(), greater<int>());

    for (auto coin : coins)
    {
        if (coin <= amount)
            v[coin] = 1;
        for (int i = coin; i <= amount - coin; i++)
        {
            v[i + coin] = min(v[i] + 1, v[i + coin]);
        }
    }

    if (v[amount] == INT_MAX - 1)
        return -1;
    return v[amount];
}