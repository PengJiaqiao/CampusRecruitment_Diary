// 数组分成两半且大小差小于等于1，要求各自的和接近，由小到大输出各自和
// AC 60%

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        vector<int> x(n + 1, 0);
        int sum = 0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> x[i];
            sum += x[i];
        }

        vector<vector<int>> dp(n / 2 + 1, vector<int>(sum / 2 + 1, 0));

        for (int i = 1; i <= n; ++i)
        {
            for (int j = min(i, n / 2); j >= 1; --j)
            {
                for (int s = sum / 2; s >= x[i]; --s)
                {
                    dp[j][s] = max(dp[j - 1][s - x[i]] + x[i], dp[j][s]);
                }
            }
        }

        cout << dp[n / 2][sum / 2] << " " << sum - dp[n / 2][sum / 2] << endl;
    }

    return 0;
}