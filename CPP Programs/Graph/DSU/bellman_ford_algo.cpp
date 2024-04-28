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

// Shortest Path Algorithm

// Function to perform the Bellman-Ford algorithm to find shortest paths from a source vertex
vector<int> bellman_ford(int V, int src, vector<vector<int>> &edges)
{
    // Distance vector initialized with INT_MAX to signify infinity
    vector<int> dist(V + 1, INT_MAX);
    // Distance to source is 0 as it is the starting point
    dist[src] = 0;

    // Main loop: relax all edges V-1 times (where V is number of vertices)
    for (int i = 0; i < V - 1; i++)
    {
        for (const auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            // Relaxation step: update the distance if a shorter path is found
            if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check for negative weight cycles by trying to relax edges one more time
    // If the value changes any more time than V-1, then we have negative weight cycles
    for (const auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        // If a relaxation is possible here, it indicates a negative weight cycle
        if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
        {
            cout << "Negative weight cycle found\n";
            exit(0); // Exiting program (not always the best approach, consider throwing an exception)
        }
    }

    // Return the calculated shortest distances
    return dist;
}

// Function to read graph data and execute Bellman-Ford algorithm
void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges; // Vector to store edges

    // Input edges data: each edge is represented as a tuple (u, v, weight)
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    // Execute Bellman-Ford algorithm from vertex 1 (assuming 1 is within graph bounds)
    vector<int> distances = bellman_ford(n, 1, edges);

    // Output the shortest distances from the source to each vertex
    for (int i = 1; i <= n; i++)
    {
        if (distances[i] == INT_MAX)
            cout << "Node " << i << " is at dist: infinity\n";
        else
            cout << "Node " << i << " is at dist " << distances[i] << endl;
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