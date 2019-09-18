#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<unsigned int> v(1025, 0);
    int id1, id2;
    cin >> id1 >> id2;

    if (id1 > 1024 || id1 < 1 || id2 > 1024 || id2 < 1)
        cout << -1 << endl;
    else
    {
        v[id1] = 1;
        cout << v[id2] << endl;
    }

    return 0;
}