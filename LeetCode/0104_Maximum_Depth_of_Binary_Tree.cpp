/* https://leetcode.com/problems/maximum-depth-of-binary-tree/ */

#include <vector>
#include <math.h>
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
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        return max(maxDepth(left), maxDepth(right)) + 1;
    }
};