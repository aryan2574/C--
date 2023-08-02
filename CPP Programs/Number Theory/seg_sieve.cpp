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

// I/P : 2 1 10 3 5
// O/P :  2 3 5 7  3 5

const int SIZE = 1e5 + 10;
vector<bool> primeSieve(SIZE, true);
vector<int> primes;

void createPrimeSieve()
{
    primeSieve[0] = false;
    primeSieve[1] = false;

    for (int i = 2; i < SIZE; ++i)
    {
        if (primeSieve[i] == true)
        {
            primes.push_back(i);
            for (ll currNum = i * ll(i); currNum < SIZE; currNum += i)
            {
                primeSieve[currNum] = false;
            }
        }
    }
}

void solve()
{
    createPrimeSieve();

    int t;
    cin >> t;
    while (t--)
    {
        ll m, n;
        cin >> m >> n;

        bool segmented_sieve[n - m + 1];

        for (int i = 0; i < n - m + 1; i++)
        {
            segmented_sieve[i] = true;
        }

        for (auto x : primes)
        {
            // If square of prime is greater than our number
            if (x * x > n)
                break;

            // We want to make false our multiple of primes in the segment sieve
            int start = (m / x) * x;

            // Special Case
            if (x >= m && x <= n)
                start = x * 2;

            for (int i = start; i <= n; i += x)
            {
                segmented_sieve[i - m] = false;
            }
        }

        for (ll i = m; i <= n; i++)
        {
            if (segmented_sieve[i - m] && i != 1)
                cout << i << nline;
        }

        cout << nline;
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