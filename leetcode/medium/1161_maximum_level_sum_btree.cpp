
#include <queue>
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
int maxLevelSum(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    int n;

    int level = 0;
    int ans = 1;
    int maxx = INT_MIN;
    int sum;
    TreeNode *node;

    while (!q.empty())
    {
        level++;
        sum = 0;
        n = q.size();
        for (int i = 0; i < n; i++)
        {
            node = q.front();
            q.pop();
            sum += node->val;

            if (node->right != nullptr)
                q.push(node->right);

            if (node->left != nullptr)
                q.push(node->left);
        }
        if (sum > maxx)
        {
            maxx = sum;
            ans = level;
        }
    }
    return ans;
}