// #include "bits/stdc++.h"

// #ifdef LOCAL
// #include "F:\CPP\Debug\debug.h" 
// #else
// #define print(...) 1;
// #endif

// using i64 = long long;

// void solve()
// {
//     std::string s;
//     i64 pos;
//     std::cin >> s >> pos;
//     pos--;

//     std::stack<int> st;
//     st.push(0);
//     int n = std::size(s);
//     auto sz = n;

//     std::vector<int> rem(n + 1);

//     int i = 1;
//     s += 'a' - 1;
//     while (pos >= n)
//     {
//         if (i <= sz)
//         {
//             if (!st.empty() and s[i] < s[st.top()])
//             {
//                 rem[st.top()]++;
//                 st.pop();
//                 pos -= n;
//                 n--;
//             }
//             else
//                 st.push(i++);
//         }
//         else
//         {
//             assert(!st.empty());
//             rem[st.top()]++;
//             st.pop();
//             pos -= n;
//             n--;
//         }
//     }

//     std::vector<int> zero;
//     for (int i = 0; i < sz; i++)
//     {
//         if (!rem[i])
//             zero.emplace_back(i);
//     }

//     std::cout << s[zero[pos]];
// }

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);

//     int t;
//     std::cin >> t;
    
//     while (t--)
//         solve();
    
//     return 0;
// }

#include "bits/stdc++.h"

class A1 {
    public: 
        int upper;
        int lower;
        A1(int i) : lower(i), upper(lower + 1){

        }
};

class A {
public:
    A(){}
};

void foo()
{
    throw new A;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    return 0;
}