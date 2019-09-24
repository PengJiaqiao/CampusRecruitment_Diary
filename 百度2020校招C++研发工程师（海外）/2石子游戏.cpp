#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        if (n == 1)
        {
            if (a[0] % 2 == 0)
                cout << "woman" << endl;
            else
                cout << "man" << endl;
            continue;
        }

        sort(a.begin(), a.end());
        if (a[0] == 0 && a[1] == 0)
        {
            cout << "woman" << endl;
            continue;
        }

        int i;
        for (i = 1; i < n; ++i)
        {
            if (a[i] == a[i - 1])
            {
                cout << "woman" << endl;
                break;
            }
        }
        if (i < n)
            continue;

        int sum1 = 0, sum2 = 0;
        for (i = 0; i < n; ++i)
        {
            sum1 += a[i];
            sum2 += i;
        }

        if ((sum1 - sum2) % 2 == 0)
            cout << "woman" << endl;
        else
            cout << "man" << endl;
    }

    return 0;
}