#include <vector>
#include <map>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        map<int, int> m;
        vector<int> ans;

        sums(root, m);

        int max = 0;

        for (auto x : m)
        {
            if (x.second > max)
            {
                max = x.second;
                ans = {};
                ans.push_back(x.first);
            }
            else if (x.second == max)
                ans.push_back(x.first);
        }

        return ans;
    }

    void sums(TreeNode *root, map<int, int> &m)
    {
        if (root == nullptr)
            return;
        sums(root->right, m);
        sums(root->left, m);

        if (root->left != nullptr)
            root->val += root->left->val;

        if (root->right != nullptr)
            root->val += root->right->val;

        if (m.find(root->val) == m.end())
            m[root->val] = 1;
        else
            m[root->val] += 1;
    }
};