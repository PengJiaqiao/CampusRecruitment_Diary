#include <vector>
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        if (nums.size() == 0)
            return -1;
        int sum = 0;
        for (int num : nums)
            sum += num;
        int preSum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (preSum * 2 + nums[i] == sum)
                return i;
            preSum += nums[i];
        }
        return -1;
    }
};