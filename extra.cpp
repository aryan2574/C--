#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define mod1 998244353
#define INF 1e18
#define PI 3.141592653589793238462
#define nline "\n"
#define mp make_pair
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define set_bits __builtin_popcountll
#define setp(x, y) fixed << setprecision(y) << x
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;

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
void _print(ld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

void ayush_2574_cp()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}
// ____________________________________________________________________________________

#define n 3

void solve()
{
    int row(n), col(n), sum(0);
    int arr[row][col] = {{1, 2, 3},
                         {4, 5, 6},
                         {7, 8, 9}};

    int dp[row + 1][col + 1];
    memset(dp, 0, sizeof(dp));

    for (int j = 1; j < col + 1; j++)
    {
        dp[1][j] = arr[0][j - 1];
    }

    for (int i = 2; i < row + 1; i++)
    {
        for (int j = 1; j < col + 1; j++)
        {
            dp[i][j] += dp[i - 1][j] + arr[i - 1][j - 1];
        }
    }

    for (int i = 0; i < row + 1; i++)
    {
        for (int j = 1; j < row + 1; j++)
        {
            dp[i][j] += dp[i][j - 1];
        }
    }

    for (int i = 0; i < row + 1; i++)
    {
        for (int j = 0; j < col + 1; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << nline;
    }

    for (int tlx = 1; tlx < row + 1; tlx++)
    {
        for (int tly = 1; tly < col + 1; tly++)
        {
            for (int brx = tlx; brx < row + 1; brx++)
            {
                for (int bry = tly; bry < col + 1; bry++)
                {
                    sum += dp[brx][bry] - dp[tlx - 1][bry] - dp[brx][tly - 1] + dp[tlx - 1][tly - 1];
                }
            }
        }
    }

    cout << sum;
}

// _____________________________________________________________________________________
int main(void)
{
    ayush_2574_cp();
    solve();
    return 0;
}