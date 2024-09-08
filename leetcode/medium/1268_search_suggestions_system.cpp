#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
vector<vector<string>> suggestedProducts(vector<string> &products,
                                         string searchWord)
{
    unordered_map<string, vector<string>> m;
    string key = "";
    // -----
    for (auto p : products)
    {
        key = "";

        for (auto c : p)
        {
            key += c;
            m[key].push_back(p);
        }
    }
    vector<vector<string>> result;

    key = "";
    for (auto s : searchWord)
    {
        key += s;
        if (m.find(key) == m.end())
            result.push_back({});
        else
        {
            vector<string> v = m[key];
            sort(v.begin(), v.end());
            if (v.size() > 3)
                v.resize(3);
            result.push_back(v);
        }
    }
    return result;
}