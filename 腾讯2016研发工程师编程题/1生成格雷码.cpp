#include <vector>
#include <string>
using namespace std;

class GrayCode
{
public:
    vector<string> getGray(int n)
    {
        vector<string> res;
        if (n == 1)
        {
            res.push_back("0");
            res.push_back("1");
            return res;
        }

        vector<string> v = getGray(n - 1);

        for (int i = 0; i < v.size(); ++i)
            res.push_back("0" + v[i]);
        for (int i = v.size() - 1; i >= 0; --i)
            res.push_back("1" + v[i]);

        return res;
    }
};