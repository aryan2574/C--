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

// kth Smallest Element in sorted Matrix

// Define a type alias for better readability
using node = pair<int, pair<int, int>>; // {value, {row, column}}

int findKSmallest(vector<vector<int>> &arr, int k)
{
    int n = arr.size();
    if (n == 0)
        return -1;
    int m = arr[0].size();

    // Min-heap to store the smallest elements
    priority_queue<node, vector<node>, greater<node>> minHeap;

    // Insert the first element of each row into the heap
    for (int i = 0; i < min(n, k); ++i)
    {
        minHeap.push({arr[i][0], {i, 0}});
    }

    node curr;
    // Extract the smallest element from the heap k times
    for (int i = 0; i < k; ++i)
    {
        curr = minHeap.top();
        minHeap.pop();

        int r = curr.second.first;  // Row index
        int c = curr.second.second; // Column index

        // If there is a next element in the same row, push it into the heap
        if (c + 1 < m)
        {
            minHeap.push({arr[r][c + 1], {r, c + 1}});
        }
    }

    return curr.first;
}

void solve()
{
    vector<vector<int>> arr = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {24, 29, 37, 48},
        {32, 33, 39, 50}};

    int k = 5;

    cout << "The " << k << "th smallest element is: " << findKSmallest(arr, k) << nline;
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