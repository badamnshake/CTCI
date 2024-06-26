/* ------------------------------- Problem 3.2 ------------------------------ */
// Stack Min: How would you design a stack which, in addition to push and pop, has a function min
// which returns the minimum element? Push, pop and min should all operate in 0(1) time.
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class StackMin
{
    public:
    stack<pair<int, int>> s;
    int min = INT_MAX;

    void push(int x)
    {
        if (x < min)
            min = x;
        s.push({x, min});
    }

    void pop()
    {
        s.pop();
        auto x = s.top();
        min = x.second;
    }

    int get_min()
    {
        if (s.empty())
            return -1;

        return min;
    }

    void createFromVector(vector<int> arr)
    {
        for(auto i: arr)
            push(i);
    }

    void print()
    {
        while(!s.empty())
        {
            auto x = s.top();
            cout << "Val: " << x.first << " Min: " << x.second << endl;
            s.pop();
        }
        
    }

};


int main()
{
    vector<int> s = {12, 8, 9, 10, 11, 4, 5, 6, 3, 1};
    StackMin smin;
    smin.createFromVector(s);
    smin.print();


    return 0;
}
