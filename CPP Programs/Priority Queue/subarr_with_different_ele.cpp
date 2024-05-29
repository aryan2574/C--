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

const int MOD = 1e9 + 7; // Define a constant MOD to store 10^9 + 7

// Function to calculate the sum of lengths of subarrays with all distinct elements
int sumOfLengthsOfSubarraysWithDistinctElements(int n, const std::vector<int> &arr)
{
    std::unordered_set<int> seen; // Set to keep track of elements in the current window
    int start = 0;                // Start pointer of the sliding window
    long long sum_lengths = 0;    // Variable to store the sum of lengths

    // Iterate through the array using the end pointer
    for (int end = 0; end < n; ++end)
    {
        // If the element at 'end' is already in the set, move the 'start' pointer to the right
        while (seen.find(arr[end]) != seen.end())
        {
            seen.erase(arr[start]); // Remove the element at 'start' from the set
            ++start;                // Move the 'start' pointer to the right
        }

        // Add the current element at 'end' to the set
        seen.insert(arr[end]);

        // Calculate the number of subarrays ending at 'end' with distinct elements
        // and add it to sum_lengths
        sum_lengths += (end - start + 1);

        // Take modulo to prevent overflow
        sum_lengths %= MOD;

        for (const auto &ele : seen)
            cout << ele << ' ';
        cout << nline;
    }

    // Return the final sum of lengths modulo 10^9 + 7
    return sum_lengths;
}

void solve()
{
    int n;
    std::cin >> n; // Read the size of the array
    std::vector<int> arr(n);

    // Read the array elements
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    // Calculate the result using the function
    int result = sumOfLengthsOfSubarraysWithDistinctElements(n, arr);

    // Print the result
    std::cout << result << std::endl;
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