
// simple implementation of linked list to use for problem solving purposes

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = nullptr;
    }
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

Node* createLinkedList(vector<int> arr);
void printLinkedList(Node* head);
void removeDuplicates(Node* head);

vector<int> ll = {1, 2, 3, 6, 8, 9, 1, 2, 9, 3};

int main()
{
    Node* h = createLinkedList(ll);
    printLinkedList(h);
    removeDuplicates(h);
    cout << endl;
    printLinkedList(h);

    return 0;
}

// what if prev was not allowed
void removeDuplicates(Node* head)
{
    Node* temp = head;

    unordered_set<int> uset;
    uset.insert(head->data);

    Node* prev = temp;
    temp = temp->next;

    while(temp != nullptr)
    {
        if(uset.find(temp->data) != uset.end())
        {
            prev->next = temp->next;
            temp = temp->next;
        }
        else {
            uset.insert(temp->data);
            prev = temp;
            temp = temp->next;
        }
    }
}

Node* createLinkedList(vector<int> arr)
{
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i = 1; i < arr.size(); i++)
    {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

void printLinkedList(Node* head)
{
    while(head != nullptr)
    {
        cout << head->data << " _ ";
        head = head->next;
    }
}