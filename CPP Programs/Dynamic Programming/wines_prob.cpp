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

int winesProblem(vector<int> prices, int yr, int l, int r, vector<vector<int>> &dp)
{
    // Base Case
    if (l > r)
        return 0;

    // If the value is already computed, return it
    if (dp[l][r] != -1)
        return dp[l][r];

    // Calculate the profit if we sell the leftmost wine
    int sellLeft = prices[l] * yr + winesProblem(prices, yr + 1, l + 1, r, dp);

    // Calculate the profit if we sell the rightmost wine
    int sellRight = prices[r] * yr + winesProblem(prices, yr + 1, l, r - 1, dp);

    // Store the maximum profit for the current range
    return dp[l][r] = max(sellLeft, sellRight);
}

void printSellOrder(vector<int> prices, int yr, int l, int r, vector<vector<int>> &dp)
{
    if (l > r)
        return;

    int sellLeft = prices[l] * yr + dp[l + 1][r];
    int sellRight = prices[r] * yr + dp[l][r - 1];

    if (sellLeft > sellRight)
    {
        cout << "beg ";
        printSellOrder(prices, yr + 1, l + 1, r, dp);
    }
    else
    {
        cout << "end ";
        printSellOrder(prices, yr + 1, l, r - 1, dp);
    }
}

void solve()
{
    vector<int> prices = {2, 3, 5, 1, 4};
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    int maxProfit = winesProblem(prices, 1, 0, n - 1, dp);
    cout << maxProfit << endl;

    printSellOrder(prices, 1, 0, n - 1, dp);
    cout << endl;
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