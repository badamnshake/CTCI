/* ------------------------------- Problem 8.4 ------------------------------ */
// Power Set: Write a method to return all subsets of a set.

#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> subsets(vector<int> set, vector<vector<int>> subs);

int main()
{
    vector<int> set = {1, 2, 3, 4, 5};
    auto subs = subsets(set, {{}});
    for (auto s : subs)
    {
        cout << "{ ";
        for (auto x : s)
        {
            cout << x << " ";
        }
        cout << "}, ";
        cout << endl;
    }

    return 0;
}

vector<vector<int>> subsets(vector<int> set, vector<vector<int>> subs)
{
    vector<int> temp;

    for(auto x: set)
    {
        int n = subs.size();
        subs.push_back({x});
        for(int i = 1; i < n; i++)
        {
            temp = subs[i];
            temp.push_back(x);
            subs.push_back(temp);
        }
    }


    return subs;
}