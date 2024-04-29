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
    int V;
    list<pair<int, int>> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int cost)
    {
        l[u].push_back(make_pair(v, cost));
        l[v].push_back(make_pair(u, cost)); // Edge is bidirectional
    }

    // DFS helper function to calculate subtree sizes and total travel distance
    int dfsHelper(int node, bool *visited, int *count, int &ans)
    {
        // Mark the node as visited
        visited[node] = true;
        count[node] = 1; // Initially, the subtree size is 1 (current node)

        for (const auto &nbr_pair : l[node])
        {
            int nbr = nbr_pair.first; // Neighbor node
            int wt = nbr_pair.second; // Edge weight

            if (!visited[nbr])
            {
                count[node] += dfsHelper(nbr, visited, count, ans); // Update subtree size
                int nx = count[nbr];                                // Size of subtree rooted at neighbor node
                int ny = V - nx;                                    // Size of remaining subtree

                ans += 2 * min(nx, ny) * wt; // Update total travel distance
            }
        }

        // Return the total size of the subtree rooted at the current node
        return count[node];
    }

    // DFS traversal to find the best plan maximizing the total travel distance
    int dfs()
    {
        // Initialize arrays to keep track of visited nodes and subtree sizes
        bool *visited = new bool[V];
        int *count = new int[V];

        // Initialize arrays with default values
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
            count[i] = 0;
        }

        int ans = 0; // Total travel distance

        // Start DFS traversal from the first city (node 0)
        dfsHelper(0, visited, count, ans);

        // Free dynamically allocated memory
        delete[] visited;
        delete[] count;

        // Return the total travel distance
        return ans;
    }
};

void solve()
{
    int T;
    cin >> T; // Number of test cases

    for (int t = 1; t <= T; t++)
    {
        int N;
        cin >> N; // Number of cities

        // Create a graph with N cities
        Graph g(N);

        // Input highways information
        for (int i = 0; i < N - 1; i++)
        {
            int X, Y, Z;
            cin >> X >> Y >> Z;         // City X, City Y, Highway length
            g.addEdge(X - 1, Y - 1, Z); // Add edge (1-based indexing to 0-based indexing)
        }

        // Calculate the maximum total travel distance for the current test case
        int max_distance = g.dfs();

        // Output the result for the current test case
        cout << "Case #" << t << ": " << max_distance << endl;
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