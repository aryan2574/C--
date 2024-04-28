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

// Function to perform the Floyd-Warshall algorithm to find shortest paths between all pairs of vertices
vector<vector<int>> floyd_warshall(vector<vector<int>> graph)
{
    int V = graph.size();
    // Initialize a 2D vector to store shortest distances between all pairs of vertices
    vector<vector<int>> dist(V, vector<int>(V));

    // Initialize the distance matrix with the same values as the graph
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }

    // Phases: in the kth phase, we include vertices (1, 2, ..., k) as intermediate vertices
    for (int k = 0; k < V; k++)
    {
        // Iterate over all pairs of vertices
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                // If vertex k is included, can we minimize the distance between i and j?
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][j] > dist[i][k] + dist[k][j])
                {
                    // Update the distance to the shorter path through vertex k
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    // Return the computed shortest distances
    return dist;
}

void solve()
{
    // Initial Graph constructed through input
    vector<vector<int>> graph = {
        {0, INT_MAX, -2, INT_MAX},
        {4, 0, 3, INT_MAX},
        {INT_MAX, INT_MAX, 0, 2},
        {INT_MAX, -1, INT_MAX, 0}};

    // Find shortest distances between all pairs of vertices
    auto result = floyd_warshall(graph);

    // Output the shortest distances between all pairs of vertices
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result.size(); j++)
        {
            // Print "INF" for unreachable vertices (represented by INT_MAX in the result matrix)
            if (result[i][j] == INT_MAX)
            {
                cout << "INF ";
            }
            else
            {
                cout << result[i][j] << " ";
            }
        }
        cout << nline;
    }
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