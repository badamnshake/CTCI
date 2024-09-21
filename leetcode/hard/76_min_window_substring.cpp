#include <string>
#include <map>
#include <vector>

using namespace std;

string minWindow(string s, string t)
{

    int maxc = INT_MAX;
    string result = "";
    map<char, int> m;
    vector<int> v;
    int n = s.size();

    for (auto c : t)
    {
        if (m.find(c) == m.end())
            m[c] = 1;
        else
            m[c] += 1;
    }

    for (int i = 0; i < n; i++)
        if (m.find(s[i]) != m.end())
            v.push_back(i);

    if (v.empty())
        return result;
    int i = 0;
    int j = 0;
    int len;
    int minn = -1;

    while (j < v.size() && i <= j)
    {
        m[s[v[j]]]--;
        j++;

        if (ismz(m))
        {

            while (true)
            {
                len = v[j - 1] - v[i];
                if (len < maxc)
                {
                    maxc = len;
                    minn = v[i];
                }
                m[s[v[i]]] += 1;

                i++;

                if (m[s[v[i - 1]]] > 0)
                    break;
            }
        }
    }

    if (minn != -1)
        result = s.substr(minn, maxc + 1);

    return result;
}

bool ismz(map<char, int> &m)
{
    for (auto x : m)
    {
        if (x.second > 0)
            return false;
    }
    return true;
}