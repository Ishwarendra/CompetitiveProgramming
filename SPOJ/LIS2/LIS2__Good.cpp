// 2009-08-18
#include <bits/stdc++.h>
using namespace std;
int in()
{
    int x;
    std::cin >> x;
    return x;
}
#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(x...) 1;
#endif
struct NiceDay
{
    map<int,int> M;
    bool find(int x,int y)
    {
        map<int,int>::iterator lb=M.lower_bound(x);
        if (lb==M.begin())
            return false;
        lb--;
        if (lb->second<y)
            return true;
        else
            return false;
    }
    void add(int x,int y)
    {
        map<int,int>::iterator lb=M.lower_bound(x),i2;
        i2=lb;
        while (i2!=M.end()&&i2->second>=y)
            i2++;
        M.erase(lb,i2);
        M.insert(pair<int,int>(x,y));
    }
};
int main()
{
    static NiceDay a[100010];
    int L=1,N,i,x,y;
    N=in();
    x=in();
    y=in();
    a[1].add(x,y);
    for (i=0; i<N-1; i++)
    {
        x=in();
        y=in();
        int l=0;
        int u=L;
        int m=0;
        while (u>l)
        {
            m=(l+u+1)/2;
            if (a[m].find(x,y))
                l=m;
            else
                u=m-1;
        }
        if (L<=l)
            L=l+1;
        a[l+1].add(x,y);
        // print(a[l+1].M,x,y)
    }
    printf("%d\n",L);
    return 0;
}