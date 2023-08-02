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
    int arr[] = {1, 4, 5, 6, 7, 8, 9, 8, 6, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (n == 1)
        cout << 0;
    else
    {
        int low(0), high(n - 1), ans(-1);
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (mid > 0 && mid < n - 1)
            {
                if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
                {
                    ans = arr[mid];
                    break;
                }
                else if (arr[mid - 1] > arr[mid])
                    high = mid - 1;
                else if (arr[mid + 1] > arr[mid])
                    low = mid + 1;
            }
            else if (mid == 0)
            {
                if (arr[mid] > arr[mid + 1])
                {
                    ans = mid;
                    break;
                }
                else
                {
                    ans = mid + 1;
                    break;
                }
            }
            else if (mid == n - 1)
            {
                if (arr[mid] > arr[mid - 1])
                {
                    ans = arr[mid];
                    break;
                }
                else
                {
                    ans = arr[mid - 1];
                    break;
                }
            }
        }
        cout << ans;
    }
}

// _____________________________________________________________________________________
int main(void)
{
    ayush_2574_cp();
    solve();
    return 0;
}