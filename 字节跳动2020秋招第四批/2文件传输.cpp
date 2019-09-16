#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    int t, c;
    for (int i = 0; i < n; ++i)
    {
        cin >> t >> c;
        v[i] = make_pair(t, c);
    }

    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) { return a.first < b.first; });

    long long int sum = v[0].second;
    long long int Max = sum;
    for (int i = 1; i < n; ++i)
    {
        sum -= v[i].first - v[i - 1].first;
        sum += v[i].second;
        Max = max(Max, sum);
    }

    cout << v[n - 1].first + sum << " " << Max << endl;

    return 0;
}