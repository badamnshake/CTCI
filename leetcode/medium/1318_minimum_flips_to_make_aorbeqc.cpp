#include <string>
using namespace std;
int minFlips(int a, int b, int c)
{
    string as = to_binary(a);
    string bs = to_binary(b);
    string cs = to_binary(c);

    int maxl = max(as.size(), max(bs.size(), cs.size()));

    if (as.size() < maxl)
        while (as.size() != maxl)
            as = "0" + as;

    if (bs.size() < maxl)
        while (bs.size() != maxl)
            bs = "0" + bs;

    if (cs.size() < maxl)
        while (cs.size() != maxl)
            cs = "0" + cs;

    int count = 0;
    for (int i = 0; i < maxl; i++)
    {
        if (cs[i] == '1')
        {
            if (as[i] == '0' && bs[i] == '0')
                count++;
        }
        else
        {
            if (as[i] == '1')
                count++;
            if (bs[i] == '1')
                count++;
        }
    }
    return count;
}

string to_binary(int n)
{
    string r;
    while (n != 0)
    {
        r = (n % 2 == 0 ? "0" : "1") + r;
        n /= 2;
    }
    return r;
}