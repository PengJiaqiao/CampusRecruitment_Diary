#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> v(k);
    int x, y;
    for (int i = 0; i < k; ++i)
    {
        cin >> x >> y;
        v[i] = make_pair(x, y);
    }

    double res = (double)n / 2;
    double distance;
    for (int i = 0; i < k; ++i)
    {
        for (int j = i + 1; j < k; ++j)
        {
            distance = sqrt(pow(v[i].first - v[j].first, 2) + pow(v[i].second - v[j].second, 2)) / 2;
            res = min(res, distance);
        }
    }

    printf("%.4f", res);

    return 0;
}