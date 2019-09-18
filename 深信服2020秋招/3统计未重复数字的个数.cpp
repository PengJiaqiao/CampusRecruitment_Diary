#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    unordered_map<int, int> M;
    while (cin >> n)
    {
        if (M.find(n) == M.end())
            M[n] = 1;
        else
            M[n]++;
    }

    int res = 0;
    for (auto m : M)
        res = m.second > 1 ? res : res + 1;

    cout << res << endl;

    return 0;
}
