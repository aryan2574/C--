#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define mod1 998244353
#define INF 1e18
#define PI 3.141592653589793238462
#define nline "\n"
#define sz(x) ((int)(x).size())
#define set_bits __builtin_popcountll
#define setp(x, y) fixed << setprecision(y) << x
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

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

// Check whether a number is a power of 2
void checkPowerOf2(int n)
{
    if (n & (n - 1))
        cout << "NO";
    else
        cout << "YES";

    cout << '\n';
}

// Print Binary digits of number n
void printBinary(int n)
{
    for (int i = 10; i >= 0; i--)
    {
        cout << ((n >> i) & 1);
    }
    cout << nline;
}

void solve()
{
    int n;
    cin >> n;

    // Print Bits
    printBinary(n);

    // Toggle all the bits
    printBinary(~n);

    // Set Bit at particular pos
    printBinary(n & (1 << 3));

    // Unset Bit a set bit at particular pos
    printBinary(n & (~(1 << 3)));

    // Toggle a bit : we can change 0 to 1 and 1 to 0 - Using XOR operator
    printBinary(n ^ (1 << 1));

    // Count of set bits  - Method 1
    int count(0);
    for (int i = 31; i >= 0; i--)
    {
        if ((n & (1 << i)) != 0)
            count++;
    }
    cout << count << nline;

    // Count of set bits  - Method 2

    count = 0;
    int temp = n;
    while (temp > 0)
    {
        if (temp & 1)
            count++;
        temp = temp >> 1;
    }
    cout << count << nline;

    // Inbuilt Method to find set bits
    // For Integer
    cout << __builtin_popcount(11) << nline;

    // For Long number
    cout << __builtin_popcountll(1ll << 35) << nline;
    cout << __builtin_popcountll((1ll << 35) - 1) << nline;

    // Check whether a number is a power of 2
    checkPowerOf2(n);
}

// _____________________________________________________________________________________
int main(void)
{
    ayush_2574_cp();
    solve();
    return 0;
}