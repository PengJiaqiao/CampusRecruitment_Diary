#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    int x, y;
    for (int i = 0; i < n; ++i)
    {
        cin >> x >> y;
        v[i] = make_pair(x, y);
    }

    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) { return a.second > b.second; });

    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        if (v[i].first == 0)
            continue;
        for (int j = n - 1; j >= 0; --j)
        {
            if (v[j].first == 0)
                continue;
            if (v[j].first < v[i].first)
            {

                v[i].first -= v[j].first;
                v[j].first = 0;
            }
            else
            {
                v[j].first -= v[i].first;
                v[i].first = 0;
                res = max(res, v[i].second + v[j].second);
                break;
            }
        }
    }
    cout << res << endl;

    return 0;
}