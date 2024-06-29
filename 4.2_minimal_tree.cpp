/* ------------------------------- Problem 4.2 ------------------------------ */
// Minimal Tree: Given a sorted (increasing order) array with unique integer elements, write an algo­
// rithm to create a binary search tree with minimal height.

#include <vector>
#include <iostream>

using namespace std;

class Node
{
public:
    int val;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(int v)
    {
        val = v;
    }
};

Node *sortedArrToBTree(vector<int> arr, int start, int end);

void preorder(Node *root);

void postorder(Node *root);

void inorder(Node *root);

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    Node *root = sortedArrToBTree(arr, 0, arr.size() - 1);

    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    return 0;
}

void inorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    inorder(root->left);
    cout << root->val << " -> ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->val << " -> ";

    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);

    cout << root->val << " -> ";
}

Node *sortedArrToBTree(vector<int> arr, int start, int end)
{

    if (start > end)
        return nullptr;

    if (start == end)
        return new Node(arr[start]);

    int mid = (start + end + 1) / 2;

    Node *root = new Node(arr[mid]);

    root->left = sortedArrToBTree(arr, start, mid - 1);
    root->right = sortedArrToBTree(arr, mid + 1, end);

    return root;
}