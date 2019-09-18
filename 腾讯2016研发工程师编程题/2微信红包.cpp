#include <vector>
#include <unordered_map>
using namespace std;

class Gift
{
public:
    int getValue(vector<int> gifts, int n)
    {
        unordered_map<int, int> M;
        for (int i = 0; i < n; ++i)
        {
            if (M.find(gifts[i]) == M.end())
                M[gifts[i]] = 1;
            else
                M[gifts[i]]++;
        }

        int threshold = n / 2;
        for (auto m : M)
        {
            if (m.second > threshold)
                return m.first;
        }
        return 0;
    }
};