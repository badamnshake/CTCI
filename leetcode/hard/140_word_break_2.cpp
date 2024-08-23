#include <vector>
#include <string>
using namespace std;
vector<string> wordBreak(string s, vector<string> &wordDict)
{
    int n = s.size();
    bool curr = false;
    int ws;

    vector<string> stored;
    vector<string> res;
    vector<int> storedSpaces;

    vector<bool> dp(n, false);
    dp.push_back(true);

    for (int i = n - 1; i >= 0; i--)
    {

        curr = false;
        for (auto w : wordDict)
        {
            ws = w.size();
            if (i + ws <= n && s.substr(i, ws) == w && dp[i + ws])
            {
                curr = true;
                if (i + ws == n)
                {

                    stored.push_back(w);
                    storedSpaces.push_back(0);
                }
                else
                {
                    for (int j = 0; j < stored.size(); j++)
                        if (stored[j].size() == n - i - ws + storedSpaces[j])
                        {
                            stored.push_back(w + " " + stored[j]);
                            storedSpaces.push_back(storedSpaces[j] + 1);
                        }
                }
            }
        }

        dp[i] = curr;
    }
    for (int i = 0; i < stored.size(); i++)
    {

        if (stored[i].size() - storedSpaces[i] - n == 0)
            res.push_back(stored[i]);
    }
    return res;
}