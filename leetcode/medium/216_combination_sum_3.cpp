#include <vector>
using namespace std;
vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> ans;
    cs(k, n, ans);
    return ans;
}

void cs(int k, int n, vector<vector<int>> &ans, vector<int> curr = {})
{
    if (k == 0)
        return;
    int s = curr.size() ? curr.back() + 1 : 1;
    for (int i = s; i < 10; i++)
    {
        curr.push_back(i);
        if (n - i == 0 && k == 1)
        {
            ans.push_back(curr);
        }
        else if (n - i > 0)
        {
            cs(k - 1, n - i, ans, curr);
        }
        curr.pop_back();
    }
}