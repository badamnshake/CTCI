#include <vector>
#include <algorithm>
using namespace std;

int change(int amount, vector<int> &coins)
{
    if (amount == 0)
        return 1;
    vector<int> v(amount + 1, 0);

    sort(coins.begin(), coins.end(), greater<int>());

    for (auto coin : coins)
    {
        if (coin <= amount)
            v[coin] += 1;
        for (int i = coin; i <= amount - coin; i++)
        {
            v[i + coin] += v[i];
        }
    }

    return v[amount];
}