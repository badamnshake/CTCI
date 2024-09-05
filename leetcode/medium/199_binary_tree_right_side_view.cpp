#include <vector>
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
vector<int> rightSideView(TreeNode *root)
{
    if (root == nullptr)
        return {};
    queue<TreeNode *> q;
    q.push(root);
    int n;
    vector<int> ans;

    while (!q.empty())
    {
        n = q.size();
        for (int i = 0; i < n; i++)
        {
            if (i == n - 1)
                ans.push_back(q.front()->val);

            if (q.front()->left != nullptr)
                q.push(q.front()->left);

            if (q.front()->right != nullptr)
                q.push(q.front()->right);

            q.pop();
        }
    }
    return ans;
}