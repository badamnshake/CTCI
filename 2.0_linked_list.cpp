// simple implementation of linked list to use for problem solving purposes

#include <iostream>
#include <vector>

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

int main()
{

    return 0;
}