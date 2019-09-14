#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    while (N--)
    {
        int M;
        cin >> M;

        int res = 0;
        vector<vector<pair<int, int>>> v(100, vector<pair<int, int>>(100, make_pair(0, 0)));
        for (int i = 1; i <= M; ++i)
        {
            int k;
            cin >> k;
            for (int j = 0; j < k; ++j)
            {
                int x, y;
                cin >> x >> y;
                if (v[x][y].first == 0)
                {
                    v[x][y].first = i;
                    v[x][y].second = i;
                    continue;
                }
                else
                {
                    if (v[x][y].second == i - 1)
                    {
                        v[x][y].second = i;
                        res = max(res, v[x][y].second - v[x][y].first);
                    }
                    else
                    {
                        v[x][y].first = i;
                        v[x][y].second = i;
                    }
                }
            }
        }

        res++;
        cout << res << endl;
    }

    return 0;
}