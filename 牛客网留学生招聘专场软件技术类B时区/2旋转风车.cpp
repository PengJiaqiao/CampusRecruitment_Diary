#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;

    set<unsigned long long int> s;
    while (n--)
    {
        unsigned long long int a;
        cin >> a;
        s.insert(a);
    }

    auto iter = s.begin();
    if (*iter == 1)
        cout << "Impossible" << endl;
    else if (*iter > 2)
        cout << 1 << " " << 2 << endl;
    else
    {
        unsigned long long int second = 3;
        while (iter != s.end())
        {
            if (*iter < second)
            {
                ++iter;
            }
            else if (*iter == second)
            {
                ++iter;
                second += 2;
            }
            else
            {
                auto iter_ = s.begin();
                while (iter_ != iter)
                {
                    if (second % *iter_ == 0)
                    {
                        break;
                    }
                    ++iter_;
                }
                if (iter_ != iter)
                {
                    ++iter;
                    second += 2;
                }
                else
                {
                    break;
                }
            }
        }
        cout << 1 << " " << second << endl;
    }

    return 0;
}