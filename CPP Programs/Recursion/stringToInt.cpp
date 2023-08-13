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

// Array
vector<string> numberSpellingPairs = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

// Iterative Approach : "1234" -> one two three four
void iterativeWay(vector<string> numberSpellingPairs, string str, int len)
{
    for (size_t i = 0; i < len; i++)
    {
        int curr = str[i] - '0';
        cout << numberSpellingPairs[curr] << ' ';
    }
    cout << nline;
}

// Recursive Approach : "1234" -> one two three four
void recursiveWay(vector<string> numberSpellingPairs, int num)
{
    // Base Case
    if (num == 0)
        return;

    // Recursive Case
    recursiveWay(numberSpellingPairs, num / 10);
    cout << numberSpellingPairs[num % 10] << ' ';
}

// Convert Character to Int -  "1245" -> 1234
int charToInt(string str, int len)
{
    // base case
    if (len < 0)
        return 0;

    int digit = str[len] - '0';
    int smallAns = charToInt(str, len - 1);

    return smallAns * 10 + digit;
}

void solve()
{
    string str;
    cin >> str;
    int len = str.length();
    iterativeWay(numberSpellingPairs, str, len);

    int n;
    cin >> n;
    recursiveWay(numberSpellingPairs, n);

    string str2;
    cin >> str2;
    int len2 = str2.length();

    int ans = charToInt(str2, len2 - 1);
    cout << ans << " " << ans + 1;
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