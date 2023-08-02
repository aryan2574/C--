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

// Print binary digits of decimal number n
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
    // Printing char from A to Z with their ASCII Value

    for (char c = 'A'; c <= 'Z'; ++c)
    {
        cout << c << nline;
        printBinary(int(c));
    }

    // Printing char from a to z with their ASCII Value

    for (char c = 'a'; c <= 'z'; ++c)
    {
        cout << c << nline;
        printBinary(int(c));
    }

    char A = 'A', z = 'z', Z = 'Z';

    // Converting to Lowercase
    cout << char(int(A) | (' ')) << nline;

    // Converting to uppercase
    cout << char(int(z) & int('_')) << nline;
    cout << char(int(z) & (~(1 << 5))) << nline;

    // Converting to lowercase to uppercase or vice-versa by using toggle statement -  XOR

    cout << char(int('A') ^ int(' ')) << nline;
    cout << char(int('b') ^ (1 << 5)) << nline;
}

// _____________________________________________________________________________________
int main(void)
{
    ayush_2574_cp();
    solve();
    return 0;
}