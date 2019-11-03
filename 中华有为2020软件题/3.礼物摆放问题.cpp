#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;

    stack<pair<int, vector<string>>> stack;
    vector<pair<int, string>> res;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '[')
        {
            vector<string> v;
            v.push_back("");
            stack.push(make_pair(stack.size(), v));
        }
        else if (s[i] == ',')
            stack.top().second.push_back("");
        else if (s[i] == ']')
        {
            vector<string> &v = stack.top().second;
            string res_ = "[";
            for (string s_ : v)
            {
                if (s_ != "")
                {
                    if (res_.size() > 1)
                        res_ += ",";
                    res_ += s_;
                }
            }
            res_ += "]";
            res.push_back(make_pair(stack.top().first, res_));
            stack.pop();
        }
        else
        {
            vector<string> &v = stack.top().second;
            v[v.size() - 1] += s[i];
        }
    }
    sort(res.begin(), res.end(), [](pair<int, string> a, pair<int, string> b) { return a.first > b.first; });
    int level = res[0].first;
    cout << res[0].second;
    for (int i = 1; i < res.size(); ++i)
    {
        if (res[i].first == level)
            cout << ",";
        else
            cout << endl;
        cout << res[i].second;
    }

    return 0;
}