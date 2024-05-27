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

/*
    Comparison Function (compare):
        Defines the comparison logic for maintaining the max-heap property.

    Heapify Function (heapify):
        Maintains the heap property by comparing a node with its children and swapping them if necessary.
        Recursively calls itself to ensure the entire sub-tree satisfies the heap property.

    Build Heap Function (buildHeap):
        Converts an array into a heap by calling heapify on all non-leaf nodes, starting from the bottom up.

    Heap Sort Function (heapsort):
        First builds a heap from the array.
        Then repeatedly swaps the root of the heap with the last element, reduces the heap size, and calls heapify to maintain the heap property.

    Print Function (print):
        Utility function to print the elements of the array.

    Solve Function (solve):
        Reads input from the user, calls heapsort, and prints the sorted array.
*/

// Function to compare two elements based on the type of heap
// This will help in maintaining the max-heap property
bool compare(int child, int parent)
{
    return child > parent; // For max-heap
}

// Function to maintain the heap property from the given index downwards
void heapify(vector<int> &arr, int idx, int n)
{
    int left = 2 * idx;
    int right = 2 * idx + 1;
    int largest = idx;

    // If left child is larger than the root
    if (left < n && compare(arr[left], arr[largest]))
    {
        largest = left;
    }

    // If right child is larger than the largest so far
    if (right < n && compare(arr[right], arr[largest]))
    {
        largest = right;
    }

    // If largest is not the root
    if (largest != idx)
    {
        swap(arr[idx], arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, largest, n);
    }
}

// Function to build a heap from a given array
void buildHeap(vector<int> &arr)
{
    int n = arr.size();
    // Build heap (rearrange array)
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, i, n);
    }
}

// Heapsort implementation
void heapsort(vector<int> &arr)
{
    buildHeap(arr);
    int n = arr.size();

    // One by one extract elements from the heap
    for (int i = n - 1; i > 1; i--)
    {
        // Move current root to end
        swap(arr[1], arr[i]);
        // Call max heapify on the reduced heap
        heapify(arr, 1, i);
    }
}

// Utility function to print the array (for debugging purposes)
void print(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void solve()
{
    vector<int> v;
    v.push_back(-1); // Placeholder for 1-based indexing

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int temp;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }

    heapsort(v);
    cout << "Sorted elements: ";
    print(v);
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