/* ------------------------------- Problem 4.6 ------------------------------ */
// Successor: Write an algorithm to find the "next" node (i.e., in-order successor) of a given node in a
// binary search tree. You may assume that each node has a link to its parent.

#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *parent = nullptr;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(int value, Node *parent = nullptr)
    {
        this->value = value;
        this->parent = parent;
    }
};

int main()
{

    return 0;
}

// i do not know if this will necessariliy work 
int successor(Node *curr)
{
    Node *rtop = nullptr;
    if (curr->parent == nullptr)
    {
        // there is no successor because this is the largest
        if (curr->right == nullptr)
            return -1;
        rtop = curr->right;
    }

    if (rtop == nullptr)
        rtop = curr->parent->right;

    while (rtop->left != nullptr)
        rtop = rtop->left;

    return rtop->value;
}