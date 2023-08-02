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
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}

// ____________________________________________________________________________________

// Large Input : 100000014383                               | Output : YES Prime

const int SIZE = (int)1e6 + 10;

bitset<SIZE> arr;

void primeS()
{
    // Special Case
    arr.set();

    arr[0] = 0;
    arr[1] = 0;

    for (int i = 2; i < SIZE; ++i)
    {
        if (arr[i])
        {
            for (ll currNum = i * (ll)i; currNum < SIZE; currNum += i)
            {
                arr[currNum] = 0;
            }
        }
    }
}

void solve()
{
    primeS();

    ll n;
    cin >> n;

    if (n < SIZE) // Calculating Prime Number using Prime Sieve
    {
        cout << (arr[n] ? "YES" : "NO") << nline;
    }

    else
    {

        // If Number is larger than our prime sieve range than calculate using for loop

        bool flag = true;

        for (int i = 2; i < sqrt(n); ++i)
        {
            if (n % i == 0)
            {
                flag = false;
                break;
            }
        }

        cout << (flag ? "YES" : "NO") << nline;
    }
}

// _____________________________________________________________________________________

signed main(void)
{
    ayush_2574_cp();
    solve();
    return 0;
}