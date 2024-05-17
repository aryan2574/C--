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

// Link - https://www.codechef.com/problems/CD1IT4/

vector<vector<int>> dp;

int countPaths(int m, int n)
{
    // If the start or end is blocked, there's no path
    if (dp[0][0] == -1 || dp[m - 1][n - 1] == -1)
    {
        return 0;
    }

    dp[0][0] = 1;

    // Initialize the first row
    for (int col = 1; col < n; ++col)
    {
        if (dp[0][col] == -1)
        {
            dp[0][col] = 0; // No path through this cell
        }
        else
        {
            dp[0][col] = dp[0][col - 1];
        }
    }

    // Initialize the first column
    for (int row = 1; row < m; ++row)
    {
        if (dp[row][0] == -1)
        {
            dp[row][0] = 0; // No path through this cell
        }
        else
        {
            dp[row][0] = dp[row - 1][0];
        }
    }

    // Fill the dp array for the rest of the grid
    for (int row = 1; row < m; ++row)
    {
        for (int col = 1; col < n; ++col)
        {
            if (dp[row][col] == -1)
            {
                dp[row][col] = 0; // No path through this cell
            }
            else
            {
                dp[row][col] = (dp[row - 1][col] + dp[row][col - 1]) % mod;
            }
        }
    }

    return dp[m - 1][n - 1];
}

void solve()
{
    int m, n, p;
    cin >> m >> n >> p;

    dp.assign(m, vector<int>(n, 0));

    // Set blocked cells to -1
    for (int i = 0; i < p; ++i)
    {
        int x, y;
        cin >> x >> y;
        dp[x - 1][y - 1] = -1;
    }

    cout << countPaths(m, n) << endl;
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