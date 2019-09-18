#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s;
    cin >> s;

    vector<int> v(26, 0);
    int res = -1;
    for (char c : s)
    {
        int idx = (int)c - 'a';
        if (idx < 0)
            idx = (int)c - 'A';
        v[idx]++;
        if (v[idx] == 3)
        {
            res = idx;
            break;
        }
    }

    cout << res + 1 << endl;

    return 0;
}
