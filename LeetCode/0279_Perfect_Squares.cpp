#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, n);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j <= sqrt(i); ++j)
                dp[i] = min(dp[i - j * j] + 1, dp[i]);
        }

        return dp[n];
    }
};