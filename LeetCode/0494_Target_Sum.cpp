// sum(positive) - sum(negative) = target
// 2 * sum(P) = target + sum(nums)

#include <vector>
using namespace std;

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int S)
    {
        int sum = 0;
        for (int num : nums)
            sum += num;

        if (sum > S)
            return 0;

        S = S + sum;
        if (S % 2)
            return 0;

        S /= 2;
        vector<int> dp(S + 1, 0);
        dp[0] = 1;
        for (int num : nums)
        {
            for (int i = S; i >= num; --i)
            {
                dp[i] = dp[i] + dp[i - num];
            }
        }
        return dp[S];
    }
};
