#include <vector>
using namespace std;
//  * Definition for a binary tree node.
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
class Solution
{
public:
    int pathSum(TreeNode *root, int targetSum)
    {
        int n = 0;
        pathS(root, {}, targetSum, n);
        return n;
    }

    void pathS(TreeNode *root, vector<long int> pastSums, int targetSum,
               int &paths)
    {
        if (root == nullptr)
            return;

        for (int i = 0; i < pastSums.size(); i++)
        {
            if ((long int)root->val + pastSums[i] == (long int)targetSum)
                paths++;

            pastSums[i] += root->val;
        }
        if ((long int)root->val == (long int)targetSum)
            paths++;
        pastSums.push_back(root->val);
        pathS(root->left, pastSums, targetSum, paths);
        pathS(root->right, pastSums, targetSum, paths);
    }
};