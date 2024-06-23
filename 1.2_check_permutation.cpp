#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

bool isPerm(string s1, string s2);
vector<string> str1 = {"stopping", "12", "xtra", "", "arcreactor"};
vector<string> str2 = {"ppsotnig", "21", "xtra", "", "arcreactom"};

int main()
{

    for (int i = 0; i < str1.size(); i++)
    {

        if (isPerm(str1[i], str2[i]))
            cout << "Yes : " << str1[i] << " - " << str2[i] << endl;
        else
            cout << "No : " << str1[i] << " - " << str2[i] << endl;
    }

    return 0;
}

/* ------------------------------- problem 1.2 ------------------------------ */
// Check Permutation: Given two strings, write a method to decide if one is a permutation of the
// other.
bool isPerm(string s1, string s2)
{
    if (s1.size() != s2.size())
        return false;

    if (s1.size() == 0)
        return true;

    unordered_map<char, int> map;

    for (auto x : s1)
    {
        if (map.find(x) == map.end())
        {
            map[x] = 1;
        }
        else
        {
            map[x] += 1;
        }
    }

    for (auto y : s2)
    {
        if (map.find(y) == map.end())
        {
            return false;
        }
        else
        {
            map[y] -= 1;

            if (map[y] < 0)
                return false;
        }
    }

    // if any element was not traversed return false;
    for (auto i = map.begin(); i != map.end(); i++)
        if (i->second != 0)
            return false;

    // if all conditions were met return true
    return true;
}
