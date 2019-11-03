#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, xc, yc, r;
    cin >> n >> xc >> yc >> r;

    int r_ = r * r;
    vector<vector<bool>> v(n + 1, vector<bool>(n + 1, false));
    for (int i = max(0, yc - r); i < min(n + 1, yc + r); ++i)
    {
        for (int j = max(0, xc - r); j < min(n + 1, xc + r); ++j)
        {
            if (pow(abs(i - yc), 2) + pow(abs(j - xc), 2) < r_)
                v[i][j] = true;
        }
    }

    vector<int> res;
    for (int i = 0; i < n * n; ++i)
    {
        int row = i / n;
        int col = i % n;
        bool leftDown = v[row][col];
        bool leftUp = v[row + 1][col];
        bool rightDown = v[row][col + 1];
        bool rightUp = v[row + 1][col + 1];
        if ((leftDown || leftUp || rightDown || rightUp) &&
            !(leftDown && leftUp && rightDown && rightUp))
            res.push_back(i + 1);
    }
    if (res.size() != 0)
    {
        cout << res[0];
        for (int i = 1; i < res.size(); ++i)
            cout << " " << res[i];
    }
    else
        cout << -1 << endl;

    return 0;
}