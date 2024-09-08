#include <string>
#include <vector>
using namespace std;
string predictPartyVictory(string senate)
{
    int c = 0;
    int n = senate.size();

    vector<int> ds;
    vector<int> rs;

    for (int i = 0; i < n; i++)
    {
        if (senate[i] == 'R')
            rs.push_back(i);
        else
            ds.push_back(i);
    }

    int d = 0;
    int r = 0;

    while (rs.size() != 0 && ds.size() != 0)
    {
        r = 0;
        d = 0;
        for (int i = 0; i < n; i++)
        {
            if (rs.size() == 0 || ds.size() == 0)
                break;
            if (senate[i] == 'R')
            {
                while (d < ds.size() && ds[d] < i)
                    d++;
                if (d >= ds.size())
                    d = 0;
                senate[ds[d]] = ' ';
                ds.erase(ds.begin() + d);
            }
            else if (senate[i] == 'D')
            {
                while (r < rs.size() && rs[r] < i)
                    r++;
                if (r >= rs.size())
                    r = 0;
                senate[rs[r]] = ' ';
                rs.erase(rs.begin() + r);
            }
        }
    }

    if (!rs.empty())
        return "Radiant";
    return "Dire";
}