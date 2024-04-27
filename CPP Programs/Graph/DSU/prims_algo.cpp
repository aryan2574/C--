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

class Graph
{
    vector<pair<int, int>> *l; // Adjacency list to store edges and their weights
    int V;                     // Number of vertices

public:
    Graph(int n)
    { // Constructor to initialize the graph with n vertices
        V = n;
        l = new vector<pair<int, int>>[n]; // Allocate memory for adjacency list
    }

    ~Graph()
    { // Destructor to free memory allocated for adjacency list
        delete[] l;
    }

    void addEdge(int x, int y, int w)
    {                           // Function to add an edge between vertices x and y with weight w
        l[x].push_back({y, w}); // Add edge from x to y with weight w
        l[y].push_back({x, w}); // Add edge from y to x with weight w (since graph is undirected)
    }

    int prim_mst()
    {                                                                                      // Function to find the minimum spanning tree using Prim's algorithm
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q; // Priority queue to store edges sorted by weight
        bool *visited = new bool[V]{0};                                                    // Array to track visited vertices
        int ans = 0;                                                                       // Variable to store the total weight of the minimum spanning tree

        Q.push({0, 0}); // Start with vertex 0 and weight 0

        while (!Q.empty())
        {                        // While there are vertices left to process
            auto best = Q.top(); // Get the edge with the minimum weight
            Q.pop();             // Remove the edge from the priority queue

            int to = best.second;    // Destination vertex of the edge
            int weight = best.first; // Weight of the edge

            if (visited[to])
            { // If the destination vertex has already been visited, skip it
                continue;
            }

            ans += weight;      // Add the weight of the edge to the total weight of the minimum spanning tree
            visited[to] = true; // Mark the destination vertex as visited

            for (auto x : l[to])
            { // Iterate over the neighbors of the destination vertex
                if (!visited[x.first])
                {                                // If the neighbor has not been visited
                    Q.push({x.second, x.first}); // Add the neighbor to the priority queue with its weight
                }
            }
        }

        delete[] visited; // Free memory allocated for the visited array
        return ans;       // Return the total weight of the minimum spanning tree
    }
};

void solve()
{
    Graph g(4);         // Create a graph with 4 vertices
    g.addEdge(0, 1, 1); // Add edges with weights
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 4);
    g.addEdge(2, 3, 5);

    cout << "Minimum Spanning Tree Weight: " << g.prim_mst() << endl; // Find and print the weight of the minimum spanning tree
}

// void solve()
// {
//     int n, m;
//     cin >> n >> m;

//     Graph g(n);
//     for (int i = 0; i < m; i++)
//     {
//         int x, y, w;
//         cin >> x >> y >> w;

//         g.addEdge(x - 1, y - 1, w);
//     }

//     cout << g.prim_mst() << nline;
// }

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