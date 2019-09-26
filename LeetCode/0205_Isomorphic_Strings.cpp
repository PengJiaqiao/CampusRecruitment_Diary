#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        vector<int> sPre(128, -1);
        vector<int> tPre(128, -1);
        int sIdx, tIdx;
        for (int i = 0; i < s.size(); ++i)
        {
            sIdx = s[i];
            tIdx = t[i];
            if (sPre[sIdx] != tPre[tIdx])
                return false;
            sPre[sIdx] = i;
            tPre[tIdx] = i;
        }
        return true;
    }
};