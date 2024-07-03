/* ------------------------------- Problem 8.1 ------------------------------ */
// Triple Step: A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3
// steps at a time. Implement a method to count how many possible ways the child can run up the
// stairs.

#include <vector>
#include <iostream>

using namespace std;

int chairs(int steps);
int chairsDP(int steps);

int main()
{

    for (int i = 1; i < 10; i++)
    {
        cout << "rec: " << chairs(i) << " - " << "dp: " << chairsDP(i) << endl;
    }
    return 0;
}

int chairs(int steps)
{
    if (steps == 1)
        return 1;
    if (steps == 2)
        return 2;
    if (steps == 3)
        return 4;

    return chairs(steps - 3) +
           chairs(steps - 2) + chairs(steps - 1);
}

int chairsDP(int steps)
{
    vector<int> arr = {1, 2, 4};

    if (steps <= 3)
        return arr[steps - 1];

    int sum;

    for (int i = 0; i < steps - 3; i++)
    {
        sum = arr[0] + arr[1] + arr[2];
        arr[0] = arr[1];
        arr[1] = arr[2];
        arr[2] = sum;
    }
    return arr[2];
}