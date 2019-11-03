#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;

    bool err = false;
    long long int res = 0;
    if (s[0] == '0')
    {
        for (int i = s.size() - 1, j = 0; i > 0; --i, ++j)
        {
            int num = s[i] - '0';
            if (num >= 8 || num < 0)
            {
                err = true;
                break;
            }
            res += num * pow(8, j);
        }
    }
    else if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
    {
        for (int i = s.size() - 1, j = 0; i > 1; --i, ++j)
        {
            int num;
            if (s[i] - '0' >= 0 && s[i] - '0' <= 9)
                num = s[i] - '0';
            else if (s[i] - 'a' >= 0 && s[i] - 'a' <= 5)
                num = s[i] - 'a' + 10;
            else
            {
                err = true;
                break;
            }
            res += num * pow(16, j);
        }
    }
    else if (s[1] == '#' || s[2] == '#')
    {
        int splitIdx = s[1] == '#' ? 1 : 2;
        int base = stoi(s.substr(0, splitIdx));
        for (int i = s.size() - 1, j = 0; i > splitIdx; --i, ++j)
        {
            int num;
            if (s[i] - '0' >= 0 && s[i] - '0' <= 9)
                num = s[i] - '0';
            else if (s[i] - 'a' >= 0 && s[i] - 'a' <= 25)
                num = s[i] - 'a' + 10;
            else if (s[i] - 'A' >= 0 && s[i] - 'A' <= 25)
                num = s[i] - 'A' + 36;
            else if (s[i] == '@')
                num = 62;
            else if (s[i] == '_')
                num = 63;
            else
            {
                err = true;
                break;
            }
            if(num >= base) {
                err = true;
                break;
            }
            res += num * pow(base, j);
        }
    }
    else
    {
        for (int i = s.size() - 1, j = 0; i >= 0; --i, ++j)
        {
            int num = s[i] - '0';
            if (num >= 10 || num < 0)
            {
                err = true;
                break;
            }
            res += num * pow(10, j);
        }
    }

    if (err)
        cout << "ERROR" << endl;
    else
        cout << res << endl;

    return 0;
}