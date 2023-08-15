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

// Generate all strings with String mapping
// Eg- 1234
// O/p - 1234 = ABCD   | 1(23)4 = AWD | (12)34 = LCD

// Idea : Take one digit at a time, store it into output and call recursion on remaining part
// Take two digit at a time, check for condition if we can take two digit or not and call for recursion for remaining part.

void generate_strings(char *inp, char *out, int i, int j)
{
    // Base Case
    if (inp[i] == '\0')
    {
        out[j] = '\0';
        cout << out << nline;
        return;
    }

    // Recursive Case
    // Pick one digit at a time
    int firstDigit = inp[i] - '0';
    if (firstDigit != 0)
    {
        char ch = firstDigit + 'A' - 1;
        out[j] = ch;
        generate_strings(inp, out, i + 1, j + 1);
    }

    // Pick two digit at a time
    // Check the next digit is not null
    if (inp[i + 1] != '\0')
    {
        int secondDigit = inp[i + 1] - '0';
        secondDigit += firstDigit * 10;
        if (secondDigit <= 26)
        {
            char ch = secondDigit + 'A' - 1;
            out[j] = ch;
            generate_strings(inp, out, i + 2, j + 1);
        }
    }
    return;
}

void solve()
{
    char inp[10], out[100];
    cin >> inp;

    generate_strings(inp, out, 0, 0);
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