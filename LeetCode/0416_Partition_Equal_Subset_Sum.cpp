/* https://leetcode.com/problems/partition-equal-subset-sum/description/ */

#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int num : nums)
            sum += num;

        if (sum % 2 != 0)
            return false;
        sum /= 2;

        vector<int> dp(sum + 1, 0);
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = sum; j >= nums[i]; --j)
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
        }
        return dp[sum] == sum;
    }
};