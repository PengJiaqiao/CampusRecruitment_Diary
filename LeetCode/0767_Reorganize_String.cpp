#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string reorganizeString(string S)
    {
        if (S.size() == 0)
            return "";
        vector<pair<int, char>> v(26);
        for (int i = 0; i < 26; ++i)
            v[i] = make_pair(0, 'a' + i);
        for (char c : S)
            ++v[c - 'a'].first;
        sort(v.begin(), v.end(), [](pair<int, char> a, pair<int, char> b) { return a.first > b.first; });
        int sum = 0;
        for (int i = 1; i < 26; ++i)
            sum += v[i].first;
        if (v[0].first - 1 > sum)
            return "";
        string res = "";
        res.push_back(v[0].second);
        vector<string> s(v[0].first, res);
        for (int i = 0, j = 1; i < sum; ++i)
        {
            if (v[j].first == 0)
                ++j;
            s[i % v[0].first].push_back(v[j].second);
            --v[j].first;
        }
        res = "";
        for (string s_ : s)
            res += s_;

        return res;
    }
};