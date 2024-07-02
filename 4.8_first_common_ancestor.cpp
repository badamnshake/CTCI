/* ------------------------------- Problem 4.8 ------------------------------ */
// First Common Ancestor: Design an algorithm and write code to find the first common ancestor
// of two nodes in a binary tree. Avoid storing additional nodes in a data structure. NOTE: This is not
// necessarily a binary search tree.
#include <vector>
#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(int value)
    {
        this->value = value;
    }
};

bool preOrderFindIsLeftSide(Node *root, int val, bool &left);

Node *firstCommonAncestor(Node *root, int i, int j);

int main()
{
    Node* root = new Node(1);

    Node* temp = root;

    temp->left = new Node(2);
    temp->right = new Node(8);

    temp = temp->left;

    temp->left = new Node(3);
    temp->right = new Node(3);

    Node* temp1 = temp->left;
    Node* temp2 = temp->right;

    temp1->left = new Node(4);
    temp1->right = new Node(5);

    temp2->left = new Node(6);
    temp2->right = new Node(7);

    Node* common = firstCommonAncestor(root, 4, 8);
    std::cout << common->value << std::endl;
    return 0;
}

Node *firstCommonAncestor(Node *root, int i, int j)
{
    auto curr = root;
    bool isIonLeftSide;
    bool isJonLeftSide;
    preOrderFindIsLeftSide(root, i, isIonLeftSide);
    preOrderFindIsLeftSide(root, j, isJonLeftSide);

    if (isIonLeftSide != isJonLeftSide)
        return curr;

    if (isIonLeftSide)
        return firstCommonAncestor(root->left, i, j);

    return firstCommonAncestor(root->right, i, j);
}

bool preOrderFindIsLeftSide(Node *root, int val, bool &left)
{
    bool isLeft;
    bool isFound = false;
    if (root == nullptr)
        return false;

    if (root->value == val)
        return true;

    if (preOrderFindIsLeftSide(root->left, val, left))
    {
        left = true;
        return true;
    }
    if (preOrderFindIsLeftSide(root->right, val, left))
    {
        left = false;
        return true;
    }
    return false;
}