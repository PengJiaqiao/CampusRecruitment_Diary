#include <string>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        if (s == "")
            return 0;
        int i, j;
        for (i = s.size() - 1; i >= 0; --i)
            if (s[i] != ' ')
                break;
        for (j = i - 1; j >= 0; --j)
        {
            if (s[j] == ' ')
                return i - j;
        }
        return i + 1;
    }
};