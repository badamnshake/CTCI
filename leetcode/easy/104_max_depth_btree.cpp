//   Definition for a binary tree node.
#include <algorithm>
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
    int maxDepth(TreeNode *root)
    {
        return mdepth(root, 1);
    }

    int mdepth(TreeNode *root, int depth)
    {
        int maxdepth = 0;
        int l = depth;
        int r = depth;
        if (root == nullptr)
            return maxdepth;
        if (root->left != nullptr)
        {

            l = mdepth(root->left, depth + 1);
        }
        if (root->right != nullptr)
        {
            r = mdepth(root->right, depth + 1);
        }
        maxdepth = max(l, r);
        return maxdepth;
    }
};