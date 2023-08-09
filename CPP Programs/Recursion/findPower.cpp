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

// Calculate power of a number
int findPowerRecursion(int n, int pow)
{
    // Base Case
    if (pow == 0)
    {
        return 1;
    }

    // Recursive Case
    int subProb = n * findPowerRecursion(n, pow - 1);

    return subProb;
}

// Find power - a^n  - O(n)
ll calcPower(int a, int n)
{
    // Base case
    if (n == 0)
        return 1;

    // Recursive Case
    int subProb = a * calcPower(a, n - 1);
    return subProb;
}

// Calculate power using Binary Exponentiation
int findPowerRecursionFast(int n, int pow)
{
    // Base Case
    if (pow == 0)
    {
        return 1;
    }

    // Recursive Case
    int subProb = findPowerRecursion(n, pow / 2);
    if (pow % 2 == 0)
    {
        return subProb * subProb;
    }
    else
    {
        return n * subProb * subProb;
    }
}

// Fast method - using Binary Exponentiation
int mulNumbersRecursionFast(int n, int t)
{
    // Base Case
    if (t == 1)
    {
        return n;
    }

    // Recursive Case
    int subProb = mulNumbersRecursionFast(n, t / 2);
    if (t % 2 == 0)
    {
        return subProb + subProb;
    }
    else
    {
        return n + subProb + subProb;
    }
}

// Fast power function - exponentiation by squaring - Calculate - a^n - O(logn)
ll calcPowerFast(int a, int n)
{
    // Base Case
    if (n == 0)
        return 1;

    // Recursive case
    int subProb = calcPower(a, n / 2);

    // If n is odd - a * a^n/2 * a^n/2
    if (n & 1)
        return a * subProb * subProb;

    // else n is even
    return subProb * subProb;
}

// Multiply two numbers without using -> * <- operator : Add a number t times to itself
int mulNumbersRecursion(int n, int t)
{
    // Base Case
    if (t == 1)
        return n;

    // Recursive Case
    int subProb = n + mulNumbersRecursion(n, t - 1);

    return subProb;
}

void solve()
{
    int n, pow;
    cin >> n >> pow;

    cout << mulNumbersRecursion(n, pow) << nline;
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