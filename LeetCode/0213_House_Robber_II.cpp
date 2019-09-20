#include <vector>
using namespace std;

class Solution
{
public:
    int pairMax(pair<int, int> p)
    {
        return p.first > p.second ? p.first : p.second;
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        pair<int, int> dp1 = make_pair(nums[0], 0);
        pair<int, int> dp2 = make_pair(nums[n - 1], 0);
        for (int i = 1, j = n - 2; i < n - 1; ++i, --j)
        {
            dp1 = make_pair(dp1.second + nums[i], pairMax(dp1));
            dp2 = make_pair(dp2.second + nums[j], pairMax(dp2));
        }
        return max(pairMax(dp1), pairMax(dp2));
    }
};