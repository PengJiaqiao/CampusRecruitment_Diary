#include <iostream>
#include <string>
#include <vector>
using namespace std;

int numOfDecodings(string s)
{
    int len = s.size();
    if (!len || s[0] == '0')
        return 0;

    vector<int> nums(len, 0);
    nums[0] = 1;
    if (s[1] == '0' && s[0] <= '2')
        nums[1] = 1;
    else if (s[0] == '1' || (s[0] == '2' && s[1] <= '6'))
        nums[1] = 2;
    else if (s[1] == 0)
        nums[1] = 0;
    else
        nums[1] = 1;

    for (int i = 2; i < len; ++i)
    {
        if (s[i] == '0' && s[i - 1] <= '2' && s[i - 1] > '0')
            nums[i] = nums[i - 2];
        else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))
            nums[i] = nums[i - 1] + nums[i - 2];
        else if (s[i] == '0')
            nums[i] = 0;
        else
            nums[i] = nums[i - 1];
    }

    return nums[len - 1];
}

int main(void)
{
    string s;
    cin >> s;
    cout << numOfDecodings(s) << endl;
    return 0;
}