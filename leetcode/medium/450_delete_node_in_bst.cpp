
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
    TreeNode *deleteNode(TreeNode *root, int key)
    {

        if (root == nullptr)
            return root;

        if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        else if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else
        {
            if (root->right == nullptr)
                return root->left;
            else if (root->left == nullptr)
                return root->right;
            else
            {
                TreeNode *temp = root->left;
                while (temp->right != nullptr)
                    temp = temp->right;
                root->val = temp->val;
                root->left = deleteNode(root->left, root->val);
            }
        }
        return root;
    }
};