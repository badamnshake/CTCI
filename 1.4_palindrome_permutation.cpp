#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

bool isPalperm(string s);

vector<string> str = {"stopping", "12", "xtra", "", "arcreactor"};

int main()
{

    for (int i = 0; i < str.size(); i++)
    {
        if (isPalperm(str[i]))
            cout << "Yes : " << str[i] << endl;
        else
            cout << "No : " << str[i] << endl;
    }

    return 0;
}

/* ------------------------------- problem 1.4 ------------------------------ */
// Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palin­
// drome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation
// is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.
// 1.5
// 1.6
// EXAMPLE
// Input:
// Tact Coa
// Output:
// True (permutations: "taco cat", "atco eta", etc.)

bool isPalperm(string s)
{

    unordered_map<char, int> map;

    s.erase(remove_if(s.begin(), s.end(), isspace), s.end());

    int n = s.size();
    if (n <= 1)
        return true;

    if (n == 2)
    {
        if (s[0] == s[1])
            return true;
        else
            return false;
    }

    for (auto x : s)
    {
        if (map.find(x) == map.end())
            map[x] = 1;
        else
            map[x]++;
    }
     
    bool isOneOdd = false;

    for(auto i = map.begin(); i != map.end(); i++)
    {
        if(i->second % 2 == 1)
        {
            if(isOneOdd) return false;
            isOneOdd = true;
        }
    }

    return true;
}