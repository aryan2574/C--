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

// Counting Sort - O(N + Range)
// Not suitable to large ranges

/*
Step 1 : Calculate Frequency of the numbers in the array
Step 2 : Iterate through frequency array and print the numbers by their frequency times
    eq:  Freq[6] = 2 : print 6 6

Since we are iterating through 0 - new created array will be sorted
*/

const int inp[] = {88, 97, 10, 12, 15, 1, 5, 6, 12, 5, 8};

void solve()
{

    int n = sizeof(inp) / sizeof(int);
    vector<int> sortedArray;

    // Find maximum in the array to create frequency array
    int mx = *max_element(&inp[0], &inp[n - 1]);

    // Frequency Array
    int freq[mx + 1] = {0};

    for (int i = 0; i < n; i++)
    {
        freq[inp[i]]++;
    }

    // Create sorted array according to frequency
    for (int i = 0, currFreq; i <= mx; i++)
    {
        currFreq = freq[i];
        if (currFreq)
        {
            while (currFreq)
            {
                sortedArray.push_back(i);
                currFreq--;
            }
        }
        currFreq = 0;
    }

    // Print sorted Array
    for (auto ele : sortedArray)
        cout << ele << nline;
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