    #include <vector>
    #include<stack>
    using namespace std;
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<pair<int, int>> s;
        int t;

        for (int i = temperatures.size() - 1; i >= 0; i--)
        {
            t = pop_monotonic(temperatures[i], i, s);

            if (t != -1)
                ans[i] = t - i;
        }
        return ans;
    }

    int pop_monotonic(int val, int index, stack<pair<int, int>> &s)
    {
        int ans = -1;

        while (!s.empty() && s.top().first <= val)
            s.pop();

        if (!s.empty())
            ans = s.top().second;
        s.push(make_pair(val, index));
        return ans;
    }