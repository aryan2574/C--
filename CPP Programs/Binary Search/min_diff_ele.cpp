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

void solve()
{
    int arr[] = {1, 3, 4, 6, 7, 10, 13, 15, 16, 20, 22, 25, 29};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;

    int low(0), high(n - 1), ans(-1);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            ans = arr[mid];
            break;
        }
        if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (ans == -1)
    {
        ans = abs(arr[low] - key) <= abs(arr[high] - key) ? arr[low] : arr[high];
    }
    cout << ans;
}

// _____________________________________________________________________________________
int main(void)
{
    ayush_2574_cp();
    solve();
    return 0;
}