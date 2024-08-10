/* ------------------------------- Problem 8.9 ------------------------------ */
// Parens: Implement an algorithm to print all valid (e.g., properly opened and closed) combinations
// of n pairs of parentheses

#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> parens(int n);

int main()
{
    auto x = parens(3);

    for (auto y : x)
    {
        cout << y << endl;
    }
    return 0;
}

vector<string> parens(int n)
{
    vector<string> result;
    int l = 0;
    int r = 0;
    result.push_back("()");

    for(int i = 1; i < n; i++)
    {

    }
}