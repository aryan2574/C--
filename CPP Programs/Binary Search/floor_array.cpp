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
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int size = sizeof(arr) / sizeof(arr[0]);

    int key;
    cin >> key;

    int ans(-1);

    if (key < arr[0])
        ans = -1;
    else if (key > arr[n - 1])
        ans = arr[n - 1];
    else
    {
        int low(0), high(n - 1);
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= key)
            {
                ans = arr[mid];
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
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