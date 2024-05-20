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

// SPOJ Problem : DEFKIN
// https://www.spoj.com/problems/DEFKIN/

void solve()
{
    int t;
    cin >> t;

    while (t--)
    {
        int w, h, n;
        cin >> w >> h >> n;

        vector<int> x_coords, y_coords;

        for (int i = 0; i < n; ++i)
        {
            int x, y;
            cin >> x >> y;
            x_coords.push_back(x);
            y_coords.push_back(y);
        }

        // If there are no towers, the largest rectangle is the whole grid
        if (n == 0)
        {
            cout << w * h << nline;
            continue;
        }

        // Sort the coordinates
        sort(x_coords.begin(), x_coords.end());
        sort(y_coords.begin(), y_coords.end());

        // Calculate maximum gaps in x direction
        int max_x_gap = max(x_coords[0] - 1, w - x_coords.back());
        for (int i = 1; i < n; ++i)
        {
            max_x_gap = max(max_x_gap, x_coords[i] - x_coords[i - 1] - 1);
        }

        // Calculate maximum gaps in y direction
        int max_y_gap = max(y_coords[0] - 1, h - y_coords.back());
        for (int i = 1; i < n; ++i)
        {
            max_y_gap = max(max_y_gap, y_coords[i] - y_coords[i - 1] - 1);
        }

        // The largest rectangle that is not defended
        int largest_undefended_area = max_x_gap * max_y_gap;
        cout << largest_undefended_area << nline;
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