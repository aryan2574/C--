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

// Check if an array is sorted
bool isSorted(int *arr, int n)
{
    // base case
    if (n == 0 || n == 1)
        return true;

    // recursive case
    if (arr[0] < arr[1] && isSorted(arr + 1, n - 1))
    {
        return true;
    }

    return false;
}

// Binary Search - Recursion Implementation
int binarySearchRecursion(int *arr, int low, int high, int key)
{
    // base case
    if (high >= low)
    {
        int mid = low + (high - low) / 2;

        // If the element is present at the middle
        if (arr[mid] == key)
        {
            return mid;
        }

        // If element is smaller than mid, then call the left subarray
        if (key < arr[mid])
        {
            return binarySearchRecursion(arr, low, mid - 1, key);
        }

        // Else call the right subarray
        return binarySearchRecursion(arr, mid + 1, high, key);
    }
    return -1;
}

void solve()
{
    int sze;
    cin >> sze;
    int arr[sze];
    for (int i = 0; i < sze; i++)
        cin >> arr[i];

    int key;
    cin >> key;

    int low = 0, high = sze - 1;

    // cout << isSorted(arr, sze) << nline;

    int ans = binarySearchRecursion(arr, low, high, key);
    if (ans == -1)
        cout << "Element not found" << nline;
    else
        cout << "Elelment found at Index " << ans << nline;
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