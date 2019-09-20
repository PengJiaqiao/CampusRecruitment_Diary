#include <iostream>
#include <string>
using namespace std;

/* bool solution(int n, string &s)
{
    if (n < 11)
        return false;
    int i;
    for (i = 0; i < n; ++i)
    {
        if (s[i] == '8')
            break;
    }
    if (n - i >= 11)
        return true;
    else
        return false;
} */

bool solution(int n, string &s)
{
    if (n < 11)
        return false;
    for (int i = 0, j = n - 11; i <= j; ++i, --j)
    {
        if (s[i] == '8' || s[j] == '8')
            return true;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        if (solution(n, s))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}