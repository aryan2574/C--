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

// Function to swap two elements
void swapElements(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Iterative Bubble Sort Function
void findBubbleSort(int *arr, int n)
{
    bool swapped; // Flag to track if any swaps are made in a pass

    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;

        // Last i elements are already in place after i passes
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap the elements
                swapElements(arr[j], arr[j + 1]);
                swapped = true; // Set the flag to true
            }
        }

        // If no swaps were made in this pass, the list is sorted
        if (!swapped)
        {
            break;
        }
    }
}

void findBubbleSortRec(int *arr, int len)
{
    // Base Case
    if (len == 1)
    {
        return;
    }

    // Recursive Case
    // Move the largest element to the end
    for (int j = 0; j < len - 1; j++)
    {
        if (arr[j] > arr[j + 1])
            swapElements(arr[j], arr[j + 1]);
    }

    // Sort the first n-1 elements
    findBubbleSortRec(arr, len - 1);
}

void findBubbleSortRec2(int *arr, int n, int i)
{
    if (n == 1)
        return;

    if (i == n - 1)
    {
        // If one pass is completed, start the next pass
        findBubbleSortRec2(arr, n - 1, 0);
        return;
    }

    if (arr[i] > arr[i + 1])
    {
        // Swap the elements if they are in the wrong order
        swap(arr[i], arr[i + 1]);
    }

    // Move to the next element in the current pass
    findBubbleSortRec2(arr, n, i + 1);
}

void solve()
{
    int len;
    cin >> len;

    int arr[len];

    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }

    // findBubbleSort(arr, len);
    // findBubbleSortRec(arr, len);
    findBubbleSortRec2(arr, len, 0);

    for (int i = 0; i < len; i++)
        cout << arr[i] << nline;
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