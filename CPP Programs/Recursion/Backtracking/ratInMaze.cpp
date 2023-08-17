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

// Problem : Rat in a maze

// Idea : Start then go right : find the way
// Go Left : find the way
// If not possible : return false
// If reached the destination : print the maze (path) and return true;
// Backtrack : make the path same as before and start finding some other paths

bool ratInMaze(char maze[10][10], int soln[][10], int i, int j, int m, int n)
{
    // Base Case
    if (i == m && j == n)
    {
        soln[m][n] = 1;

        // Print soln matrix
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << soln[i][j] << ' ';
            }
            cout << nline;
        }
        cout << nline;

        return true;
    }

    // Rat should be inside the grid
    if (i > m || j > n)
        return false;

    if (maze[i][j] == 'X')
        return false;

    // Assume solution exists through current cell
    soln[i][j] = 1;

    bool rightSuccess = ratInMaze(maze, soln, i, j + 1, m, n);
    bool downSuccess = ratInMaze(maze, soln, i + 1, j, m, n);

    // Backtracking
    soln[i][j] = 0;

    if (rightSuccess || downSuccess)
        return true;
    return false;
}

void solve()
{
    char maze[10][10] = {
        "0000",
        "00X0",
        "000X",
        "0X00",
    };
    int soln[10][10] = {0};

    int m(4), n(4);

    bool ans = ratInMaze(maze, soln, 0, 0, m - 1, n - 1);

    if (ans == false)
        cout << "Path does not exist!" << nline;
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