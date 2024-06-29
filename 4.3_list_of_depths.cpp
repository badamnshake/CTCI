/* ------------------------------- Problem 4.3 ------------------------------ */
// List of Depths: Given a binary tree, design an algorithm which creates a linked list of all the nodes
// at each depth (e.g., if you have a tree with depth D, you'll have D linked lists).

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class LNode
{
public:
    int value;
    LNode *next = nullptr;
    LNode(int val)
    {
        value = val;
    }
};

class Node
{
public:
    int value;
    Node *right = nullptr;
    Node *left = nullptr;
    Node(int val)
    {
        value = val;
    }
};

Node *sortedArrToBTree(vector<int> arr, int start, int end);
void printLL(LNode *root);
vector<LNode *> listOfDepths(Node *root);

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    Node *root = sortedArrToBTree(v, 0, v.size() - 1);
    auto x = listOfDepths(root);

    for (auto z : x)
        printLL(z);

    return 0;
}

vector<LNode *> listOfDepths(Node *root)
{
    vector<LNode *> lls;
    queue<Node *> q;
    q.push(root);
    int n;
    Node *temp;

    while (!q.empty())
    {
        n = q.size();

        LNode *x;

        for (int i = 0; i < n; i++)
        {
            temp = q.front();
            q.pop();

            if (i == 0)
            {
                x = new LNode(temp->value);
                lls.push_back(x);
            }
            else
            {
                x->next = new LNode(temp->value);
                x = x->next;
            }

            if (temp->left != nullptr)
                q.push(temp->left);

            if (temp->right != nullptr)
                q.push(temp->right);
        }
    }

    return lls;
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

void printLL(LNode *root)
{
    LNode *temp = root;
    while (temp != nullptr)
    {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << endl;
}
