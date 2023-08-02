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

// Counting Number of rotation using linear search : O(n)
int countRLinear(int *arr, int size)
{
    int ele = INT_MAX, idx(-1);
    for (int i = 0; i < size; i++)
    {
        if (ele > arr[i])
        {
            ele = arr[i];
            idx = i;
        }
    }
    return idx;
}

// Using Binary Search in O(logn)
int countRBinary(int *arr, int size)
{
    int low = 0, high = size - 1;

    // If there is only one element left
    if (high == low)
        return low;

    // If array is already sorted
    if (arr[low] <= arr[high])
        return low;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int prev = ((mid - 1 + size) % size);
        int next = ((mid + 1) % size);
        if (arr[mid] <= arr[prev] && arr[mid] <= arr[next]) // Checking our pivot element
            return mid;

        else if (arr[mid] <= arr[size - 1]) // It will not matter which case we will write forward both can never be true
            high = mid - 1;                 // at the same time

        else if (arr[0] <= arr[mid])
            low = mid + 1;
    }
    return -1;
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int size = sizeof(arr) / sizeof(arr[0]);

    int ansByLinear = countRLinear(arr, size), ansByBinary = countRBinary(arr, size);
    cout << ansByBinary;
}

// _____________________________________________________________________________________
int main(void)
{
    ayush_2574_cp();
    solve();
    return 0;
}