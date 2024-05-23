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

class Heap
{
    vector<int> v;
    bool minHeap;

    // Function to compare two elements based on the type of heap
    bool compare(int child, int parent)
    {
        if (minHeap)
            return child < parent; // Change from <= to < for strict heap property
        else
            return child > parent; // Change from >= to > for strict heap property
    }

public:
    // Constructor with default size and heap type (true for min-heap, false for max-heap)
    Heap(int default_size = 10, bool type = true)
    {
        // Reserve memory according to requirement
        v.reserve(default_size);

        // Start from index 1 for easy parent-child calculations
        v.push_back(-1); // Placeholder for 1-based indexing

        minHeap = type;
    }

    // Insert function to add an element to the heap
    void push(int ele)
    {
        // Add the new element at the end
        v.push_back(ele);

        // Get the current index of the new element and its parent's index
        int idx = v.size() - 1;
        int parent = idx / 2;

        // Perform up-heap (bubble-up) operation to maintain heap property
        while (idx > 1 && compare(v[idx], v[parent]))
        {
            // Swap the current element with its parent
            swap(v[idx], v[parent]);

            // Update the current index and parent index
            idx = parent;
            parent = parent / 2;
        }
    }

    // Utility function to print the heap (for debugging purposes)
    void print()
    {
        for (int i = 1; i < v.size(); ++i)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};

void solve()
{
    Heap minHeap(10, true); // Create a min-heap
    minHeap.push(10);
    minHeap.push(20);
    minHeap.push(5);
    minHeap.push(7);
    minHeap.push(40);
    minHeap.push(3);

    cout << "Min-Heap: ";
    minHeap.print();

    Heap maxHeap(10, false); // Create a max-heap
    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(5);
    maxHeap.push(7);
    maxHeap.push(40);
    maxHeap.push(3);

    cout << "Max-Heap: ";
    maxHeap.print();
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