#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> path1;
        vector<TreeNode *> path2;
        findPath(root, path1, p->val);
        findPath(root, path2, q->val);
        int i;

        for (i = 0; i < path1.size() && i < path2.size(); i++)
        {
            if (path1[i] != path2[i])
                break;
        }
        return path1[i - 1];
    }

    bool findPath(TreeNode *root, vector<TreeNode *> &path, int k)
    {
        if (root == NULL)
            return false;

        path.push_back(root);

        if (root->val == k)
            return true;

        if ((root->left && findPath(root->left, path, k)) ||
            (root->right && findPath(root->right, path, k)))
            return true;

        path.pop_back();
        return false;
    }
};