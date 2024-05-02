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

// Calculate minimum steps to reach 1
int minStepsTopDown(int n, int *dp)
{
    // Base Case
    if (n == 1)
        return 0;

    // Lookup condition
    if (dp[n] != 0)
    {
        return dp[n];
    }

    // Recursive Case
    int op1, op2, op3;
    op1 = op2 = op3 = INT_MAX;

    if (n % 3 == 0)
    {
        op1 = minStepsTopDown(n / 3, dp) + 1;
    }
    if (n % 2 == 0)
    {
        op2 = minStepsTopDown(n / 2, dp) + 1;
    }
    op3 = minStepsTopDown(n - 1, dp) + 1;

    int ans = min(min(op1, op2), op3);
    return dp[n] = ans;
}

int minStepsBottomUp(int n, int *dp)
{
    // Base case
    dp[0] = dp[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        int op1, op2, op3 = INT_MAX;
        if (i % 3 == 0)
        {
            op1 = dp[i / 3];
        }
        if (i % 2 == 0)
        {
            op2 = dp[i / 2];
        }
        op3 = dp[i - 1];

        dp[i] = min(min(op1, op2), op3) + 1;
    }

    return dp[n];
}

void solve()
{
    int x;
    cin >> x;

    int dp_top_down[100] = {0};  // Separate array for top-down approach
    int dp_bottom_up[100] = {0}; // Separate array for bottom-up approach

    cout << minStepsTopDown(x, dp_top_down) << nline;

    cout << minStepsBottomUp(x, dp_bottom_up) << nline;
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