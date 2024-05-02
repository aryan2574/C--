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

// Fibonacci Number

// TOP DOWN DP
// Space - O(n)  Time - O(n)
int fibo(int n, int *dp)
{
    // Base Case
    if (n == 0 || n == 1)
        return n;

    // Recursive
    // Look up - TOP DOWN DP
    if (dp[n] != 0)
        return dp[n];

    // Recursive Case
    int subProb1 = fibo(n - 1, dp);
    int subProb2 = fibo(n - 2, dp);

    return dp[n] = (subProb1 + subProb2);
}

// BOTTOM UP DP
// Space - O(n)  Time - O(n)
int fiboBottomUp(int n, int *dp)
{
    // Initialise base case
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[n] = dp[n - 1] + dp[n - 2];
    }

    return dp[n];
}

// BOTTOM UP DP
// Space - O(1)  Time - O(n)
int fiboBottomUp2(int n)
{
    if (n < 2)
        return 1;

    int sum(0), x(0), y(1);

    for (int i = 2; i <= n; i++)
    {
        sum = (x + y);
        x = y;
        y = sum;
    }

    return sum;
}

void solve()
{
    int x;
    cin >> x;

    int dp[100] = {0};

    cout << fibo(x, dp) << nline;
    cout << fiboBottomUp(x, dp) << nline;
    cout << fiboBottomUp2(x) << nline;
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