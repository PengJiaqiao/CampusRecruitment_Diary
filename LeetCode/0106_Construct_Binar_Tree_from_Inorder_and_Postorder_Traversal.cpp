#include <vector>
#include <unordered_map>
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.empty())
            return nullptr;
        unordered_map<int, int> M;
        for (int i = 0; i < inorder.size(); ++i)
            M[inorder[i]] = i;
        int end = inorder.size() - 1;
        return build(inorder, 0, end,
                     postorder, 0, end, M);
    }

private:
    TreeNode *build(vector<int> &inorder, int start1, int end1,
                    vector<int> &postorder, int start2, int end2,
                    unordered_map<int, int> &M)
    {
        if (start1 > end1)
            return nullptr;
        if (start1 == end1)
            return new TreeNode(inorder[start1]);
        TreeNode *root = new TreeNode(postorder[end2]);
        int rootIdx = M[postorder[end2]];
        int leftLength = rootIdx - start1;
        root->left = build(inorder, start1, rootIdx - 1,
                           postorder, start2, start2 + leftLength - 1, M);
        root->right = build(inorder, rootIdx + 1, end1,
                            postorder, start2 + leftLength, end2 - 1, M);
        return root;
    }
};