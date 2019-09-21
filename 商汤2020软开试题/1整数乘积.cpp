// 把整数拆成至少两个数的和，在乘积最大的前提下使拆分数尽可能多
// 输出最大乘积和最大拆分数的和

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<long long int, int>> dp(n + 1, make_pair(0, 0));
    for (int i = 1; i < n; ++i)
        dp[i] = make_pair(i, 1);
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = make_pair(i, 1);
        for (int j = 1; j < i; ++j)
        {
            if (j * dp[i - j].first > dp[i].first)
            {
                dp[i].first = j * dp[i - j].first;
                dp[i].second = dp[i - j].second + 1;
            }
            else if (j * dp[i - j].first == dp[i].first)
            {
                dp[i].second = max(dp[i].second, dp[i - j].second + 1);
            }
        }
    }

    cout << dp[n].first + dp[n].second << endl;

    return 0;
}