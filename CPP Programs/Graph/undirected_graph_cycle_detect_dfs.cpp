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

// If there is more then one way to visit a node - Find cycle in undirected graph
class Graph
{
    list<int> *l;
    int V;

public:
    Graph(int V) : V(V)
    {
        l = new list<int>[V];
    }

    ~Graph()
    {
        delete[] l; // Deallocate memory
    }

    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x); // For undirected graph
    }

    bool cycle_helper(int curr_node, vector<bool> &visited, vector<int> &parent)
    {
        visited[curr_node] = true;

        // Traverse all neighbors of the current node
        for (auto nbr : l[curr_node])
        {
            // If the neighbor is visited and not the parent of the current node, cycle found
            if (visited[nbr] && parent[curr_node] != nbr)
                return true;

            // If the neighbor is not visited, explore it
            if (!visited[nbr])
            {
                parent[nbr] = curr_node; // Update parent
                bool cycle_found = cycle_helper(nbr, visited, parent);
                if (cycle_found)
                    return true; // Propagate the cycle detection result
            }
        }

        return false; // No cycle found in this DFS branch
    }

    bool isCycle()
    {
        vector<bool> visited(V, false);
        vector<int> parent(V, -1); // Initialize parent array to -1

        // Perform DFS for each unvisited vertex
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (cycle_helper(i, visited, parent))
                    return true; // If cycle found in any connected component, return true
            }
        }

        return false; // No cycle found in the entire graph
    }
};

void solve()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(3, 1);
    // g.addEdge(2, 3);

    if (g.isCycle())
        cout << "Cycle present" << endl;
    else
        cout << "No cycle present" << endl;
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