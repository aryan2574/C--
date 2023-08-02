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

int mnEle(int *arr, int n) // Calculating Minimum Element
{
    int low = 0, high = n - 1;

    if (low == high) // If thre is only one element
        return low;

    if (arr[low] <= arr[high]) // If the array is already sorted
        return low;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int prev = (mid - 1 + n) % n, next = (mid + 1) % n;

        if (arr[mid] <= arr[prev] && arr[mid] <= arr[next])
            return mid;
        else if (arr[0] < arr[mid])
            low = mid + 1;
        else if (arr[mid] < arr[n - 1])
            high = mid - 1;
    }

    return -1;
}

int bSrch(int *arr, int key, int low, int high) // Searching our element using binary search
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

void solve()
{
    int n;
    cin >> n;
    int arr[n] = {0};
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int key, size;
    cin >> key;
    size = sizeof(arr) / sizeof(arr[0]);

    int min_ele = mnEle(arr, size);

    // Approach : 1

    /*int idx1 = bSrch(arr, key, 0, min_ele - 1);
    int idx2 = bSrch(arr, key, min_ele, size - 1);

    if (idx1 == -1)
        cout << idx2;
    else
        cout << idx1;
    */

    // Approach : 2

    int idx = -1;
    if (min_ele == 0)
        idx = bSrch(arr, key, 0, size - 1);
    else if (key >= arr[0])
        idx = bSrch(arr, key, 0, min_ele - 1);
    else
        idx = bSrch(arr, key, min_ele, size - 1);

    cout << idx;
}

// _____________________________________________________________________________________
int main(void)
{
    ayush_2574_cp();
    solve();
    return 0;
}