#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(5));
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i][0] >> v[i][1] >> v[i][2] >> v[i][3] >> v[i][4];
    }

    double res = 0;
    for (int i = 0; i < n; ++i)
    {
        double tmp;
        tmp = pow(abs(v[i][0] - v[i][2]), 2) + pow(abs(v[i][1] - v[i][3]), 2);
        tmp /= pow(v[i][4], 2);
        res = max(res, tmp);
    }

    res = sqrt(res);
    printf("%.3f", res);

    return 0;
}