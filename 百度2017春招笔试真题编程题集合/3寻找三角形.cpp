#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

struct Point
{
    int x, y, z;
    explicit Point(int _x = 0, int _y = 0, int _z = 0) : x(_x), y(_y), z(_z) {}
    void get()
    {
        scanf("%d%d%d", &x, &y, &z);
    }
    Point cross_product(const Point &b) const
    {
        return Point(y * b.z - z * b.y,
                     z * b.x - x * b.z,
                     x * b.y - y * b.x);
    }
    Point operator-(const Point &b) const
    {
        return Point(x - b.x,
                     y - b.y,
                     z - b.z);
    }
    double get_length()
    {
        return sqrt((ll)x * x + (ll)y * y + (ll)z * z);
    }
};

typedef vector<Point> vp;
typedef Point Vec;

double ans = 0.0;

void loop(vp &a, vp &b, vp &c)
{
    for (vp::iterator i = a.begin(); i != a.end(); ++i)
    {
        for (vp::iterator j = b.begin(); j != b.end(); ++j)
        {
            for (vp::iterator k = c.begin(); k != c.end(); ++k)
            {
                Vec sa = *j - *i;
                Vec sb = *k - *i;
                ans = max(ans, sa.cross_product(sb).get_length() * 0.5);
            }
        }
    }
}

vector<Point> r, g, b;

int main()
{
    int n;
    char tmp[3];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", tmp);
        Point p;
        p.get();
        if (tmp[0] == 'R')
            r.push_back(p);
        if (tmp[0] == 'G')
            g.push_back(p);
        if (tmp[0] == 'B')
            b.push_back(p);
    }
    loop(r, r, r);
    loop(g, g, g);
    loop(b, b, b);
    loop(r, g, b);
    printf("%.5f\n", ans);
    return 0;
}