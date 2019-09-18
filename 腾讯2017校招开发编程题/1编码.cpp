#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int level[4];
    level[0] = ((25 + 1) * 25 + 1) * 25 + 1;
    level[1] = (25 + 1) * 25 + 1;
    level[2] = 25 + 1;
    level[3] = 1;

    int res = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        res += level[i] * (s[i] - 'a');
    }

    cout << res + s.size() - 1 << endl;

    return 0;
}