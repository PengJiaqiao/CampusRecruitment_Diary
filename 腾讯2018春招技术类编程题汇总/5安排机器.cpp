#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> zw(n);
    int z, w;
    for (int i = 0; i < n; ++i)
    {
        cin >> z >> w;
        zw[i] = make_pair(z, w);
    }

    vector<pair<int, int>> xy(m);
    int x, y;
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y;
        xy[i] = make_pair(x, y);
    }

    sort(zw.begin(), zw.end(), [](pair<int, int> a, pair<int, int> b) { 
    if(a.first == b.first)return a.second > b.second;
    else return a.first > b.first; });

    sort(xy.begin(), xy.end(), [](pair<int, int> a, pair<int, int> b) { 
    if(a.first == b.first)return a.second > b.second;
    else return a.first > b.first; });

    int res1 = 0;
    long long int res2 = 0;
    int j = 0;
    unordered_map<int, int> M;
    for (int i = 0; i < m; ++i)
    {
        while (j < n && zw[j].first >= xy[i].first)
        {
            if (M.find(zw[j].second) == M.end())
                M[zw[j].second] = 1;
            else
                M[zw[j].second]++;
            j++;
        }

        for (int j = xy[i].second; j <= 100; ++j)
        {
            if (M.find(j) != M.end())
            {
                if (M[j] > 0)
                {
                    M[j]--;
                    res1++;
                    res2 += 200 * xy[i].first + 3 * xy[i].second;
                    break;
                }
            }
        }
    }

    cout << res1 << " " << res2 << endl;

    return 0;
}