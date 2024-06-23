#include <string>
#include <iostream>

using namespace std;

bool isStringRotation(string s1, string s2);

bool isRotation(string s1, string s2);

int main()
{
    if (isRotation("creepcorncake", "cakecreepcorn"))
    {
        cout << "substring found" << endl;
    }
    else
    {
        cout << "substring not found" << endl;
    }

    return 0;
}

// s1 is the string and s2 is the rotated one
bool isStringRotation(string s1, string s2)
{
    

    int n = s2.size();

    if(n != s1.size())
        return false;

    int p = 0;

    int i = 0;
    int occurence = n;
    int finalPos = n;

    while (i < n)
    {
        if (s2[i] == s1[p])
        {

            occurence = i;

            while (i < n && s2[i] == s1[p])
            {
                i++;
                p++;
            };

            if (i == n)
                finalPos = occurence;
            else
                p = 0;
        }
        else
        {
            i++;
        }
    }
    cout << finalPos << endl;

    if (finalPos != n && s1.find(s2.substr(0, finalPos)) != string::npos)
        return true;
    return false;
}


// the solution in the book
// s1 is xy and s2 is yx
// in this case yx will always be substring of xyxy
bool isRotation(string s1, string s2)
{
    if(s1.size() == s2.size() && s1.size() > 0)
    {
        string s1s1 = s1 + s1;
        return s1s1.find(s2) != string::npos;
    }
    return false;

}