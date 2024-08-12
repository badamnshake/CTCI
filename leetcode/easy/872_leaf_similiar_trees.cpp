#include <algorithm>
#include <vector>
using namespace std;
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1;
        vector<int> leaf2;
        leafValSequence(root1, &leaf1);
        leafValSequence(root2, &leaf2);
        if(leaf1.size() == leaf2.size())
        {
            for(int i = 0; i < leaf1.size(); i++)
            {
                if(leaf1[i] != leaf2[i])
                {
                    return false;
                }
            }
            return true;
        }
        return false;
        
    }

    void leafValSequence(TreeNode* root, vector<int>* result)
    {
        if(root == nullptr) return;
        if(root->left == nullptr && root->right== nullptr)
        {
            result->push_back(root->val);
            return;
        }
        leafValSequence(root->left, result);
        leafValSequence(root->right, result);
    }
};