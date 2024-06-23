#include <iostream>
#include <string>

using namespace std;


bool isOneAway(string s1, string s2);
int main()
{

    if(isOneAway("pale", "bake"))
    {
        cout << "is one away" << endl;
    }
    return 0;
}

bool isOneAway(string s1, string s2)
{
    int n1 = s1.size();
    int n2 = s2.size();

    if (n2 - n1 >= 2)
        return false;

    int i = 0;
    int j = 0;

    bool isOneEdit = false;

    while (i < n1 && j < n2)
    {
        // compare and decide if ahead or behind
        if (s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            if (isOneEdit)
                return false;

            isOneEdit = true;
            if (s1[i + 1] == s2[j])
                i++;
            else if (s1[j + 1] == s2[i])
                j++;
            else if (s1[i + 1] == s2[j + 1])
            {
                i++;
                j++;
            }
        }
    }

    if (n1 - 1 - i >= 2 || n2 - 1 - j >= 2)
        return false;

    return true;
}