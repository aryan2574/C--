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

// Euclid GCD Algorithm

// Method 1
int findGCD(int a, int b)
{
    return b == 0 ? a : findGCD(b, a % b);
}

// Method 2
int findGCD2(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    return findGCD2(b, a % b);
}

// ____________________________________________________________________________________

// Extended Euclid Algorithm : To calculate equation
// Ax + By = GCD(A,B);

int x, y, gcd;
void extendedEuclidMethod(int a, int b)
{
    // base case
    if (b == 0)
    {
        x = 1;
        y = 0;
        gcd = a;

        // To check current values
        debug(x);
        debug(y);
        debug(gcd);
        return;
    }

    // Recursive Case
    extendedEuclidMethod(b, a % b);

    int cx = y;
    int cy = x - floor(a / b) * y;

    x = cx;
    y = cy;

    // To check current values
    debug(x);
    debug(y);
}

pair<int, int> extendedEuclidMethod2(int a, int b)
{
    if (b == 0)
    {
        return {1, 0};
    }
    pair<int, int> p1 = extendedEuclidMethod2(b, a % b);
    int x2 = p1.first, y2 = p1.second;

    int x = y2, y = x2 - floor(a / b) * y2;
    return {x, y};
}

// ____________________________________________________________________________________

void solve()
{
    int a, b;
    cin >> a >> b;

    // Calculate GCD
    cout << findGCD(a, b) << nline;
    cout << findGCD2(a, b) << nline;

    // Solve Equation - 18x + 30y = 6    <- Using Extended Euclid Algorithm
    int p = 18, q = 30;
    extendedEuclidMethod(p, q);
    cout << x << ' ' << y << nline;

    pair<int, int> p1 = extendedEuclidMethod2(p, q);
    cout << p1.first << ' ' << p1.second << nline;
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