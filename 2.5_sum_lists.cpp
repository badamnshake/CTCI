/* ------------------------------- Problem 2.5 ------------------------------ */
// Sum Lists: You have two numbers represented by a linked list, where each node contains a single
// digit. The digits are stored in reverse order, such that the 1 's digit is at the head of the list. Write a
// function that adds the two numbers and returns the sum as a linked list.
// EXAMPLE
// Input: (7-> 1 -> 6) + (5 -> 9 -> 2).That is,617 + 295.
// Output: 2 -> 1 -> 9. That is, 912.
// FOLLOW UP
// Suppose the digits are stored in forward order. Repeat the above problem.
// EXAMPLE
// lnput:(6 -> 1 -> 7) + (2 -> 9 -> 5).That is,617 + 295.
// Output: 9 -> 1 -> 2. That is, 912.

#include <iostream>
#include <vector>

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

    Node()
    {
        data = 0;
        next = nullptr;
    }
};

Node *createLL(vector<int> values);
int calculateValues(Node *head);
Node *sumTwoVector(Node *h1, Node *h2);

vector<int> ll1 = {7, 1, 6, 5};
vector<int> ll2 = {5, 9, 2, 5, 9, 9, 9, 9};

int main()
{

    Node *h1 = createLL(ll1);
    int x = calculateValues(h1);

    Node *h2 = createLL(ll2);
    int y = calculateValues(h2);

    Node *h3 = sumTwoVector(h1, h2);
    int z = calculateValues(h3);

    cout << x + y << endl;
    cout << z << endl;

    return 0;
}

Node *createLL(vector<int> values)
{
    Node *head = new Node(values[0]);
    Node *temp = head;
    for (int i = 1; i < values.size(); i++)
    {
        temp->next = new Node(values[i]);
        temp = temp->next;
    }
    return head;
}

int calculateValues(Node *head)
{
    int mul = 1;
    int sum = 0;
    while (head != nullptr)
    {
        sum += mul * head->data;
        mul *= 10;
        head = head->next;
    }
    return sum;
}

Node *sumTwoVector(Node *h1, Node *h2)
{

    int carry = 0;
    int sum;

    Node *n = new Node();
    Node *head = n;

    while (h1 != nullptr && h2 != nullptr)
    {
        sum = h1->data + h2->data + carry;

        if (sum > 9)
        {
            sum -= 10;
            carry = 1;
        }
        else
            carry = 0;

        h1 = h1->next;
        h2 = h2->next;

        n->next = new Node(sum);
        n = n->next;
    }
    Node *h = h1 == nullptr ? h2 : h2 == nullptr ? h1
                                                 : nullptr;

    // if both were the same length
    if (h != nullptr)
        while (h != nullptr)
        {
            sum = h->data + carry;
            if (sum > 9)
            {
                sum -= 10;
                carry = 1;
            }
            else
                carry = 0;

            h = h->next;
            n->next = new Node(sum);
            n = n->next;
        }
    if (carry == 1)
        n->next = new Node(carry);

    return head->next;
}