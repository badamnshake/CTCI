#include <vector>
#include <string>
using namespace std;
string convert(string s, int numRows)
{
    if (numRows == 1)
        return s;
    int n = s.size();

    string res;
    vector<vector<char>> v(numRows, vector<char>(n, ' '));
    int i = 0;
    int r = 0;
    int c = 0;

    while (i < n)
    {
        while (i < n && r < numRows)
        {

            v[r][c] = s[i];
            r++;
            i++;
        }
        r--;
        r--;
        c++;
        while (i < n && r > 0)
        {

            v[r][c] = s[i];
            c++;
            r--;
            i++;
        }
    }

    for (r = 0; r < numRows; r++)
    {
        for (c = 0; c < n; c++)
        {
            if (v[r][c] != ' ')
                res.push_back(v[r][c]);
        }
    }
    return res;
}