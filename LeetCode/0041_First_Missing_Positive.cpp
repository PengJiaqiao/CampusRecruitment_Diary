#include <vector>
#include <bitset>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        bitset<10000> b;
        for (int num : nums)
        {
            if (num < 0 || num > nums.size())
                continue;
            bitset<10000> a;
            a[0] = 1;
            b |= a << num;
        }
        for (int i = 1; i <= nums.size(); ++i)
        {
            if (b[i] == 0)
                return i;
        }
        return nums.size() + 1;
    }
};