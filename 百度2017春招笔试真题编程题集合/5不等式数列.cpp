#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 1; i <= n; ++i)
        dp[i][0] = 1;
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 1; j <= min(k, i - 1); ++j)
        {
            dp[i][j] = (dp[i - 1][j - 1] * (i - j) + dp[i - 1][j] * (j + 1)) % 2017;
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}