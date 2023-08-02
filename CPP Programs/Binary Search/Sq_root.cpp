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

float sqroot(int n, int p)
{
    int start = 0, end = n, mid;
    float ans = -1;
    while (start <= end)
    {
        mid = (start + end) / 2;

        if ((mid * mid) == n)
            return mid;

        else if ((mid * mid) > n)
            end = mid - 1;

        else
        {
            ans = mid;
            start = mid + 1;
        }
    }

    float inc = 0.1;
    for (int time = 1; time <= p; ++time)
    {
        while (ans * ans <= n)
        {
            ans += inc;
        }
        ans -= inc;
        inc /= 10;
    }
    return ans;
}

void solve()
{
    int n, p;

    scanf("%d%d", &n, &p);
    cout << sqroot(n, p) << nline;
}

// _____________________________________________________________________________________
int main(void)
{
    ayush_2574_cp();
    solve();
    return 0;
}