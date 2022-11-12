// ਹਰਅਸੀਸ ਸਿੰਘ

#include<bits/stdc++.h>
using namespace std;

int query(int i, string q, int j = -1){
    if(j == -1) j = i + 1;
    cout << q << ' ' << i << ' ' << j << "\n";

    int t; cin >> t; 

    return t;
}
void slv(){
        // 1, 11, 100
        // find element number 1 and 3

        // element 1 is ([1] or [2]) - (([1] or [2]) and ([2] or [3])) + [1] and [2]

        int n, k; cin >> n >> k; 

        vector<int> f(n);

        int i = 1;

        int OR1 = query(i, "or");

        int OR2 = query(i + 1, "or");

        int AND1 = query(i, "and");

        int AND2 = query(i + 1, "and");

        f[i - 1] = OR1 + AND1 - ((OR1 & OR2) - query(i, "and", i + 2) + (AND1 & AND2));

        f[i + 1] = OR2 + AND2 - ((OR1 & OR2) - query(i, "and", i + 2) + (AND1 & AND2));

        for(int i = 3; i < n; i++){
            f[i] = query(i, "or") - f[i - 1] + query(i, "and");
        }
        f[1] = OR1 - f[0] + AND1;

        sort(f.begin(), f.end());

        cout << "finish " << f[k - 1] << endl;

        return;
}

int32_t main(){
        
        slv();        
        return 0;
}