#include <string>
using namespace std;
string countAndSay(int n)
{
    return rle(n);
}

string rle(int n, string res = "1")
{
    if (n == 1)
        return res;

    string t = "";
    int count = 0;
    int i = 0;
    int s = res.size();

    while (i < s)
    {
        count = 1;
        while (i + 1 < s && res[i] == res[i + 1])
        {
            count++;
            i++;
        }
        t += to_string(count);
        t.push_back(res[i]);
        i++;
    }
    return rle(n - 1, t);
}