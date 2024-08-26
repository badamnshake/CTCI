#include <string>
#include <algorithm>
using namespace std;
int myAtoi(string s)
{
    long curr = 0;
    bool digitFound = false;
    bool isNegative = false;
    bool isLeadingZero = true;

    for (auto x : s)
    {

        if (curr > INT_MAX)
            break;
        if (x == ' ' && !digitFound)
        {
            continue;
        }
        else if (!digitFound && (x == '-' || x == '+'))
        {

            if (x == '-')
                isNegative = true;
            digitFound = true;
        }
        else if (x >= '0' && x <= '9')
        {

            digitFound = true;
            curr = curr * 10 + (x - '0');
        }
        else
            break;
    }
    if (isNegative)
        curr = 0 - curr;

    if (curr > INT_MAX)
        curr = INT_MAX;
    if (curr < INT_MIN)
        curr = INT_MIN;

    return curr;
}
