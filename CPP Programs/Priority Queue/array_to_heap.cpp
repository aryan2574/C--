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

// Global constant to determine heap type
const bool minHeap = false;

// Function to compare two elements based on the type of heap
bool compare(int child, int parent)
{
    if (minHeap)
        return child < parent; // For min-heap
    else
        return child > parent; // For max-heap
}

// Function to maintain the heap property from the given index downwards
void heapify(int idx, vector<int> &v)
{
    int left = 2 * idx, right = 2 * idx + 1;
    int betterChild = idx;
    int last = v.size() - 1;

    if (left <= last && compare(v[left], v[idx]))
    {
        betterChild = left;
    }

    if (right <= last && compare(v[right], v[betterChild]))
    {
        betterChild = right;
    }

    if (betterChild != idx)
    {
        swap(v[idx], v[betterChild]);
        heapify(betterChild, v);
    }
}

// Build heap using up-heap (bubble-up) method - O(NlogN)
void buildHeap(vector<int> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        int idx = i;
        int parent = i / 2;

        // Use compare function to maintain heap property
        while (idx > 1 && compare(v[idx], v[parent]))
        {
            swap(v[idx], v[parent]);
            idx = parent;
            parent = parent / 2;
        }
    }
}

// Build heap using down-heap (heapify) method - O(N)
void buildHeap2(vector<int> &v)
{
    for (int i = v.size() / 2; i >= 1; i--)
    {
        heapify(i, v);
    }
}

void solve()
{
    vector<int> vi1{-1, 10, 20, 5, 6, 1, 8, 9, 4};
    vector<int> vi2{-1, 10, 20, 5, 6, 1, 8, 9, 4};

    // Build heaps
    buildHeap(vi1);
    buildHeap2(vi2);

    // Print results
    cout << "Heap built using buildHeap: ";
    for (const auto &i : vi1)
        cout << i << ' ';
    cout << nline;

    cout << "Heap built using buildHeap2: ";
    for (const auto &i : vi2)
        cout << i << ' ';
    cout << nline;
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