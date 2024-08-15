/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 */

int guess(int num);

class Solution
{
public:
    int guessNumber(int n)
    {
        long i = 0;
        long j = n;
        long mid;
        short res;

        while (i <= n)
        {
            mid = (i + j) / 2;
            res = guess(mid);
            if (res == -1)
            {
                j = mid - 1;
            }
            else if (res == 1)
            {
                i = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        return 0;
    }
};