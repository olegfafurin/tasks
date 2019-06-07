//
// Created by imd on 10/28/2018.
//
#include <bits/stdc++.h>
using namespace std;
struct point
{
    long double x;
    long double y;
};

long double d(point a, point b)
{
    return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
long double sq(point a, point b, point c)
{
    return ((a.x - b.x) * (a.y - c.y) - (a.x - c.x) * (a.y - b.y));
}
int check (point a, point b, point c, point d)
{
    long double a1, b1, c1, a2, b2, c2;
    point ans;
    a1 = a.y - b.y;
    b1 = b.x - a.x;
    c1 = a1 * a.x + b1 * a.y;
    a2 = c.y - d.y;
    b2 = d.x - c.x;
    c2 = a2 * c.x + b2 * c.y;
    b2 = b2 * a1 - b1 * a2;
    c2 = c2 * a1 - c1 * a2;
    if (a1 == 0 && a2 == 0 && b.y != c.y)
        return 0;
    if (b2 == 0 && c2 == 0)
        return -1;
    if (b2 == 0 && c2 != 0)
        return 0;
    return 1;
}
point li (point a, point b, point c, point d)
{
    long double a1, b1, c1, a2, b2, c2;
    point ans;
    a1 = a.y - b.y;
    b1 = b.x - a.x;
    c1 = a1 * a.x + b1 * a.y;
    a2 = c.y - d.y;
    b2 = d.x - c.x;
    c2 = a2 * c.x + b2 * c.y;
    b2 = b2 * a1 - b1 * a2;
    c2 = c2 * a1 - c1 * a2;
    ans.y = c2 / b2;
    a1 = a.y - b.y;
    b1 = b.x - a.x;
    c1 = a1 * a.x + b1 * a.y;
    a2 = c.y - d.y;
    b2 = d.x - c.x;
    c2 = a2 * c.x + b2 * c.y;
    a1 = a2 * b1 - a1 * b2;
    c1 = c2 * b1 - c1 * b2;
    ans.x = c1 / a1;
    return ans;
}
bool check1 (point a, point b, point c)
{
    return((sq(a, b, c) == 0) && (min(a.x, b.x) <= c.x) && (max(a.x, b.x) >= c.x)  && (min(a.y, b.y) <= c.y) && (max(a.y, b.y) >= c.y));
}
int main()
{
    freopen("segments.in", "r", stdin);
    freopen("segments.out", "w", stdout);
    int n, i, f;
    long double x1, y1, d1, d2, a1, b1, c1, a2, b2, c2, x2, y2, x, y;
    point p, q, r, t;
    point v[100];
    for (i = 0; i < 4; ++i)
    {
        cin >> x >> y;
        p.x = x;
        p.y = y;
        v[i] = p;
    }
    if (d(v[0], v[1]) == 0 && d(v[2], v[3]) == 0)
        if (d(v[0], v[2]) == 0)
        {
            p = v[0];
            cout << fixed << setprecision(10) << p.x << " " << p.y;
            return 0;
        }
        else
        {
            cout << "Empty";
            return 0;
        }
    if (d(v[0], v[1]) == 0)
        if (check1(v[2], v[3], v[0]))
        {
            p = v[0];
            cout << fixed << setprecision(10) << p.x << " " << p.y;
            return 0;
        }
        else
        {
            cout << "Empty";
            return 0;
        }
    if (d(v[2], v[3]) == 0)
        if (check1(v[1], v[0], v[2]))
        {
            p = v[2];
            cout << fixed << setprecision(10) << p.x << " " << p.y;
            return 0;
        }
        else
        {
            cout << "Empty";
            return 0;
        }
    f = check (v[0], v[1], v[2], v[3]);
    if (f == 1)
    {
        p = li(v[0], v[1], v[2], v[3]);
        if (check1(v[0], v[1], p) && check1(v[2], v[3], p))
        {
            cout << fixed << setprecision(10) << p.x << " " << p.y;
            return 0;
        }
        else
        {
            cout << "Empty";
            return 0;
        }
    }
    if (f == 0)
    {
        cout << "Empty";
        return 0;
    }
    x1 = min( max(v[0].x, v[1].x), max(v[2].x, v[3].x));
    y1 = min( max(v[0].y, v[1].y), max(v[2].y, v[3].y));
    x2 = max( min(v[0].x, v[1].x), min(v[2].x, v[3].x));
    y2 = max( min(v[0].y, v[1].y), min(v[2].y, v[3].y));
    if (x1 < x2)
        swap(x1, x2);
    if (y1 < y2)
        swap(y1, y2);
    if (x1 == x2 && y1 == y2)
    {
        cout << x2 << " " << y2;
        return 0;
    }
    p.x = x1;
    p.y = y1;
    q.x = x2;
    q.y = y2;
    if (check1(v[0], v[1], p) && check1(v[2], v[3], p) && check1(v[0], v[1], q) && check1(v[2], v[3], q))
    {
        cout << x2 << " " << y2 << endl;
        cout << x1 << " " << y1;
        return 0;
    }
    p.x = x1;
    p.y = y2;
    q.x = x2;
    q.y = y1;
    if (check1(v[0], v[1], p) && check1(v[2], v[3], p) && check1(v[0], v[1], q) && check1(v[2], v[3], q))
    {
        cout << x2 << " " << y1 << endl;
        cout << x1 << " " << y2;
        return 0;
    }
    cout << "Empty";
    return 0;
}
