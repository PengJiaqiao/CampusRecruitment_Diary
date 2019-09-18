#include <iostream>
#include <vector>
using namespace std;

int res = 0;

void dfs(vector<vector<char>> &v, int i, int j, char c)
{
    if (i >= v.size() || j >= v[0].size())
        return;
    if (v[i][j] == 'X')
        return;
    if (c == 'Y')
    {
        if (v[i][j] == 'Y')
        {
            v[i][j] = 'X';
            dfs(v, i + 1, j + 1, c);
        }
        else if (v[i][j] == 'G')
        {
            v[i][j] = 'B';
            dfs(v, i + 1, j + 1, c);
        }
        else
            return;
    }
    if (c == 'B')
    {
        if (v[i][j] == 'B')
        {
            v[i][j] = 'X';
            dfs(v, i + 1, j - 1, c);
        }
        else if (v[i][j] == 'G')
        {
            v[i][j] = 'Y';
            dfs(v, i + 1, j - 1, c);
        }
        else
            return;
    }
    if (c == 'G')
    {
        v[i][j] = 'X';
        res++;
        dfs(v, i + 1, j + 1, 'Y');
        dfs(v, i + 1, j - 1, 'B');
    }

    return;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> v(n, vector<char>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (v[i][j] != 'X')
            {
                dfs(v, i, j, v[i][j]);
                res++;
            }
        }
    }

    cout << res << endl;

    return 0;
}