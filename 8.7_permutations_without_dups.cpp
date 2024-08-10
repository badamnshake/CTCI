/* ------------------------------- Problem 8.7 ------------------------------ */
// Permutations without Dups: Write a method to compute all permutations of a string of unique
// characters.

#include <iostream>
#include <vector>

using namespace std;

string p = "abcd";

vector<string> getperms(string question);
vector<string> getpermsR(string question, vector<string> &result);

int main()
{
    auto r = getperms(p);
    vector<string> result;
    auto y = getpermsR(p, result);
    for (auto x : r)
        cout << x << endl;

    for (auto x : y)
        cout << x << endl;

    return 0;
}

vector<string> getperms(string question)
{
    int curr = 0;
    vector<string> result;

    string x;
    x.push_back(question[curr]);
    result.push_back(x);
    curr++;

    string temp = "";

    while (curr < question.size())
    {
        int n = result.size();
        for (int i = 0; i < n; i++)
        {

            temp = result[i];

            for (int j = 0; j < temp.size(); j++)
            {
                temp.insert(temp.begin() + j, question[curr]);
                result.push_back(temp);
                temp = result[i];
            }
            temp.push_back(question[curr]);
            result.push_back(temp);
        }
        for (int i = 0; i < n; i++)
            result.erase(result.begin());
        curr++;
    }
    return result;
}

// yet to implement
vector<string> getpermsR(string question, vector<string> &result)
{


    int n = result.size();

    if(n == 0)
        result.push_back("a");
    n++;

    string temp;

    for (int i = 0; i < question.size(); i++)
    {
        temp = question;
        for (int j = 0; j < n; j++)
        {
            result[j].push_back(question[i]);
            temp.erase(temp.begin() + i);
            getpermsR(temp, result);
        }
    }
    return result;
}