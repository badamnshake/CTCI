#include <vector>
#include <string>
using namespace std;

string longestPalindrome(string s)
{
    string res = s.substr(0, 1);
    int n = s.size();
    int l;
    int r;
    int cmax = 1;

    for (int i = 0; i < n; i++)
    {
        l = i;
        r = i;

        while (l >= 0 && r < n && s[l] == s[r])
        {
            if (r - l + 1 > cmax)
            {
                cmax = r - l + 1;
                res = s.substr(l, cmax);
            }
            l--;
            r++;
        }

        l = i;
        r = i + 1;

        while (l >= 0 && r < n && s[l] == s[r])
        {
            if (r - l + 1 > cmax)
            {
                cmax = r - l + 1;
                res = s.substr(l, cmax);
            }
            l--;
            r++;
        }
    }

    return res;
}