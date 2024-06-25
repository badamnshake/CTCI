/* ------------------------------- Problem 3.6 ------------------------------ */
// Animal Shelter: An animal shelter, which holds only dogs and cats, operates on a strictly"first in, first
// out" basis. People must adopt either the "oldest" (based on arrival time) of all animals at the shelter,
// or they can select whether they would prefer a dog or a cat (and will receive the oldest animal of
// that type). They cannot select which specific animal they would like. Create the data structures to
// maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog,
// and dequeueCat. You may use the built-in Linked list data structure.
#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    char animal;
    int serialNum;
    Node *next;

    Node(char a)
    {
        animal = a;
        next = nullptr;

        // generate a random num for serial num between 1 and 100
        // 0-50 for dogs and 51-100 for cats
        if (a == 'd')
            serialNum = rand() % 50 + 1;

        if (a == 'c')
            serialNum = rand() % 50 + 51;
    }
};



pair<Node *, int> dequeue(Node *head);
pair<Node *, int> dequeueDog(Node *head);
pair<Node *, int> dequeueCat(Node *head);
Node* enqueue(Node *head, char type);
void printLL(Node* head);

int main()
{
    vector<int> ll = {'d', 'c', 'c', 'd', 'c', 'd'};
    // first initialize a list
    Node *list = nullptr;


    for (auto x : ll)
        list = enqueue(list, x);
    printLL(list);
    cout << endl;
    
    auto x  = dequeueDog(list);
    list = x.first;
    x = dequeueDog(list);
    list = x.first;
    printLL(list);

    return 0;
}


void printLL(Node* head)
{
    Node* temp = head;
    while(temp != nullptr)
    {
        cout << temp->animal << " _ ";
        temp = temp->next;
    }
}

Node* enqueue(Node *head, char type)
{
    Node *temp = head;

    if (temp == nullptr)
    {
        head = new Node(type);
        return head;
    }

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = new Node(type);
    return head;
}

// return the latest animal be it a dog or cat its serial number
pair<Node *, int> dequeue(Node *head)
{
    pair<Node *, int> result;
    if (head == nullptr)
    {
        return {nullptr, -1};
    }
    result.first = head->next;
    result.second = head->serialNum;
    // idk why I am pointing it to null to flush memory perhaps?
    head->next = nullptr;
    return result;
}

// return the latest animal be it a dog or cat its serial number
pair<Node *, int> dequeueDog(Node *head)
{

    pair<Node *, int> result;
    Node *prev = nullptr;
    Node *curr = head;
    while (curr->animal != 'd')
    {
        prev = curr;
        curr = curr->next;
    }

    if (prev == nullptr)
    {
        result.first = curr->next;
        result.second = curr->serialNum;
        return result;
    }

    result.first = head;
    result.second = curr->serialNum;
    prev->next = curr->next;
    return result;
}

// return the latest animal be it a dog or cat its serial number
pair<Node *, int> dequeueCat(Node *head)
{

    pair<Node *, int> result;
    Node *prev = nullptr;
    Node *curr = head;
    while (curr->animal != 'c')
    {
        prev = curr;
        curr = curr->next;
    }

    if (prev == nullptr)
    {
        result.first = nullptr;
        result.second = curr->serialNum;
        return result;
    }

    result.first = head;
    result.second = curr->serialNum;
    prev->next = curr->next;
    return result;
}