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
            return child < parent; // For min-heap
        else
            return child > parent; // For max-heap
    }

    // Function to find the appropriate child to swap with based on the heap type
    int getBetterChild(int idx, int sze)
    {
        int leftChild = 2 * idx;
        int rightChild = 2 * idx + 1;

        if (leftChild <= sze && rightChild <= sze)
        {
            // Both children exist
            if (compare(v[leftChild], v[rightChild]))
            {
                return leftChild;
            }
            else
            {
                return rightChild;
            }
        }
        else if (leftChild <= sze)
        {
            // Only left child exists
            return leftChild;
        }
        else if (rightChild <= sze)
        {
            // Only right child exists
            return rightChild;
        }
        else
        {
            // No child exists
            return -1;
        }
    }

    // Function to maintain the heap property from the given index downwards
    void heapify(int idx)
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
            heapify(betterChild);
        }
    }

public:
    // Constructor with default size and explicit heap type (true for min-heap, false for max-heap)
    Heap(int default_size = 10, bool type)
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

    // Function to get the top element of the heap
    int top()
    {
        if (v.size() <= 1)
        {
            // Heap is empty
            cout << "Heap is empty" << endl;
            return -1;
        }

        return v[1];
    }

    // Pop function to remove the top element from the heap
    void pop()
    {
        if (v.size() <= 1)
        {
            // Heap is empty
            cout << "Heap is empty" << endl;
            return;
        }

        cout << "Element removed: " << v[1] << "\n"; // Print the root element (for debugging)

        // Swap with the last element
        swap(v[1], v[v.size() - 1]);
        v.pop_back();

        int idx = 1;
        int sze = v.size() - 1;

        // Perform down-heap (bubble-down) operation to maintain heap property
        while (idx <= sze)
        {
            int betterChild = getBetterChild(idx, sze);
            if (betterChild == -1 || !compare(v[betterChild], v[idx]))
            {
                break;
            }

            swap(v[idx], v[betterChild]);
            idx = betterChild;
        }
    }

    // Alternative pop function using the heapify method
    void pop2()
    {
        if (v.size() <= 1)
        {
            // Heap is empty
            cout << "Heap is empty" << endl;
            return;
        }

        int last_idx = v.size() - 1;
        swap(v[1], v[last_idx]);
        v.pop_back();
        heapify(1);
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

    cout << "Element at top: " << minHeap.top() << "\n";

    minHeap.pop();

    cout << "Min-Heap: ";
    minHeap.print();

    cout << "\n";

    Heap maxHeap(10, false); // Create a max-heap
    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(5);
    maxHeap.push(7);
    maxHeap.push(40);
    maxHeap.push(3);

    cout << "Element at top: " << maxHeap.top() << "\n";

    cout << "Max-Heap: ";
    maxHeap.print();

    maxHeap.pop2();
    cout << "Element at top: " << maxHeap.top() << "\n";

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