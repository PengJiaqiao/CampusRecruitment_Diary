#include <vector>
#include <limits.h>
using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int m = triangle.size();
        vector<vector<int>> dp = triangle;
        for (int i = 1; i < m; ++i)
            dp[i][0] += dp[i - 1][0];
        for (int i = 1; i < m; ++i)
            dp[i][i] += dp[i - 1][i - 1];
        for (int i = 2; i < m; ++i)
        {
            for (int j = 1; j < i; ++j)
                dp[i][j] += min(dp[i - 1][j - 1], dp[i - 1][j]);
        }
        int res = dp[--m][0];
        for (int i = 1; i <= m; ++i)
            res = min(res, dp[m][i]);
        return res;
    }
};