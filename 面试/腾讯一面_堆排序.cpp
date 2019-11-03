#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> heapSort(vector<int> &nums)
    {
        for (int i = nums.size() / 2; i >= 0; --i)
            heap_build(nums, i, nums.size - 1);
        for (int i = nums.size() - 1; i > 0;)
        {
            swap(nums[0], nums[i]);
            heap_build(nums, 0, --i);
        }
    }
    void heap_build(vector<int> &nums, int root, int end)
    {
        int l = 2 * root + 1;
        if (l < end)
        {
            int r = l + 1;
            int largeChild = l;
            if (r < end)
                largeChild = nums[r] > nums[l] ? r : l;
            if (nums[root] < nums[largeChild])
            {
                swap(nums[root], nums[largeChild]);
                heap_build(nums, largeChild, end);
            }
        }
        return;
    }
    void swap(int &a, int &b)
    {
        int tmp = a;
        a = b;
        b = tmp;
        return;
    }
};