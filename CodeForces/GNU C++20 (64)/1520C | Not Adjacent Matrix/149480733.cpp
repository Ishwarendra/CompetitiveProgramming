#include<bits/stdc++.h>
#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<string>
#include <iterator>
#include <map>
#include<math.h>
#include<stack>
#include<queue>
#include<unordered_map>
#include <cstring>
#include<string.h>
 
using namespace std;
 
#define pb     push_back
#define nn     endl
#define pll    pair<int,int>
#define ll     long long int
#define vll    vector<int>
#define all(a) (a).begin(),(a).end()
//#define x       first
#define y      second
#define sz(x)  (int)x.size()
#define hell   1000000007
#define lbnd   lower_bound
#define ubnd   upper_bound
#define bs     binary_search
#define mi     map<int,int>
#define gcd(a,b)  __gcd((a),(b))
#define lcm(a,b)  ((a)*(b)) / gcd((a),(b))
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
 
 
 
void solve()
{
    ll n;
    cin>>n;
    vector<ll> v;
    for(ll i=0;i<(n*n);i++)
    {
        if(i%2==0)
        {
            v.push_back(i+1);
        }
        
        
    }
    for(ll i=0;i<(n*n);i++)
    {
        if(i%2!=0)
        {
            v.push_back(i+1);
        }
        
        
    }
    ll vs = v.size();
    ll ad=0;
    if(n==1)
    {
        cout<<"1"<<nn;
    }
    else if(n==2)
    {
        cout<<"-1"<<nn;
    }
    else{
        for(ll i=0;i<vs;i++)
        {
            ad++;
            cout<<v[i] << ' ';
            if(ad==n)
            {
                cout<<nn;
                ad=0;
            }
        }
    }
}
 
 
int main()
 
{
    fio
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    
}