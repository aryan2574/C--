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

// Link - https://www.geeksforgeeks.org/gcd-of-two-numbers-when-one-of-them-can-be-very-large-2/
// INPUT : 1221
//         1234567891011121314151617181920212223242526272829

ll findGCD(ll a, ll b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    return findGCD(b, a % b);
}

ll reduceB(ll a, string b)
{
    // Idea
    // Step 1 : Break 'a' into different terms eg. 1211 -> 1 * 10^3 + 2 * 10^2 + 1 * 10^1 + 1 * 10^0
    // Step 2 : Take mod by 'b' as we know mod is a distributive. Take mod in each step
    // Step 3 : Return ans

    // Initialize result
    ll m = 0;

    // calculating mod of b with a to make b : 0 <= b < a
    for (int i = 0; i < b.length(); i++)
        m = ((m * 10) + (b[i] - '0')) % a;

    return m; // return modulo
}

ll findGCDLargeNumbers(ll a, string b)
{
    ll num = reduceB(a, b);

    return findGCD(a, num);
}

void solve()
{
    ll a;
    string b;
    cin >> a >> b;

    if (a == 0)
        cout << b;
    else
        cout << findGCDLargeNumbers(a, b) << nline;
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