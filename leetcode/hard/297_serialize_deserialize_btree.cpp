  #include <string>
  #include <iostream>
  #include <queue>
  #include <vector>

  using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string s;
        postOrder(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        int i = 0;
        stringstream ss(data);
        string substr;

        queue<int> q;

        while (ss.good())
        {
            getline(ss, substr, ',');
            if (substr.empty())
                q.push(INT_MIN);
            else
                q.push(stoi(substr));
        }
        return postOrderSerialize(q);
    }

    TreeNode *postOrderSerialize(queue<int> &q)
    {
        if (q.empty())
            return nullptr;

        if (q.front() == INT_MIN)
            return nullptr;

        TreeNode *root = new TreeNode(q.front());

        q.pop();

        root->left = postOrderSerialize(q);

        q.pop();

        root->right = postOrderSerialize(q);

        return root;
    }

    void postOrder(TreeNode *r, string &s)
    {
        if (r == nullptr)
        {
            s += ",";
            return;
        }
        s += to_string(r->val) + ",";

        postOrder(r->left, s);
        postOrder(r->right, s);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));