#include <string>
using namespace std;
int numDecodings(string s)
{

    int n = s.size();
    if (s[0] == '0')
        return 0;
    if (n == 1)
    {
        return 1;
        // if(s[0] > '2') return 0;
    }
    int t1 = 1;
    int t2 = 1;
    int t;

    for (int i = 1; i < n; i++)
    {
        if (s[i] == '0')
        {
            if (s[i - 1] > '2')
                return 0;
            t = t1;
            t1 = t2 - t1;
            t2 = t;
        }
        // 2 combinations
        else if ((s[i - 1] == '1') || (s[i - 1] == '2' && s[i] != '7' &&
                                       s[i] != '8' && s[i] != '9'))
        {
            t = t2;
            t2 += t1;
            t1 = t;
        }
        else
        {
            t1 = t2;
        }
    }

    return t2;
}