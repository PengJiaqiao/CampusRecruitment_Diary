// 动态规划求路径
// 只能往下或者往右，可能存在棋子堵塞路线，将其置零
// 不知道为什么还是只有90%

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;

    vector<vector<long long int>> dp(M + 1, vector<long long int>(N + 1, 1));
    int i, j;
    while (cin >> i >> j)
    {
        dp[i][j] = 0;
    }

    for (int i = 0; i < N + 1; ++i)
    {
        if (dp[0][i] == 0)
        {
            for (int j = i + 1; j < N + 1; ++j)
                dp[0][j] = 0;
            break;
        }
    }

    for (int i = 1; i < M + 1; ++i)
    {
        if (dp[i][0] == 0)
        {
            for (int j = i + 1; j < M + 1; ++j)
                dp[j][0] = 0;
            break;
        }
    }

    for (int i = 1; i < M + 1; ++i)
    {
        for (int j = 1; j < N + 1; ++j)
        {
            if (dp[i][j] == 0)
                continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    cout << dp[M][N] << endl;

    return 0;
}