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

bool search(Node *root, int target);
Node *remove(Node *root, int target);

int minValueNode(Node *root);

Node *insert(Node *root, int data);

void inorder(Node *root);
void preorder(Node *root);
void postorder(Node *root);

void bfs(Node *root);
void bfsx(Node *root);

bool findPath(Node *root, vector<int> &path);

vector<int> v = {5, 2, 3, 7, 6, 1, 4, 0};

int main()
{
    Node *root = new Node(4);
    Node *temp = root;
    root->left = new Node(1);
    root->right = new Node(1);
    temp = root->left;
    temp->left = new Node(0);
    temp->right = new Node(0);
    temp = root->right;
    temp->left = new Node(0);
    temp->right = new Node(2);
    // Node *root = nullptr;
    // for (auto x : v)
    // {
    //     root = insert(root, x);
    // }
    // inorder(root);
    // cout << endl;
    // preorder(root);

    // cout << endl;
    // postorder(root);
    cout << endl;
    // bfs(root);

    vector<int> path;
    bool isfound = findPath(root, path);
    for(auto x: path)
    {
        cout << x << " - ";
    }

    if (isfound)
        cout << "found" << endl;
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

bool findPath(Node *root, vector<int> &path)
{

    if (root == nullptr || root->data == 0)
        return false;

    path.push_back(root->data);

    if (root->left == nullptr && root->right == nullptr)
        return true;

    if (findPath(root->left, path))
        return true;

    if (findPath(root->right, path))
        return true;

    path.pop_back();

    return false;
}