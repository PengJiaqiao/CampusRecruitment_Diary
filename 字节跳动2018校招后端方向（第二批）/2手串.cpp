#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, c;
    cin >> n >> m >> c;

    vector<vector<int>> v(c + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; ++i)
    {
        int num_i;
        cin >> num_i;
        int tmp;
        for (int j = 0; j < num_i; ++j)
        {
            cin >> tmp;
            v[tmp][i] = 1;
        }
    }

    for (int i = 1; i <= c; ++i)
        v[i][n] = v[i][0];

    int res = 0;
    for (int i = 1; i <= c; ++i)
    {
        int pre = -1;
        for (int j = 0; j <= n; ++j)
        {
            if (v[i][j] == 1)
            {
                if (pre == -1)
                    pre = j;
                else
                {
                    if (j - pre < m)
                    {
                        res++;
                        break;
                    }
                    pre = j;
                }
            }
        }
    }

    cout << res << endl;

    return 0;
}