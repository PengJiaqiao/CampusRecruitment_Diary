#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> coords(n, vector<int>(k));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
            cin >> coords[i][j];
    }

    double res = 0;
    vector<double> distance;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            double tmp = 0;
            for (int l = 0; l < k; ++l)
                tmp += pow(coords[i][l] - coords[j][l], 2);
            distance.push_back(tmp);
            res += sqrt(tmp);
        }
    }
    sort(distance.begin(), distance.end());
    res += (m - n * (n - 1) / 2) * distance[0];
    printf("%.3f\n", res);

    return 0;
}