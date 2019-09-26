#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> at(n);
    int a, t;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> t;
        at[i] = make_pair(a, t);
    }

    sort(at.begin(), at.end(), [](pair<int, int> a, pair<int, int> b) { return a.first > b.first; });
    long long int sum = 0;
    long long int v = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += at[i].second * (2 * v + at[i].first * at[i].second);
        v += at[i].first * at[i].second;
    }
    long double res = sum / 2.0;
    printf("%.1Lf\n", res);

    return 0;
}