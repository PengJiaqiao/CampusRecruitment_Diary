#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> origin(n);
    vector<int> sorted(n);
    int a;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        origin[i] = a;
        sorted[i] = a;
    }

    sort(sorted.begin(), sorted.end());

    int start = 0, end = 0;
    bool flag = true;
    for (int i = 0; i < n; ++i)
    {
        if (origin[i] != sorted[i])
        {
            if (flag)
            {
                start = i;
                flag = false;
            }
            end = i;
        }
    }

    int i, j;
    for (i = start, j = end; i <= end; ++i, --j)
    {
        if (origin[i] != sorted[j])
        {
            cout << "no" << endl;
            break;
        }
    }

    if (i == end + 1)
        cout << "yes" << endl;

    return 0;
}