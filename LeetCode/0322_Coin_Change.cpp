#include <vector>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (coins.empty())
            return 0;

        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int coin : coins)
        {
            if (coin > amount)
                continue;
            for (int i = coin; i <= amount; ++i)
                dp[i] = dp[i - coin] == -1 ? dp[i] : dp[i] == -1 ? dp[i - coin] + 1 : min(dp[i - coin] + 1, dp[i]);
        }
        return dp[amount];
    }
};