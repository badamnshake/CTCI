#include <algorithm>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};
int maxPathSum(TreeNode *root)
{
    int ans = INT_MIN;
    iteratePaths(root, ans);
    return ans;
}

int iteratePaths(TreeNode *root, int &currMax)
{

    if (root == nullptr)
        return 0;
    else if (root->left == nullptr && root->right == nullptr)
    {
        currMax = max(root->val, currMax);
        return root->val;
    }
    else
    {
        int lMax = iteratePaths(root->left, currMax);
        int rMax = iteratePaths(root->right, currMax);
        int takeMax =
            max(root->val, max(root->val + lMax, root->val + rMax));

        currMax = max(currMax, takeMax);
        currMax = max(currMax, root->val + lMax + rMax);
        return takeMax;
    }
}