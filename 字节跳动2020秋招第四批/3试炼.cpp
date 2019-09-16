#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<vector<int>> F(n, vector<int>(n, 0)); // I first
    vector<vector<int>> S(n, vector<int>(n, 0)); // I second
    for (int i = 0; i < n; ++i)
    {
        F[i][i] = a[i];
        S[i][i] = 0;
    }

    for (int dis = 1; dis < n; ++dis)
    {
        for (int i = 0; i < n - dis; ++i)
        {
            int j = i + dis;
            F[i][j] = max(S[i + 1][j] + a[i], S[i][j - 1] + a[j]);
            S[i][j] = min(F[i + 1][j], F[i][j - 1]);
        }
    }

    cout << F[0][n - 1] << endl;

    return 0;
}