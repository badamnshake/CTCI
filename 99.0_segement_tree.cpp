#include <iostream>
#include <vector>

using namespace std;

class SNode
{
public:
    int l;
    int r;
    int sum;
    SNode *left = nullptr;
    SNode *right = nullptr;

    SNode(int l, int r, int sum)
    {
        this->l = l;
        this->r = r;
        this->sum = sum;
    }
};

SNode *create_seg_tree(vector<int> v, int l, int r);

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    create_seg_tree(v, 0, v.size() - 1);

    return 0;
}

SNode *create_seg_tree(vector<int> v, int l, int r)
{
    if (l == r)
        return new SNode(v[l], l, r);
    int mid = (r + l) / 2;
    SNode *s = new SNode(l, r, 0);
    s->left = create_seg_tree(v, l, mid);
    s->right = create_seg_tree(v, mid + 1, r);
    s->sum = s->left->sum + s->right->sum;
    return s;
}

void update_seg_tree(SNode *root, int i, int value)
{
    if (root->l == root->r)
    {
        root->sum = value;
        return;
    }

    int mid = (root->l + root->r) / 2;
    if (i > mid)
    {
        update_seg_tree(root->right, i, value);
    }
    else
    {
        update_seg_tree(root->left, i, value);
    }
    root->sum = root->left->sum + root->right->sum;
}
int rangeQuery(SNode *root, int l, int r)
{
    if (l == root->l && r == root->r)
    {
        return root->sum;
    }
    int mid = (root->l + root->r) / 2;
    if (l > mid)
    {
        return rangeQuery(root->right, l, r);
    }
    else if (r <= mid)
    {

        return rangeQuery(root->left, l, r);
    }
    else
    {
        return rangeQuery(root->left, l, mid) + rangeQuery(root->right, mid + 1, r);
    }
}