#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// To execute C++, please define "int main()"

// The TestCase is shown below
// Input : 1 2
// Output : 3

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        unordered_map<string, pair<int, int>> M;
        for (int i = 0; i < n; ++i)
        {
            string name;
            int score;
            cin >> name >> score;
            if (M.find(name) == M.end)
                M[name] = make_pair(score, i);
            else
            {
                M[name].first += score;
                M[name].second = i;
            }
        }
        vector<pair<string, int>> v;
        for (auto m : M)
            v.push_back(make_pair(m.first, m.second.first));
        if (v.size() == 1)
        {
            cout << v[0].first << endl;
            continue;
        }
        sort(v.begin(), v.end(), [](pair<string, int> a, pair<string, int> b) { return a.second > b.second; });
        if (v[0].second > v[1].second)
            cout << v[0].first << endl;
        else
        {
            vector<pair<string, int>> v1;
            v1.push_back(make_pair(v[0].first, M[v[0].first].second));
            for (int i = 1; i < v.size(); ++i)
            {
                if (v[i].second == v[0].second)
                    v1.push_back(make_pair(v[i].first, M[v[i].first].second));
                else
                    break;
            }
            sort(v1.begin(), v1.end(), [](pair<string, int> a, pair<string, int> b) { return a.second < b.second; });
            cout << v1[0].first << endl;
        }
    }
    return 0;
}