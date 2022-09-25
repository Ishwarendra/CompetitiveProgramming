#include <bits/stdc++.h>
 
#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif
 
using i64 =  long long;
 
template <typename T>
bool between(T x, T l, T r)
{
    // returns true if x lie between l and r, false otherwise
    return (x >= std::min(l, r) and x <= std::max(l, r));
}
 
template <typename T>
struct Rect
{
    T bl_x, bl_y, tr_x, tr_y;
 
    friend std::istream& operator >>(std::istream &is, Rect &r)
    {
        is >> r.bl_x >> r.bl_y >> r.tr_x >> r.tr_y;
        return is;
    }
 
    T area()
    {
        return (tr_x - bl_x) * (tr_y - bl_y);
    }
 
    T intersection_area(Rect &r)
    {
        T l = std::max(T(0), std::min(tr_x, r.tr_x) - std::max(bl_x, r.bl_x));
        T w = std::max(T(0), std::min(tr_y, r.tr_y) - std::max(bl_y, r.bl_y));
 
        return l * w;
    }
 
    bool inside(T x, T y)
    {
        // return true if point (x, y) lie inside rectangle r, false otherwise
        return between(x, bl_x, tr_x) and between(y, bl_y, tr_y);
    }
};
 
template <typename T = i64>
i64 intersection_area(Rect<T> &a, Rect<T> &b, Rect<T> &c)
{
    T l = std::max(T(0), std::min({a.tr_x, b.tr_x, c.tr_x}) - std::max({a.bl_x, b.bl_x, c.bl_x}));
    T w = std::max(T(0), std::min({a.tr_y, b.tr_y, c.tr_y}) - std::max({a.bl_y, b.bl_y, c.bl_y}));
 
    return l * w;
}
 
void solve()
{
    Rect<i64> a, b, c;
    std::cin >> a >> b >> c;
 
    i64 area = a.area() - a.intersection_area(b) - a.intersection_area(c);    
    area += intersection_area(a, b, c);
 
    // print(a.area(), a.intersection_area(b), a.intersection_area(c), intersection_area(a, b, c));
    print(a.area(), (a.tr_x - a.bl_x), (a.tr_y - a.bl_y))
 
    if (area == 0)
        std::cout << "NO\n";
    else
        std::cout << "YES\n";
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int t = 1;
 
    while (t--)
        solve();
 
    return 0;
}