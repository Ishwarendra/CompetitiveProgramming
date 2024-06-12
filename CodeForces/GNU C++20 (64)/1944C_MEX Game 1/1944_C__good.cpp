/* जय  महाकाल */

#include "bits/stdc++.h"
using namespace std ;  
#define endl '\n'
#define ll long long 
const long long mx1 = 1e9 ; 
const long long Mod = 1e9 + 7 ; 

long long getpow(int a , int b) //Calculating a ^ b in 0(log(b)) - Binary Expo.
{
    int res = 1;
    while(b > 0)
    {
        if((b & 1)==1)
        {
            res *= a ;
            res %= Mod;
        }
        b>>=1;
        a*=a;
        a%=Mod;
    }
    return res ;
}

void show2(map<int,int>& mt)
{
    for(auto& i : mt)
    {
        cout << "[ ";
        cout << i.first << ',' << i.second << ' ';
        cout << "]" << endl ;
    }
}

void show1(vector<int>& x)
{
    cout << "[ ";
    for(auto& i : x)
    {
        cout << i << ' ';
    }
    cout << "]";
    cout << endl ;
}


 /* -------------------------M A I N __ C O D E --------------------------------------*/

/* ------- LEARNING ALSO OCCURS THROUGH SEEING OTHER'S SOLUTION -------- */

/* ------- EVERY PROBLEM WHETHER EASY OR TOUGH TEACHES YOU SOMETHING -- SO ENJOY LEARNING -------- */

/* -------- Do Problem Analysis as much as Possible else u will surely get WA on some TCs ------ */

void test_case()
{
    // take a walk if stuck
    int n ; cin >> n ;
    vector<int> a(n) , mp(n) ;
    
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        mp[a[i]]++ ;
        mp[a[i]] = min(2 , mp[a[i]]);
    }
    
    int MEX = -1 ; int cnt =1 ;
    
    for(int i = 0 ; i < n ; i++){
        /* if odd then alice turn else bob's turn */
        if(mp[i] == 0){
            MEX = i ;
            break ;
        }
        
        if(i + 1 < n && mp[i + 1] > 1){
            cnt++ ;
            continue ;
        }else if(i + 1 < n && mp[i + 1] <= 1){
            cnt++ ;
            if(!(cnt % 2)){
                MEX = i + 1;
                //cout << "THIS => " << MEX << endl;
                break ;
            }
        }
    }
    
    cout << ((MEX == -1) ? n : MEX) << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    
    cin.tie(0); cout.tie(0);
    
    /* WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
    * IF STUCK ON A QUESTION, MOVE TO THE NEXT ONE
    */

    int t ; cin >> t ; 
    
    while(t--)
    {
        test_case();
    }
    
    return 0 ; 
}