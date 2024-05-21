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

void solve()
{
    int n;
    cin >> n;

    vector<int> p(n + 1);
    vector<int> b(n + 1);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        p[x] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> b[i];
        p[b[i]] = i;
    }

    // check if we can make it without pushing 0
    if (p[1] != 0) // 1 is in the pile
    {
        int flag = 1;
        int i = 1;
        while (p[1] + i - 1 <= n)
        {
            if (b[p[1] + i - 1] != i)
            {
                flag = 0;
                break;
            }
            i++;
        }
        i--;

        if (flag)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (p[j] >= j - i)
                {
                    flag = 0;
                    break;
                }
            }
        }

        if (flag)
        {
            cout << n - i << endl;
            return;
        }
    }

    int result = -1;
    for (int i = 1; i <= n; i++)
        result = max(result, p[i] - i + 1 + n);
    cout << result << endl;
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