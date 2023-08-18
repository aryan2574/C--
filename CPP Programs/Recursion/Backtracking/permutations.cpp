#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define mod1 998244353
#define INF 1e18
#define PI 3.141592653589793238462
#define nline "\n"

#define sz(x) ((int)(x).size())
#define set_bits __builtin_popcount
#define set_bitsll __builtin_popcountll
#define setp(x, y) fixed << setprecision(y) << x

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define scnfi(n) scanf("%d", &n)
#define scnfii(n, m) scanf("%d%d", &n, &m)
#define scnfl(n) scanf("%I64d", &n)
#define scnfll(n, m) scanf("%lld%lld", &n, &m)
#define scnfstr(str) scanf("%s", &str);

#define prntfi(n) printf("%d\n", n)
#define prntfii(n, m) printf("%d %d\n", n, m)
#define prntfl(n) printf("%I64d\n", n)
#define prntfll(n, m) printf("%I64d %I64d\n", n, m)
#define prntfstr(s) printf("%s\n", s)

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t)
{
    cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

void ayush_2574_cp()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}

// ____________________________________________________________________________________

// void findPermutations(string str, char *out, int i, int j)
// {
//     // Base Case
//     if (str[i] == '\0')
//     {
//         out[j] = '\0';
//         cout << out << nline;
//         return;
//     }

//     // Recursive Case
//     for (int k = i; str[k] != '\0'; k++)
//     {
//         // Swap i and k pos
//         swap(str[i], str[k]);
//         out[j] = str[i];
//         debug(str);
//         findPermutations(str, out, i + 1, j + 1);
//     }

//     return;
// }

// Find all permutations
// Idea : Swap elements in the array : Call recursion at each step
// Backtrack : To keep orignal array as it is after each step
void permute(char *in, int i)
{
    // Base Case
    if (in[i] == '\0')
    {
        cout << in << nline;
        return;
    }

    // Recursive Case
    for (int j = i; in[j] != '\0'; j++)
    {
        swap(in[i], in[j]);
        permute(in, i + 1);

        // Backtracing - To restore the original array
        swap(in[i], in[j]);
    }
}

void solve()
{
    // string str;
    // cin >> str;
    // int len = str.length();
    // char out[len + 10];
    // findPermutations(str, out, 0, 0);

    char in[100];
    cin >> in;

    permute(in, 0);
}

// _____________________________________________________________________________________

signed main(void)
{
    auto t1 = std::chrono::high_resolution_clock::now();
    ayush_2574_cp();
    solve();
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
    // cout << "Time : " << duration.count() << " ms" << endl;
    debug(duration.count());
    return 0;
}