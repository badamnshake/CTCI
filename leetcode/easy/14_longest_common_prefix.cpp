#include <string>
#include <vector>
using namespace std;
string longestCommonPrefix(vector<string> &strs)
{
    if (strs.size() == 1)
        return strs[0];
    int mins = INT_MAX;
    for (auto s : strs)
    {
        if (s.size() < mins)
            mins = s.size();
    }
    if (mins == 0)
        return "";
    string ans = "";
    bool done = false;
    char c;

    for (int i = 0; i < mins; i++)
    {
        c = strs[0][i];
        for (int j = 1; j < strs.size(); j++)
        {
            if (c != strs[j][i])
                done = true;
        }
        if (done)
            break;

        ans.push_back(c);
    }
    return ans;
}