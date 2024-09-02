#include <vector>
using namespace std;
int chalkReplacer(vector<int> &chalk, int k)
{
    long long int sum = 0;
    for (auto c : chalk)
    {
        sum += c;
    }
    k = k % sum;
    for (int i = 0; i < chalk.size(); i++)
    {
        k -= chalk[i];
        if (k < 0)
            return i;
    }
    return 0;
}