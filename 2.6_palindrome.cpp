/* ------------------------------- Proble 2.6 ------------------------------- */
// Palindrome: Implement a function to check if a linked list is a palindrome.

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
Node *reverseLL(Node *head);

bool checkPalindromeUsingRLL(Node *list, Node *reverse);

bool checkPalindromeUsingRunningNode(Node *head);

vector<int> ll = {1, 2, 3, 4,  2, 1};
int main()
{
    Node *h = createLL(ll);
    Node *r = reverseLL(h);
    h = createLL(ll);
    if (checkPalindromeUsingRLL(h, r))
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not Palindrome" << endl;
    }

    if (checkPalindromeUsingRunningNode(h))
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not Palindrome" << endl;
    }
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

Node *reverseLL(Node *head)
{
    Node *prev = nullptr;
    Node *curr = head;
    Node *next;

    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    return prev;
}

void printLL(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " > ";
        head = head->next;
    }
}

bool checkPalindromeUsingRLL(Node *list, Node *reverse)
{

    while (list->next != nullptr)
    {
        if (list->data == reverse->data)
        {
            list = list->next;
            reverse = reverse->next;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool checkPalindromeUsingRunningNode(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    bool isOdd;
    vector<int> store;

    while (true)
    {
        if (fast->next == nullptr)
        {
            isOdd = true;
            break;
        }
        else if(fast->next->next == nullptr)
        {
            isOdd = false;
            break;
        }
        else
        {
            fast = fast->next->next;
            store.push_back(slow->data);
            slow = slow->next;
        }
    }

    if(!isOdd)
        store.push_back(slow->data);

    slow = slow->next;

    while(slow != nullptr)
    {
        if(store.back() == slow->data)
        {
            store.pop_back();
            slow = slow->next;
        }
        else return false;
    }
    return true;
}