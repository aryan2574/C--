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

// Helper function for DFS traversal to check if the graph is bipartite
bool dfs_helper(vector<int> graph[], int node, vector<int> &visited, int parent, int color)
{
    // Mark the current node as visited and assign it a color
    visited[node] = color;

    // Traverse all neighbors of the current node
    for (const auto &nbr : graph[node])
    {
        // If the neighbor is not visited, recursively call DFS on it with the opposite color
        if (visited[nbr] == 0)
        {
            if (!dfs_helper(graph, nbr, visited, node, 3 - color)) // Switch color (1 to 2, 2 to 1)
                return false;
        }
        // If the neighbor is visited and has the same color as the current node's color, the graph is not bipartite
        else if (nbr != parent && color == visited[nbr])
        {
            return false;
        }
    }
    return true; // If DFS traversal completes without finding conflicts, the graph is bipartite
}

// Main DFS function to check if the graph is bipartite
bool dfs(vector<int> graph[], int N)
{
    vector<int> visited(N, 0);                           // Array to track visited nodes and their colors
    int color = 1;                                       // Start with color 1 for the first node
    bool ans = dfs_helper(graph, 0, visited, -1, color); // Start DFS traversal from the first node

    // Print colors of all nodes after DFS traversal for clarity (optional)
    for (int i = 0; i < N; i++)
    {
        cout << i << " - Color " << visited[i] << endl;
    }

    return ans; // Return the result of DFS traversal (true if bipartite, false otherwise)
}

// Function to read graph input, perform DFS, and output whether the graph is bipartite
void solve()
{
    int N, M;
    cin >> N >> M; // Input the number of vertices (N) and edges (M)

    vector<int> graph[N]; // Create an array of vectors to represent the adjacency list of the graph

    // Input the edges of the graph
    while (M--)
    {
        int x, y;
        cin >> x >> y; // Input an edge (x, y)

        // Add the edge to the adjacency lists of both vertices
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    // Check if the graph is bipartite using DFS and output the result
    if (dfs(graph, N))
    {
        cout << "YES, it's bipartite" << endl;
    }
    else
    {
        cout << "Not bipartite" << endl;
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