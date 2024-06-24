/* ------------------------------- Problem 2.7 ------------------------------ */
// Intersection: Given two (singly) linked lists, determine if the two lists intersect. Return the inter­
// secting node. Note that the intersection is defined based on reference, not value. That is, if the kth
// node of the first linked list is the exact same node (by reference) as the jth node of the second
// linked list, then they are intersecting
#include <vector>
#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = nullptr;
    }
};

void printLL(Node *head);
Node *createLL(vector<int> values);
Node *findIntersection(Node *head1, Node *head2);

void addToEnd(Node *head, Node *end);

vector<int> ll1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
vector<int> ll2 = {0, 2, 4, 6, 8, 10, 12};
vector<int> ll3 = {13, 14, 15, 99};

int main()
{
    Node *h1 = createLL(ll1);
    Node *h2 = createLL(ll2);
    Node *h3 = createLL(ll3);

    addToEnd(h1, h3);
    addToEnd(h2, h3);

    printLL(h1);
    cout << endl;
    printLL(h2);
    cout << endl;

    Node *t = findIntersection(h1, h2);
    cout << t->data << endl;

    return 0;
}

Node *createLL(vector<int> values)
{
    Node *head = new Node(values[0]);
    Node *temp = head;
    for (int i = 1; i < values.size(); i++)
    {
        head->next = new Node(values[i]);
        head = head->next;
    }
    return temp;
}

void printLL(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " > ";
        head = head->next;
    }
}

void addToEnd(Node *head, Node *end)
{
    Node *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = end;
}

Node *findIntersection(Node *head1, Node *head2)
{
    Node *temp1 = head1;
    Node *temp2 = head2;

    int count1 = 0;
    int count2 = 0;

    while (temp1->next != nullptr)
    {
        count1++;
        temp1 = temp1->next;
    }

    while (temp2->next != nullptr)
    {
        count2++;
        temp2 = temp2->next;
    }

    if (&temp1 == &temp2)
        return nullptr;

    temp1 = head1;
    temp2 = head2;

    if (count1 > count2)
    {
        while (count1 != count2)
        {
            temp1 = temp1->next;
            count1--;
        }
    }
    else if (count2 > count1)
    {
        while (count2 != count1)
        {
            temp2 = temp2->next;
            count2--;
        }
    }

    while (temp2 != temp1)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return temp2;
}
