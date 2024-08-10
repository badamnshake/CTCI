/* ------------------------------- Problem 8.5 ------------------------------ */
// Recursive Multiply: Write a recursive function to multiply two positive integers without using the
// *operator.You can use addition, subtraction, and bit shifting, but you should minimize the number
// of those operations

#include <vector>
#include <iostream>

using namespace std;
int recursiveMultiply(int number, int mul, int carry);

int main()
{
    cout << recursiveMultiply(8, 9,0) << endl;
    ;
    return 0;
}

int recursiveMultiply(int number, int mul, int carry)
{
    int isEven = mul & 1;
    if (isEven == 1)
    {
        number += carry;
        carry = number;
        mul--;
    }

    if (mul == 0)
        return number;

    mul = mul >> 1;
    number = number << 1;

    
    return recursiveMultiply(number, mul, carry);
}