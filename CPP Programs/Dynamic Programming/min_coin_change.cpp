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

// Function to calculate the minimum number of coins needed to make the sum `n` using top-down DP
int minCoinChangeTopDown(int n, int *coins, int m, int *dp)
{
    if (n == 0)
        return 0; // Base case: If n is 0, no coins are needed.

    if (dp[n] != -1)
        return dp[n]; // Return already computed result

    int result = INT_MAX; // Initialize the result with a large number.

    for (int i = 0; i < m; i++)
    {
        if (coins[i] <= n)
        {
            int sub_prob = minCoinChangeTopDown(n - coins[i], coins, m, dp);
            if (sub_prob != INT_MAX)
            {
                result = min(result, sub_prob + 1);
            }
        }
    }

    dp[n] = result; // Store the result in dp array
    return dp[n];
}

// Function to calculate the minimum number of coins needed to make the sum `n` using bottom-up DP
int minCoinChangeBottomUp(int n, int *coins, int m, int *dp)
{
    dp[0] = 0; // Base Case: 0 coins needed to make sum 0

    for (int i = 1; i <= n; i++)
    {
        int res = INT_MAX;
        for (int j = 0; j < m; j++)
        {
            if (coins[j] <= i)
            {
                int sub_res = dp[i - coins[j]];
                if (sub_res != INT_MAX)
                {
                    res = min(res, sub_res + 1);
                }
            }
        }
        dp[i] = res; // Fill the dp array with the minimum coins needed for each i
    }

    return dp[n];
}

void solve()
{
    int coins[] = {1, 3, 4, 5};               // Coin denominations
    int m = sizeof(coins) / sizeof(coins[0]); // Number of different coins

    int n;
    cin >> n; // The sum we want to form

    int dp_top_down[n + 1];                     // Create DP array with size n+1 for top-down approach
    fill(dp_top_down, dp_top_down + n + 1, -1); // Initialize with -1 for memoization

    int dp_bottom_up[n + 1];                           // Create DP array with size n+1 for bottom-up approach
    fill(dp_bottom_up, dp_bottom_up + n + 1, INT_MAX); // Initialize with INT_MAX for comparison

    int minCoins1 = minCoinChangeTopDown(n, coins, m, dp_top_down);
    int minCoins2 = minCoinChangeBottomUp(n, coins, m, dp_bottom_up);

    cout << "Minimum coins required (Top-Down): " << minCoins1 << endl;
    cout << "Minimum coins required (Bottom-Up): " << minCoins2 << endl;
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