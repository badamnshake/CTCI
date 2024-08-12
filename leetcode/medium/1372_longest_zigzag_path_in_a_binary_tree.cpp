#include <algorithm>
using namespace std;
//   Definition for a binary tree node.
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
    int longestZigZag(TreeNode* root) {
        int n = 0;
        maxzigzag(root, false, false, 0, n);
        return n;
        
        
    }

    void maxzigzag(TreeNode* root, bool l, bool r, int currD, int& maxD)
    {
        maxD = max(currD, maxD);

        if(root == nullptr) return;

        maxzigzag(root->left, 1, 0, l ? 0 : currD + r, maxD);

         
        maxzigzag(root->right, 0, 1, r ? 0 : currD + l, maxD);
    }
};