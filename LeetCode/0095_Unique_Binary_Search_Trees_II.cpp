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
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return {};
        return solution(n, 0);
    }

private:
    vector<TreeNode *> solution(int n, int k)
    {
        if (n == 0)
            return {nullptr};
        if (n == 1)
        {
            TreeNode *node = new TreeNode(1 + k);
            return {node};
        }

        vector<TreeNode *> res;
        for (int i = 1; i <= n; ++i)
        {
            vector<TreeNode *> left = solution(i - 1, k);
            vector<TreeNode *> right = solution(n - i, k + i);
            for (TreeNode *l : left)
            {
                for (TreeNode *r : right)
                {
                    TreeNode *node = new TreeNode(i + k);
                    node->left = l;
                    node->right = r;
                    res.push_back(node);
                }
            }
        }
        return res;
    }
};