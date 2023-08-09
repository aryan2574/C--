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

// Find first occurrence of an element inside an array
int firstOccRec(int *arr, int n, int key)
{
    if (n == 0)
        return -1; // Base case: If the array is empty, the element is not found, return -1

    // Recursive case
    if (arr[0] == key)
        return 0; // If the first element matches the key, return 0 (index of the first element)

    int i = firstOccRec(arr + 1, n - 1, key); // Recursive call to search in the remaining array

    if (i == -1)
        return -1; // If the element is not found in the remaining array, return -1

    return i + 1; // If the element is found in the remaining array, return the index + 1
}

// Linear Search using recursion
int linearSearchRec(int *arr, int low, int high, int key)
{
    if (low <= high)
    {
        // base case
        if (arr[low] == key)
            return low;

        // recursive case
        return linearSearchRec(arr, low + 1, high, key);
    }

    return -1;
}

// Find last occurrence of an element inside an array
int lastOccRec(int *arr, int low, int high, int key)
{
    if (high >= low)
    {
        // Base case: If the element is found at the current high index, return the index.
        if (arr[high] == key)
            return high;

        // Recursive case: If the element is not found at the current high index,
        // make a recursive call to search in the remaining array (from high-1 to low).
        return lastOccRec(arr, low, high - 1, key);
    }

    // If we reach this point, it means the element is not found in the array.
    return -1;
}

// Another way to find last occurrence of an element in the array
int lastOccRec2(int *arr, int n, int key)
{
    // Base case: If the size of the array becomes 0, it means we have searched the entire array,
    // and the element is not found. In this case, return -1 to indicate the element is not present.
    if (n == 0)
        return -1;

    // Recursive Case: If the size of the array is not 0, make a recursive call to search in the remaining array (from index 1 to n-1).
    int i = lastOccRec2(arr + 1, n - 1, key);

    // After the recursive call, check the result 'i' returned by the subproblem.
    if (i == -1)
    {
        // If 'i' is -1, it means the element is not found in the remaining array.
        // Now, check if the first element (index 0) of the current array matches the key.
        // If it matches, return 0 as the last occurrence index in the current array.
        // Otherwise, return -1 to indicate that the element is not present in the current array.
        if (arr[0] == key)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }

    // If 'i' returned by the subproblem is not -1, it means the element is found in the remaining array.
    // In this case, return (i + 1) as the last occurrence index in the current array.
    return i + 1;
}

// Find all the occurrences of an element in an array
int findAllOccRec(int *arr, int low, int high, int key)
{
    if (low <= high)
    {
        // base case
        if (arr[low] == key)
            cout << low << nline;

        // recursive case
        findAllOccRec(arr, low + 1, high, key);
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

    int key;
    cin >> key;

    int low(0), high(n - 1);

    // int ans = firstOccRec(arr, n, key);
    // int ans1 = linearSearchRec(arr, low, high, key);
    // int ans2 = lastOccRec(arr, low, high, key);
    // int ans2 = lastOccRec2(arr, n, key);

    // if (ans2 == -1)
    //     cout << "Element not found" << nline;
    // else
    //     cout << "Element found at index : " << ans2 << nline;

    findAllOccRec(arr, low, high, key);
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