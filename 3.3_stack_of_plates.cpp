/* ------------------------------- Problem 3.3 ------------------------------ */
// Stack of Plates: Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
// Therefore, in real life, we would likely start a new stack when the previous stack exceeds some
// threshold. Implement a data structure SetOfStacks that mimics this. SetO-fStacks should be
// composed of several stacks and should create a new stack once the previous one exceeds capacity.
// SetOfStacks. push() and SetOfStacks. pop() should behave identically to a single stack
// (that is, pop () should return the same values as it would if there were just a single stack).
// FOLLOW UP
// Implement a function popAt ( int index) which performs a pop operation on a specific sub-stack
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class SetOfStacks
{
public:
    vector<stack<int>> sos;

    // current index denotes the current stack to be used fromt the array
    int currentIndex = -1;

    // ideally amount of elements should be 0 but as it is the start
    // this helps start from index 0 and minimizes code
    int threshold = 3;
    int amountOfElements = this->threshold;

    void push(int element)
    {
        stack<int> s;

        if (amountOfElements == threshold)
        {
            sos.push_back(s);
            currentIndex++;
            amountOfElements = 0;
        }

        sos[currentIndex].push(element);
        amountOfElements++;
    }

    int pop()
    {
        // if the set of stack is empty
        if (currentIndex == -1)
            return -1;

        int x = sos[currentIndex].top();
        sos[currentIndex].pop();
        amountOfElements--;

        // if the current stack is empty
        if (sos[currentIndex].empty())
        {
            currentIndex--;
            amountOfElements = threshold;
        }

        return x;
    }

    // unifinished **
    int pop_index(int index)
    {
        if (index >= sos.size() || currentIndex == -1 || index < 0)
            return -1;
        
        // there can be 2 cases either the index refers to the last stack
        // or not the last stack;

        // if the index is the last index just do normally
        if(index == sos.size() - 1)
            return pop();
        

        return 0;
    }
};

int main()
{
    SetOfStacks sos;
    sos.push(5);
    sos.push(6);
    sos.push(6);
    sos.push(7);
    sos.push(8);
    sos.push(9);
    sos.push(1);
    sos.push(2);
    sos.push(3);

    cout << "the stack is" << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << sos.pop() << endl;
    }
}