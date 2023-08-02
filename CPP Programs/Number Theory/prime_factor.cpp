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

const int sze = 1e5 + 10;
int ps[sze] = {0};
vector<int> primes;

void primeSieve()
{
    // Base Case
    ps[2] = 1;
    primes.push_back(2);

    // Make all odd numbers as primes
    for (int i = 3; i < sze; i += 2)
    {
        ps[i] = 1;
    }

    // Make all non primes 0 and prime numbers will remain 1
    for (int i = 3; i < sze; i += 2)
    {
        if (ps[i])
        {
            primes.push_back(i);
            for (long long int j = i * i; j * j < sze; j += i)
            {
                ps[j] = 0;
            }
        }
    }
}

vector<pair<int, int>> factors;

// O(sqrt(N))
void calculateFactors(int n)
{
    factors.clear();

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int count(0);
            while (!(n % i))
            {
                n /= i;
                ++count;
            }
            factors.push_back(make_pair(i, count));
        }
    }
    if (n != 0 && n != 1)
        factors.push_back(make_pair(n, 1));

    for (auto p : factors)
        cout << p.first << " " << p.second << nline;
}

// O(NloglogN)
void calculateFactorsUsingSieve(int n)
{
    factors.clear();
    int itr = 0;
    int p = primes[itr];

    while (p * p <= n)
    {
        if (n % p == 0)
        {
            int count(0);
            while (!(n % p))
            {
                ++count;
                n /= p;
            }
            factors.push_back(make_pair(p, count));
        }

        ++itr;
        p = primes[itr];
    }

    if (n != 0 && n != 1)
        factors.push_back(make_pair(n, 1));

    for (auto i : factors)
        cout << i.first << ' ' << i.second << nline;
}

void solve()
{
    // Calculate Prime Sieve
    primeSieve();

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        calculateFactors(n);

        cout << nline;

        calculateFactorsUsingSieve(n);

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