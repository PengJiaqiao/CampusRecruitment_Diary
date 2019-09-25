#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        vector<int> nums;
        while (head != nullptr)
        {
            nums.push_back(head->val);
            head = head->next;
        }
        return sortedArrayToBST(nums);
    }

private:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return toBST(nums, 0, nums.size() - 1);
    }

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