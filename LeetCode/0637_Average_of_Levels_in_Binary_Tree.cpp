#include <vector>
#include <queue>
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
    vector<double> averageOfLevels(TreeNode *root)
    {
        if (root == nullptr)
            return {};

        vector<double> res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            double sum = 0;
            int n = q.size();
            for (int i = 0; i < n; ++i)
            {
                sum += q.front()->val;
                if (q.front()->left != nullptr)
                    q.push(q.front()->left);
                if (q.front()->right != nullptr)
                    q.push(q.front()->right);
                q.pop();
            }
            res.push_back(sum / n);
        }
        return res;
    }
};