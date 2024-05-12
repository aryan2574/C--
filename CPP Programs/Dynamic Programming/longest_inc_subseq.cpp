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

// Time - O(N^2)
int longestIncSubseq(int *arr, int n, int *dp)
{
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1; // Every element can end with length 1
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int lis(0);
    for (int i = 0; i < n; i++)
    {
        // cout << dp[i] << " ";
        lis = max(lis, dp[i]);
    }

    return lis;
}

// Time - O(N^2)
int longestIncSubseq2(int *arr, int n, int *dp)
{
    dp[0] = INT_MIN;
    for (int i = 1; i <= n; i++)
        dp[i] = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        for (int len = 0; len < n; len++)
        {
            if (dp[len] < arr[i] && arr[i] < dp[len + 1])
            {
                dp[len + 1] = arr[i];
            }
        }
    }

    int lis(0);
    for (int i = 1; i < n; i++)
    {
        if (dp[i] != INT_MAX)
        {
            lis = i;
        }
    }

    return lis;
}

int longestIncSubseq3(int *arr, int n, int *dp)
{
    dp[0] = INT_MIN;
    for (int i = 1; i <= n; i++)
        dp[i] = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        int len = upper_bound(dp, dp + n + 1, arr[i]) - dp;
        if (dp[len - 1] < arr[i] && arr[i] < dp[len])
        {
            dp[len] = arr[i];
        }
    }

    int lis(0);
    for (int i = 1; i < n; i++)
    {
        if (dp[i] != INT_MAX)
        {
            lis = i;
        }
    }

    return lis;
}

void solve()
{
    int n = 8;
    int arr[n] = {1, 5, 2, 3, 4, 9, 6, 10};

    int dp[n], dp2[n + 1], dp3[n + 1];

    cout << longestIncSubseq(arr, n, dp) << nline;
    cout << longestIncSubseq2(arr, n, dp2) << nline;
    cout << longestIncSubseq3(arr, n, dp3) << nline;
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