
//  * Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
    int goodNodes(TreeNode* root) {
        int n = 0;
        checkGoodNodes(root, root->val, n);
        return n;
    }

    void checkGoodNodes(TreeNode* root, int currMax, int& gn)
    {
        if(root == nullptr) return;
        if(root->val >= currMax) 
        {
            currMax = root->val;
            gn += 1;
        }
        checkGoodNodes(root->left, currMax, gn);
        checkGoodNodes(root->right, currMax, gn);
    }
};