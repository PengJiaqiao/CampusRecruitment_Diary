#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void dfs(vector<vector<int>> &v, vector<bool> &reached, int init,
         int from, int past, int cost, int &res)
{
    if (past == reached.size())
    {
        res = min(res, cost + v[from][init]);
        return;
    }
    for (int i = 0; i < reached.size(); ++i)
    {
        if (reached[i] == false)
        {
            reached[i] = true;
            dfs(v, reached, init, i, past + 1, cost + v[from][i], res);
            reached[i] = false;
        }
    }
    return;
}

int solution(vector<vector<int>> &v, vector<bool> &reached)
{
    int res = 1000 * v.size();
    reached[0] = true;
    dfs(v, reached, 0, 0, 1, 0, res);
    
    return res;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cin >> v[i][j];
    }

    vector<bool> reached(n, false);
    cout << solution(v, reached) << endl;

    return 0;
}