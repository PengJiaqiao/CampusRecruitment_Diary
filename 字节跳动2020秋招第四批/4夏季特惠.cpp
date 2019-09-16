// 可以转化为背包问题，但是物品体积可能为负
// 最终也只AC 40%，很遗憾
// 参考答案： http://m.nowcoder.com/discuss/259976

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> v(n);
    vector<int> w(n);
    int offset = 0;
    int a, b;
    long long int res = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b >> w[i];
        v[i] = 2 * b - a;
        if (v[i] < 0)
        {
            offset -= v[i];
            res += w[i];
            w[i] = 0;
        }
    }

    vector<long long int> dp(x + 1 + offset, 0);
    for (int i = 0; i < n; ++i)
    {
        for (int j = x + offset; j >= v[i]; --j)
        {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    cout << res + dp[x] << endl;

    return 0;
}