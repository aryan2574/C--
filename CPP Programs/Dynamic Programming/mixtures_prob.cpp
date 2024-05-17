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

ll a[1000], dp2[1000][1000];

ll sum(int s, int e)
{
    ll ans(0);
    for (int i = s; i <= e; i++)
    {
        ans += a[i];
        ans %= 100;
    }
    return ans;
}

ll solveMixtures(int i, int j)
{
    // Base case - Smoke generated 0
    if (i == j)
        return 0;

    // If the answer already here
    if (dp2[i][j] != -1)
        return dp2[i][j];

    dp2[i][j] = INT_MAX;
    for (int k = i; k <= j; k++)
    {
        dp2[i][j] = min(dp2[i][j], (solveMixtures(i, k) + solveMixtures(k + 1, j) + (sum(i, k) * sum(k + 1, k))));
    }

    return dp2[i][j];
}

int minSmoke(vector<int> &mixtures)
{
    int n = mixtures.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> color(n, vector<int>(n, 0));

    // Initialize the color table
    for (int i = 0; i < n; ++i)
    {
        color[i][i] = mixtures[i];
    }

    // Fill the DP and color tables
    for (int length = 2; length <= n; ++length)
    {
        for (int i = 0; i <= n - length; ++i)
        {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k)
            {
                int q = dp[i][k] + dp[k + 1][j] + color[i][k] * color[k + 1][j];
                if (q < dp[i][j])
                {
                    dp[i][j] = q;
                    color[i][j] = (color[i][k] + color[k + 1][j]) % 100;
                }
            }
        }
    }

    return dp[0][n - 1];
}

void solve(void)
{
    int n;
    while (cin >> n)
    {
        vector<int> mixtures(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> mixtures[i];
        }
        cout << minSmoke(mixtures) << nline;
    }

    // Second Approach
    while ((scanf("%d", &n)) != EOF)
    {
        // Read N integers
        for (int i = 0; i < n; i++)
            cin >> a[i];

        // Init Dp -> -1
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                dp2[i][j] = -1;
            }
        }

        cout << solveMixtures(0, n - 1) << nline;
    }
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