#include <vector>
using namespace std;
char nextGreatestLetter(vector<char> &letters, char target)
{
    int l = 0;
    int r = letters.size() - 1;
    int mid;

    while (l <= r)
    {
        mid = (l + r) / 2;

        if (letters[mid] > target)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    if (l >= letters.size())
        return letters[0];
    return letters[l];
}