// Binary Search Tree
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// everything in the left subtree should be <
// everything int eh right subtree should b >
// BSTs dont have duplicates
class Node
{
public:
    Node *left = nullptr;
    Node *right = nullptr;
    int data;

    Node(int data)
    {
        this->data = data;
    }
};

vector<int> v = {5, 2, 3, 7, 6, 1, 4, 0};

bool search(Node *root, int target);
Node *remove(Node *root, int target);

int minValueNode(Node *root);

Node *insert(Node *root, int data);

void inorder(Node *root);
void preorder(Node *root);
void postorder(Node *root);

void bfs(Node *root);
void bfsx(Node *root);

int main()
{
    Node *root = nullptr;
    for (auto x : v)
    {
        root = insert(root, x);
    }
    // inorder(root);
    // cout << endl;
    // preorder(root);

    // cout << endl;
    // postorder(root);
    cout << endl;
    // bfs(root);


    bfsx(root);

    cout << endl;
}

bool search(Node *root, int target)
{
    if (root == nullptr)
        return false;

    if (target > root->data)
        return search(root->right, target);
    else if (target < root->data)
        return search(root->left, target);
    else
        return true;
}

Node *remove(Node *root, int target)
{
    if (root == nullptr)
        return nullptr;

    if (target > root->data)
    {
        root->right = remove(root->right, target);
    }

    else if (target < root->data)
    {
        root->left = remove(root->left, target);
    }
    else
    {
        if (root->left == nullptr)
            return root->right;
        else if (root->right == nullptr)
            return root->left;
        else
        {
            int min = minValueNode(root->right);
            root->data = min;
            root->right = remove(root->right, min);
        }
    }
    return root;
}

int minValueNode(Node *root)
{
    Node *curr = root;
    while (curr != nullptr && curr->left != nullptr)
    {
        curr = curr->left;
    }
    return curr->data;
}

Node *insert(Node *root, int data)
{
    if (root == nullptr)
        return new Node(data);

    if (data > root->data)
        root->right = insert(root->right, data);

    else if (data < root->data)
        root->left = insert(root->left, data);

    return root;
}

void inorder(Node *root)
{

    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " - ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " - ";

    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{

    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);

    cout << root->data << " - ";
}

void bfs(Node *root)
{
    queue<Node *> q;
    stack<Node *> s;

    Node *temp = nullptr;

    s.push(root);

    while (!s.empty())
    {
        while (!s.empty())
        {
            temp = s.top();
            cout << temp->data << " - ";
            if (temp->left != nullptr)
                q.push(temp->left);
            if (temp->right != nullptr)
                q.push(temp->right);
            s.pop();
        }
        while (!q.empty())
        {
            s.push(q.front());
            q.pop();
        }
        cout << endl;
    }
}

void bfsx(Node *root)
{
    queue<Node *> q;

    Node *temp = nullptr;
    q.push(root);
    int n;

    while (!q.empty())
    {
        n = q.size();
        for (int i = 0; i < n; i++)
        {
            temp = q.front();
            q.pop();

            cout << temp->data << " ";

            if (temp->left != nullptr)
                q.push(temp->left);
            if (temp->right != nullptr)
                q.push(temp->right);
        }
        cout << endl;
    }
}