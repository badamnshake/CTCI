/* ------------------------------- Problem 4.4 ------------------------------ */
// Check Balanced: Implement a function to check if a binary tree is balanced. For the purposes of
// this question, a balanced tree is defined to be a tree such that the heights of the two subtrees of any
// node never differ by more than one.

#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int value;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(int val)
    {
        value = val;
    }
};

int checkBalanced(Node *root);

int main()
{
    Node *root = new Node(0);
    Node *temp = root;

    temp->right = new Node(1);
    temp->left = new Node(5);

    temp = root->right;

    temp->right = new Node(2);
    temp->left = new Node(3);

    temp = root->left;

    temp->right = new Node(4);
    temp->left = new Node(5);

    cout << checkBalanced(root) << endl;
    return 0;
}

// if the bst is  balanced then this algorithm returns the height of the tree
// if there is no root then 0
// if the bst is not balanced it returns -1
int checkBalanced(Node *root)
{

    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        int lHeight = checkBalanced(root->left) + 1;
        if (lHeight == -1)
            return -1;

        int rHeight = checkBalanced(root->right) + 1;

        cout << "root: " << root->value << ", l: " << lHeight << ", r: " << rHeight << endl;

        if (rHeight == -1)
            return -1;

        if (abs(lHeight - rHeight) > 1)
            return -1;

        if (lHeight > rHeight)
            return lHeight;
        return rHeight;
    }

    // return 1;
}
