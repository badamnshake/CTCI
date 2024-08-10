/* ------------------------------- Problem 8.4 ------------------------------ */
// Power Set: Write a method to return all subsets of a set.

#include <vector>
#include <iostream>

using namespace std;
void helper(int i, vector<int> nums, vector<int> set, vector<vector<int>> *subs, int k);

void helper2(vector<int> nums, vector<int> set, vector<vector<int>> *subs, int k);
void perms(vector<int> nums, vector<int> set, vector<vector<int>> *subs);

int main()
{
    vector<vector<int>> subs = {};
    // helper(0, {1, 2, 3}, {}, &subs, 3);
    perms({1, 2, 3}, {}, &subs);
    for (auto s : subs)
    {
        for (auto x : s)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

void helper(int i, vector<int> nums, vector<int> set, vector<vector<int>> *subs, int k)
{

    if (set.size() == k)
    {
        subs->push_back(set);
        return;
    }
    if (i >= nums.size())
        return;

    set.push_back(nums[i]);
    helper(i + 1, nums, set, subs, k);

    set.pop_back();
    helper(i + 1, nums, set, subs, k);
}

void helper2(vector<int> nums, vector<int> set, vector<vector<int>> *subs, int k)
{

    if (set.size() == k)
    {
        subs->push_back(set);
        return;
    }
    if (nums.size() == 0)
        return;

    auto copy = nums;
    while (!nums.empty())
    {
        set.push_back(nums[0]);
        nums.erase(nums.begin());
        helper2(nums, set, subs, k);
        set.pop_back();
    }
}

void perms(vector<int> nums, vector<int> set, vector<vector<int>> *subs)
{

    if (nums.size() == 0)
    {
        subs->push_back(set);
        return;
    }
    auto copy = nums;

    for (size_t i = 0; i < nums.size(); i++)
    {
        copy = nums;
        set.push_back(nums[i]);
        copy.erase(copy.begin() + i);
        perms(copy, set, subs);
        set.pop_back();
    }
}
