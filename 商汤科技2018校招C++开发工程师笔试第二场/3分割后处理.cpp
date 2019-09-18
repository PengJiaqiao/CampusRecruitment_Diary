#include <iostream>
#include <vector>
using namespace std;

void search(vector<vector<int>> &grid, int row, int col)
{
    grid[row][col] = -1;
    if (row > 0 && grid[row - 1][col] == 0)
        search(grid, row - 1, col);
    if (row < grid.size() - 1 && grid[row + 1][col] == 0)
        search(grid, row + 1, col);
    if (col > 0 && grid[row][col - 1] == 0)
        search(grid, row, col - 1);
    if (col < grid[0].size() - 1 && grid[row][col + 1] == 0)
        search(grid, row, col + 1);
    return;
}

void search1(vector<vector<int>> &grid, int row, int col, int &res)
{
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size())
        return;
    if (grid[row][col] == 1 || grid[row][col] == 0)
    {
        grid[row][col] = -1;
        res++;
        search1(grid, row - 1, col, res);
        search1(grid, row, col + 1, res);
        search1(grid, row, col - 1, res);
        search1(grid, row + 1, col, res);
    }

    return;
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> v(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
            cin >> v[i][j];
    }

    int row_max = v.size() - 1, col_max = v[0].size() - 1;
    for (int row = 0; row <= row_max; row++)
    {
        if (v[row][0] == 0)
            search(v, row, 0);
        if (v[row][col_max] == 0)
            search(v, row, col_max);
    }
    for (int col = 1; col <= col_max; col++)
    {
        if (v[0][col] == 0)
            search(v, 0, col);
    }

    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        if (v[row_max][i] != -1)
        {
            search1(v, row_max, i, res);
            break;
        }
    }
    cout << res << endl;

    return 0;
}