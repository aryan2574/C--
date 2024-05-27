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

// Define a type alias for better readability
using node = pair<int, pair<int, int>>;

// Function to merge k-sorted arrays using a min-heap
vector<int> mergeKSortedArrays(vector<vector<int>> &arr)
{
    vector<int> result;
    priority_queue<node, vector<node>, greater<node>> pq;

    // Insert the 0th element of each array into the min-heap
    for (int i = 0; i < arr.size(); ++i)
    {
        if (!arr[i].empty())
        { // Check if the array is not empty
            pq.push({arr[i][0], {i, 0}});
        }
    }

    // Process the min-heap until it's empty
    while (!pq.empty())
    {
        // Extract the smallest element from the heap
        node current = pq.top();
        pq.pop();
        int ele = current.first;
        int x = current.second.first;  // Index of the array
        int y = current.second.second; // Index within the array

        // Add the smallest element to the result
        result.push_back(ele);

        // If there is a next element in the same array, add it to the heap
        if (y + 1 < arr[x].size())
        {
            pq.push({arr[x][y + 1], {x, y + 1}});
        }
    }

    return result;
}

// Function to print the result vector
void print(const vector<int> &v)
{
    for (const auto &ele : v)
    {
        cout << ele << ' ';
    }
    cout << endl;
}

void solve()
{
    vector<vector<int>> arr = {
        {2, 6, 12, 15},
        {1, 3, 14, 20},
        {3, 5, 8, 10}};

    vector<int> output = mergeKSortedArrays(arr);

    print(output); // Expected output: 1 2 3 3 5 6 8 10 12 14 15 20
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