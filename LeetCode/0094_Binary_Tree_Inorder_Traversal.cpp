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
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        vector<int> res;
        stack<TreeNode *> s;
        TreeNode *node = root;
        while (node || !s.empty())
        {
            while (node)
            {

                s.push(node);
                node = node->left;
            }
            node = s.top();
            s.pop();
            res.push_back(node->val);
            node = node->right;
        }
        return res;
    }
};