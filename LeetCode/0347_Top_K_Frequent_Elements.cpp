/* https://leetcode.com/problems/top-k-frequent-elements/ */

#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> M;
        vector<int> res;
        for (int num : nums)
            M[num]++;
        for (auto m : M)
            res.push_back(m.first);
        sort(res.begin(), res.end(), [&M](int a, int b) { return M[a] > M[b]; });
        return vector<int>(res.begin(), res.begin() + k);
    }
};