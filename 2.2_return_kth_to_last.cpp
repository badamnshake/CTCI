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
        next = nullptr;
        data = d;
    }
};

Node* createLL(vector<int> arr)
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

void printLL(Node* h)
{
    while(h != nullptr)
    {
        cout << h->data << " _ ";
        h = h->next;
    }
}

vector<int> ll = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

int main()
{

    Node* head = createLL(ll);

    return 0;
}

int kthToTheLast(Node* head, int k)
{
    if(head == nullptr)
        return 0;
    int index = kthToTheLast(head->next, k) + 1; 
    if(index == k)
    {
        cout << head->data << endl;
    }
    return index;
    


}