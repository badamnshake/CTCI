#include <string>
using namespace std;

bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    if (x < 10)
        return true;
    string xs = to_string(x);
    int i = 0;
    int j = xs.size() - 1;

    while (i <= j)
    {
        if (xs[i] != xs[j])
            return false;
        i++;
        j--;
    }

    return true;
}