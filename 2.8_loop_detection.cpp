/* ------------------------------- Problem 2.8 ------------------------------ */
// Loop Detection: Given a circular linked list, implement an algorithm that returns the node at the
// beginning of the loop

#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    Node *next;
    int data;

    Node(int d)
    {
        data = d;
        next = nullptr;
    }
};

Node *createLL(vector<int> values);
void printLL(Node *head);
Node* detectLoop(Node *head);
vector<int> ll = {11, 2, 3, 4, 2, 13, 12};

int main()
{
    Node *head = createLL(ll);
    Node* temp = head;
    while(temp->next != nullptr)
        temp = temp->next;
    temp->next = head;

    Node* l = detectLoop(head);

    cout << l->data << endl;

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

void printLL(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " > ";
        head = head->next;
    }
}

Node *detectLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (slow != nullptr && fast != nullptr && slow->next != nullptr && fast->next != nullptr && fast->next->next != nullptr)
    {
        if (slow == fast)
        {
            return slow;
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    return nullptr;
}