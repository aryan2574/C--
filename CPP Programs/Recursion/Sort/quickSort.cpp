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

// Step 1 : Find Pivot

// Step 2 : Divide the Array into three parts
// 1. Left Part : Elements less than Pivot
// 2. Middle : Pivot
// 3. Right Part : Elements greater than Pivot

// Step 3:
// 3.1 - Recursively sort left part -  quickSort(arr,strtIdx, pivtIndx-1)
// 3.2 - Recursively sort right part - quickSort(arr,pivtIndx+1, end)

// Step 4 : Do Inplace sort

// Inplace sort the array
// - Put numbers smaller than pivot at the left side of the array
// - Put numbers greater than pivot at the right side of the array
// - Return the pivot index, so we can call Quick sort at both left and right parts
int findPartition(int *arr, int s, int e)
{
    int pivt = arr[e], i = s;
    for (int j = s; j <= e; j++)
    {
        if (arr[j] <= pivt)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    return i - 1;
}

void quickSortFunc(int *arr, int s, int e)
{
    // base case
    if (s >= e)
        return;

    // recursive case
    int p = findPartition(arr, s, e);

    // Call quick sort in the left part
    quickSortFunc(arr, s, p - 1);

    // Call quick sort in the right part
    quickSortFunc(arr, p + 1, e);
}

void solve()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quickSortFunc(arr, 0, n - 1);

    for (auto i : arr)
        cout << i << " ";
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