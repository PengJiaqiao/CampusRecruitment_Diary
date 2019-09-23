#include <iostream>
#include <set>
using namespace std;

int main()
{
    int N;
    cin >> N;

    set<int> s;
    int price;
    while (N--)
    {
        cin >> price;
        s.insert(price);
    }

    if (s.size() < 3)
        cout << -1 << endl;
    else
    {
        auto iter = ++s.begin();
        ++iter;
        cout << *iter << endl;
    }

    return 0;
}