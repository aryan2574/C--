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

// Number of cities
const int n = 4;

// Distance matrix representing distances between cities
int dist[10][10] = {
    {0, 20, 42, 25},
    {20, 0, 30, 34},
    {42, 30, 0, 10},
    {25, 34, 10, 0}};

// Variable to represent all cities visited
const int VISITED_ALL = (1 << n) - 1;

// Dynamic programming table to store subproblem solutions
int dp[1 << n][n];

// Function to solve the Traveling Salesman Problem recursively
int tsp(int mask, int pos)
{
    // If all cities have been visited, return to the starting city
    if (mask == VISITED_ALL)
    {
        return dist[pos][0]; // Return the distance from the current city to the starting city
    }

    // If the solution for the current subproblem has been computed before, return it
    if (dp[mask][pos] != -1)
    {
        return dp[mask][pos];
    }

    // Initialize answer for the current subproblem
    int ans = INT_MAX;

    // Try to go to an unvisited city
    for (int city = 0; city < n; city++)
    {
        // Check if the city has not been visited yet
        if ((mask & (1 << city)) == 0)
        {
            // Calculate the cost of going to the unvisited city and recursively solve the subproblem
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            // Update the answer to the minimum cost
            ans = min(ans, newAns);
        }
    }

    // Memoize the computed solution for future use
    return dp[mask][pos] = ans;
}

// Function to solve the Traveling Salesman Problem
void solve()
{
    // Initialize dynamic programming table with -1 to indicate that no solution has been computed yet
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = -1;
        }
    }

    // Output the minimum cost of the Traveling Salesman Problem starting from the first city (0-indexed)
    cout << "Minimum cost: " << tsp(1, 0) << endl;
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