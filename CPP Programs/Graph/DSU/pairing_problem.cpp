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
/*
Q-There are N cities numbered from 0 to N-1. You have to choose 2 cities such that there is no path from first city to second city .
You are given information in the form of M pairs (X,Y) i.e there is an undirected road between city X and city Y.
Find out the number of ways in which cities can be chosen.

Input Format:
The first line contains two integers, N and M separated by a single space. M lines follow. Each line contains integers separated by a single space X and Y denoting road between X and Y.

Constraints:
1 <= N <= 100000 1 <= M <= 100000 0 <= X,Y <= N-1

Output Format
An integer that denotes the number of permissible ways to choose a pair of cities.


I/P-
5 3
0 1
2 3
0 4

O/P-
6
*/

class Graph
{
    vector<pair<int, int>> edges;
    int V;

public:
    Graph(int V) : V(V) {}

    void addEdge(int u, int v)
    {
        edges.push_back({u, v});
    }

    int findSet(int i, vector<int> &parent)
    {
        if (parent[i] == -1)
            return i;
        return parent[i] = findSet(parent[i], parent);
    }

    void union_set(int x, int y, vector<int> &parent, vector<int> &size)
    {
        int s1 = findSet(x, parent);
        int s2 = findSet(y, parent);

        if (s1 != s2)
        {
            if (size[s1] < size[s2])
            {
                parent[s1] = s2;
                size[s2] += size[s1];
            }
            else
            {
                parent[s2] = s1;
                size[s1] += size[s2];
            }
        }
    }

    long long pairing()
    {
        vector<int> parent(V, -1);
        vector<int> size(V, 1);

        for (auto &edge : edges)
        {
            union_set(edge.first, edge.second, parent, size);
        }

        vector<int> setSizeCounts(V, 0);
        for (int i = 0; i < V; i++)
        {
            int root = findSet(i, parent);
            setSizeCounts[root]++;
        }

        long long totalPairs = 0;
        long long sum = 0;
        for (int cnt : setSizeCounts)
        {
            if (cnt > 0)
            {
                totalPairs += sum * cnt;
                sum += cnt;
            }
        }

        return totalPairs;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    Graph g(n);

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        g.addEdge(x, y);
    }

    cout << g.pairing() << nline;
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