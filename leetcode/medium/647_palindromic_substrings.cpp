    #include <string>
    using namespace std;
    int countSubstrings(string s)
    {
        int n = s.size();
        int count = 0;
        int l;
        int r;

        for (int i = 0; i < n; i++)
        {
            l = i;
            r = i;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                count++;
                l--;
                r++;
            }

            l = i;
            r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                count++;
                l--;
                r++;
            }
        }
        return count;
    }