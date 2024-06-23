
/* --------------------------------- problem -------------------------------- */
// String Compression: Implement a method to perform basic string compression using the counts
// of repeated characters. For example, the string aabcccccaaa would become a2blc5a3. If the
// "compressed" string would not become smaller than the original string, your method should return
// the original string. You can assume the string has only uppercase and lowercase letters (a - z).

#include <iostream>
#include <string>

using namespace std;

string compress(string s);

int main() 
{
    string compressed = compress("aabcccccaaa");

    cout << compressed << endl;

    return 0;
}

string compress(string s)
{
    string comp = "";

    char current = s[0];
    int currentCount = 1;

    for(int i = 1;  i < s.size(); i++)
    {
        if(s[i] == current)
        {
            currentCount++;
        }
        else
        {
            comp.push_back(current) ;
            comp +=  to_string(currentCount);
            current = s[i];
            currentCount = 1;
        }
    }

    comp.push_back(current);
    comp += to_string(currentCount);


    if(comp.size() < s.size())
        return comp;

    return s;

}