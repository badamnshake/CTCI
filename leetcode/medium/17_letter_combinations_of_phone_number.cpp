#include <vector>
#include <string>
#include <map>

using namespace std;
vector<string> letterCombinations(string digits)
{
    return lc(digits);
}

vector<string> lc(string d, vector<string> arr = {})
{
    map<char, string> keypad;
    keypad['2'] = "abc";
    keypad['3'] = "def";
    keypad['4'] = "ghi";
    keypad['5'] = "jkl";
    keypad['6'] = "mno";
    keypad['7'] = "pqrs";
    keypad['8'] = "tuv";
    keypad['9'] = "wxyz";
    vector<string> newarr;
    string temp;
    if (d.size() == 0)
    {
        return arr;
    }
    if (arr.size() == 0)
    {
        for (auto c : keypad[d.front()])
        {
            temp = c;
            newarr.push_back(temp);
        }
    }
    else
    {
        for (int i = 0; i < arr.size(); i++)
        {
            for (auto c : keypad[d.front()])
                newarr.push_back(arr[i] + c);
        }
    }
    return lc(d.substr(1), newarr);
}