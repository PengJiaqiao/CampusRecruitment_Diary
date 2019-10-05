#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        if (k <= 0)
            return num;

        if (num.size() == 0 || k >= num.size())
            return "0";

        int digits = num.size() - k; // 输出字符串的长度
        vector<char> v(num.size());  // 模拟桟
        int top = 0;                 // 记录栈顶元素的下一个位置

        for (int i = 0; i < num.size(); i++)
        { // 遍历所有元素
            char c = num[i];
            while (top > 0 && v[top - 1] > c && k > 0)
            { // 如果当前元素比栈顶元素小，则出栈
                --top;
                --k;
            }
            v[top++] = c; // 将当前元素压桟
        }
        // 从头开始查找头个不为0的元素位置
        int idx = 0;
        while (idx < digits && v[idx] == '0')
            ++idx;

        if (idx == digits)
            return "0";
        else
        {
            string str(v.begin() + idx, v.begin() + digits);
            return str;
        }
    }
};