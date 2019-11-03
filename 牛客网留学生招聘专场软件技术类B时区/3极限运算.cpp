#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];

    int idx_a = 0, idx_b = 0;
    while (idx_a < n && a[idx_a] == 0)
        ++idx_a;
    while (idx_b < m && b[idx_b] == 0)
        ++idx_b;

    if (idx_a == n)
    {
        printf("0/1\n");
    }
    else if (idx_b == m)
    {
        if (a[idx_a] < 0)
            printf("-1/0\n");
        else
            printf("1/0\n");
    }
    else
    {
        if (n - idx_a > m - idx_b)
        {
            if (a[idx_a] * b[idx_b] < 0)
                printf("-1/0\n");
            else
                printf("1/0\n");
        }
        else if (n - idx_a < m - idx_b)
        {
            printf("0/1\n");
        }

        else
        {
            if (a[idx_a] * b[idx_b] < 0)
                printf("-%d/%d\n", abs(a[idx_a]), abs(b[idx_b]));
            else
                printf("%d/%d\n", a[idx_a], b[idx_b]);
        }
    }

    return 0;
}