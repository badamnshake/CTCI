#include <string>
#include <vector>
using namespace std;
bool wordBreak(string s, vector<string> &wordDict)
{
    int n = s.size();
    vector<bool> dp(n, false);
    dp.push_back(true);
    int ws;

    for (int i = n - 1; i >= 0; i--)
    {
        for (auto w : wordDict)
        {
            ws = w.size();

            if (i + ws <= n && s.substr(i, ws) == w)
            {
                dp[i] = dp[i + ws];
            }
            if (dp[i])
                break;
        }
    }
    return dp[0];
}