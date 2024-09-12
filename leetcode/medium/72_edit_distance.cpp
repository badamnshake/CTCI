#include <string>
#include <vector>
using namespace std;
int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();

    if (n == 0)
        return m;
    if (m == 0)
        return n;
    if (word1 == word2)
        return 0;
    vector<vector<int>> t(n + 1, vector<int>(m + 1, 0));

    for (int r = 0; r <= n; r++)
        t[r][0] = r;

    for (int c = 0; c <= m; c++)
        t[0][c] = c;

    for (int r = 1; r <= n; r++)
    {
        for (int c = 1; c <= m; c++)
        {
            t[r][c] = min(t[r - 1][c - 1] +
                              (word1[r - 1] == word2[c - 1] ? 0 : 1),
                          min(t[r - 1][c] + 1, t[r][c - 1] + 1));
        }
    }
    return t[n][m];
}