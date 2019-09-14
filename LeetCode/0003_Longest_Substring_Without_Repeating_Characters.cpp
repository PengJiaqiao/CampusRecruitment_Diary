#include <string>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0)
            return 0;

        int res = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            vector<int> reached(128, 0);

            int j;
            for (j = i; j < s.size(); ++j)
            {
                int idx = s[j];
                if (reached[idx] == 1)
                    break;
                reached[idx] = 1;
            }
            res = max(res, j - i);
        }
        return res;
    }
};