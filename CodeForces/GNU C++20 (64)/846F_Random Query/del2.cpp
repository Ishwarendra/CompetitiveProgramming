#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

string collapseString(string inputString)
{
    int n = inputString.size();
    int cnt = 1;
    char ch = inputString[0];

    string ans;
    for (int i = 1; i < n; i++)
    {
        if (inputString[i] == inputString[i - 1])
            cnt++;
        else
        {
            ans += to_string(cnt) + ch;
            cnt = 1;
            ch = inputString[i];
        }
    }

    ans += to_string(cnt) + ch;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;

    print(collapseString(s))
    
    return 0;
}