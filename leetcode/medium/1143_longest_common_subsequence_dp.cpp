#include <string>
#include <vector>
using namespace std;

int longestCommonSubsequence(string text1, string text2)
{

    int m = text1.size() + 1;
    int n = text2.size() + 1;

    vector<vector<int>> v(m, vector<int>(n, 0));

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                v[i][j] = 1 + v[i - 1][j - 1];
            }
            else
            {
                v[i][j] = max(v[i - 1][j], v[i][j - 1]);
            }
        }
    }
    return v[m - 1][n - 1];

    // return lcs(text1, text2, text1.size(), text2.size());
}
// int lcs(string t1, string t2, int m, int n) {
//     if (m == 0 || n == 0)
//         return 0;
//     if (t1[m - 1] == t2[n - 1]) {
//         return 1 + lcs(t1, t2, m - 1, n - 1);
//     } else
//         return max(lcs(t1, t2, m - 1, n), lcs(t1, t2, m, n - 1));
// }