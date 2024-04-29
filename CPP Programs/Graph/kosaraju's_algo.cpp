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

// Kosaraju's Algorithm

// Depth-first search (DFS) function to visit nodes and push them onto the stack
void dfs(vector<int> graph[], int i, bool *visited, vector<int> &stack)
{
    visited[i] = true; // Mark the current node as visited
    // Visit all neighbors of the current node
    for (int nbr : graph[i])
    {
        if (!visited[nbr])
        {
            dfs(graph, nbr, visited, stack); // Recursive DFS call for unvisited neighbors
        }
    }
    stack.push_back(i); // Push the current node onto the stack after visiting all its neighbors
}

// DFS function for printing nodes of each strongly connected component (SCC)
void dfs2(vector<int> graph[], int i, bool *visited)
{
    visited[i] = true; // Mark the current node as visited
    cout << i << ' ';  // Print the current node
    // Visit all neighbors of the current node
    for (int nbr : graph[i])
    {
        if (!visited[nbr])
        {
            dfs2(graph, nbr, visited); // Recursive DFS call for unvisited neighbors
        }
    }
}

// Kosaraju's algorithm to find strongly connected components (SCCs) in a directed graph
void kosarajus(vector<int> graph[], vector<int> rev_graph[], int N)
{
    bool visited[N];
    memset(visited, 0, sizeof(visited)); // Initialize visited array with false values

    vector<int> stack; // Stack to store vertices in post-order of finish times

    // Step 1: Perform DFS on the original graph and store vertices according to their finish times
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            dfs(graph, i, visited, stack); // Perform DFS on unvisited nodes
        }
    }

    // Step 3: Process all vertices in order defined by the stack
    memset(visited, 0, sizeof(visited)); // Reset visited array
    char component_name = 'A';           // Start component name from 'A'
    for (int x = stack.size() - 1; x >= 0; x--)
    {
        int node = stack[x]; // Get the vertex from the stack
        if (!visited[node])
        {
            cout << "Component " << component_name << "--> "; // Print component name
            dfs2(rev_graph, node, visited);                   // DFS to print nodes of the current SCC
            cout << endl;                                     // Move to the next line for the next component
            component_name++;                                 // Increment component name for the next SCC
        }
    }
}

void solve()
{
    int N, m;
    cin >> N >> m; // Input the number of vertices (N) and edges (m)

    vector<int> graph[N], rev_graph[N]; // Adjacency lists for the original and reverse graphs

    // Input the edges of the graph and construct both the original and reverse graphs
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y; // Input an edge (x, y)

        graph[x].push_back(y);     // Add edge to the original graph
        rev_graph[y].push_back(x); // Add edge to the reverse graph
    }

    kosarajus(graph, rev_graph, N); // Call Kosaraju's algorithm to find SCCs
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