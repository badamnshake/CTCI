#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

bool isUnique(string s);
bool isUniqueWithoutAdditionalDS(string s);

string str[] = {"stopping", "1", "xtra", "", "arcreactor"};

int main()
{
    for (auto s : str)
    {

        cout << "str: " << s << endl;

        if (isUnique(s))
            cout << "Unique: Hash" << endl;
        else
            cout << "Not Unique: Hash" << endl;

        if (isUniqueWithoutAdditionalDS(s))
            cout << "Unique: Sort" << endl;
        else
            cout << "Not Unique: Sort" << endl;
    }

    return 0;
}

/* ------------------------------- problem 1.1 ------------------------------ */
// Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you
// cannot use additional data structures?
// implementation using hashmap
bool isUnique(string s)
{
    unordered_set<char> uset;

    for (auto x : s)
    {
        if (uset.find(x) == uset.end())
        {
            uset.insert(x);
        }
        else
        {
            return false;
        }
    }
    return true;
}

/* ------------------------------- problem 1.1 ------------------------------ */
bool isUniqueWithoutAdditionalDS(string s)
{
    sort(s.begin(), s.end());

    if (s.size() == 2)
    {
        if (s[0] == s[1])
            return false;
        else
            return true;
    }

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
            return false;
    }

    return true;
}