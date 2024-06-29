/* ------------------------------- Problem 4.5 ------------------------------ */
// Validate BST: Implement a function to check if a binary tree is a binary search tree.
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

bool validateBST(Node *root);

int main()
{

    Node *root = new Node(5);

    Node *temp = root;


    temp->left = new Node(3);
    temp->right = new Node(7);



    temp = root->left;

    temp->left = new Node(2);
    temp->right = new Node(4);

    temp = root->right;



    temp->left = new Node(6);
    temp->right = new Node(8);

    if(validateBST(root))
     cout << "valid" << endl;
    else
        cout << "invalid" << endl;

    return 0;
}

bool validateBST(Node *root)
{
    if (root == nullptr)
        return true;

    if (root->left != nullptr && root->left->value > root->value)
        return false;

    if (root->right != nullptr && root->right->value < root->value)
        return false;

    if (!validateBST(root->right) || !validateBST(root->left))
        return false;

    return true;
}