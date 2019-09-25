#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.size() == 0)
            return nullptr;
        return toBST(nums, 0, nums.size() - 1);
    }

private:
    TreeNode *toBST(vector<int> &nums, int start, int end)
    {
        if (start > end)
            return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = toBST(nums, start, mid - 1);
        root->right = toBST(nums, mid + 1, end);
        return root;
    }
};