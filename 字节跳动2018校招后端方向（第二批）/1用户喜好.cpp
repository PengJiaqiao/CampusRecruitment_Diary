/* https://www.nowcoder.com/test/question/66b68750cf63406ca1db25d4ad6febbf?pid=8537209&tid=27553936 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> v[i];

    int q;
    cin >> q;
    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        l = l < 0 ? 0 : l;
        r = r > n ? n : r;

        int res = 0;
        for (int i = l; i <= r; ++i)
        {
            if (v[i] == k)
                res++;
        }
        cout << res << endl;
    }

    return 0;
}