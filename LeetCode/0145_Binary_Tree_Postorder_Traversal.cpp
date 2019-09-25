#include <vector>
#include <stack>
#include <algorithm>
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
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
            return {};

        vector<int> res;
        stack<TreeNode *> s;
        s.push(root);
        TreeNode *node;

        while (!s.empty())
        {
            node = s.top();
            s.pop();
            res.push_back(node->val);

            if (node->left != nullptr)
                s.push(node->left);
            if (node->right != nullptr)
                s.push(node->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};