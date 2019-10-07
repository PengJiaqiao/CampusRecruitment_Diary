#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        vector<int> bigs(k);
        for (int i = 0; i < k; ++i)
            bigs[i] = nums[i];
        make_heap(bigs.begin(), bigs.end(), greater<int>());
        for (int i = k; i < nums.size(); ++i)
        {
            if (nums[i] > bigs.front())
            {
                pop_heap(bigs.begin(), bigs.end(), greater<int>());
                bigs.pop_back();
                bigs.push_back(nums[i]);
                push_heap(bigs.begin(), bigs.end(), greater<int>());
            }
        }
        return bigs.front();
    }
};

/*
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        k = nums.size() - k;
        int l = 0, h = nums.size() - 1;
        while (l < h)
        {
            int j = partition(nums, l, h);
            if (j == k)
                break;
            else if (j < k)
                l = j + 1;
            else
                h = j - 1;
        }
        return nums[k];
    }

    void swap(int &a, int &b)
    {
        int tmp = a;
        a = b;
        b = tmp;
        return;
    }

    int partition(vector<int> &nums, int l, int h)
    {
        int i = l + 1, j = h;
        while (1)
        {
            while (i < h && nums[i] <= nums[l])
                ++i;
            while (j > l && nums[j] >= nums[l])
                --j;
            if (i >= j)
                break;
            swap(nums[i], nums[j]);
        }
        swap(nums[l], nums[j]);
        return j;
    }
};*/