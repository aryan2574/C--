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

// Cell Mitosis

/*
There's a scientist named Brook who is interested in budding of cells. He has one container which initially contains
only one single cell. Now, Brook wants n number of cells in his container. So he can change the number of cells in container in 3 different ways:
1. Double the number of cells present in the container.
2. Increase the number of cells in the container by 1
3. Decrease the number of cells in the container by 1

Now, all the above operations have different costs associated with them x,y,z respectively, for above operations.
Help brook in finding the min cost to generate n cells in the container starting from one cell.


I/ p -
5
2 1 3

O/p - 4
*/

long long solveCellProblem(int n, int x, int y, int z)
{

    long long *dp = new long long[n + 1];
    // Base case
    dp[0] = 0; // To construct 0 cells we need 0 steps
    dp[1] = 0; // We already given 1 cell

    for (int i = 2; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            dp[i] = min(dp[i / 2] + x, dp[i - 1] + y);
        }

        else
        {
            dp[i] = min(dp[i - 1] + y, dp[(i + 1) / 2] + x + z);
        }
    }

    return dp[n];
}

void solve()
{
    int n, x, y, z;
    cin >> n >> x >> y >> z;

    cout << solveCellProblem(n, x, y, z);
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