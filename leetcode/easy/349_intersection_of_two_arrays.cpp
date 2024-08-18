#include <vector>
#include <unordered_set>
using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    if (nums1.size() > nums2.size())
        return intersection(nums2, nums1);

    vector<int> isec;
    unordered_set<int> s;
    unordered_set<int> s2;

    for (auto x : nums2)
    {
        s.insert(x);
    }
    for (auto y : nums1)
    {
        if (s.find(y) != s.end())
        {
            s2.insert(y);
        }
    }
    for (auto z : s2)
    {
        isec.push_back(z);
    }
    return isec;
}