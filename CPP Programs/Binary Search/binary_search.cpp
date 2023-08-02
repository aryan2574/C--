#include <bits/stdc++.h>
using namespace std;

#define mod1 998244353
#define INF 1e18
#define PI 3.141592653589793238462
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
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

// Binary Search
int bS(int *arr, int key, int size)
{
    int start = 0, end = size - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

// Lower Bound Function
int lwerbnd(int *arr, int key, int size)
{
    int start = 0, end = size - 1, ans = -1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (arr[mid] > key)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return ans;
}

// Upper Bound Function
int uprbnd(int *arr, int key, int size)
{
    int start = 0, end = size - 1, ans = -1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (arr[mid] > key)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return ans;
}

void solve()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int key;
    scanf("%d", &key);

    int size = sizeof(arr) / sizeof(int);
    // int ans = bS(arr, key, size);

    int ans = uprbnd(arr, key, size);

    if (ans == -1)
        cout << "NOT FOUND";
    else
        cout << "KEY Found at Index : " << ans;
}

// _____________________________________________________________________________________
int main(void)
{
    ayush_2574_cp();
    solve();
    return 0;
}