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

// Ques : https://www.spoj.com/problems/MPOW/

// Function to print the matrix
void printMatrix(vector<vector<ll>> mat, ll m)
{
    for (auto i = 0; i < m; i++)
    {
        for (auto j = 0; j < m; j++)
        {
            cout << mat[i][j] << ' ';
        }
        cout << nline;
    }
}

// Function to multiply two matrix and do their mod for larger numbers
vector<vector<ll>> multiplyMatrix(vector<vector<ll>> A, vector<vector<ll>> B, ll m)
{
    vector<vector<ll>> temp(m + 1, vector<ll>(m + 1));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < m; k++)
            {
                temp[i][j] = (temp[i][j] % mod + ((A[i][k] % mod) * (B[k][j] % mod) % mod)) % mod;
            }
        }
    }
    return temp;
}

// Calculate exponent of a matrix - mat^n   : m - dimension of square matrix
vector<vector<ll>> compute(vector<vector<ll>> mat, ll m, ll n)
{
    // base case
    if (n == 1)
    {
        return mat;
    }

    // power is odd - mat * mat^n-1     eg: a^3 =  a * a^3-1 => a * a^2
    if (n & 1)
    {
        return multiplyMatrix(mat, compute(mat, m, n - 1), m);
    }
    // power is even
    vector<vector<ll>> subProblem = compute(mat, m, n / 2);
    return multiplyMatrix(subProblem, subProblem, m);
}

// Another way to calculate exponent
vector<vector<ll>> compute2(vector<vector<ll>> mat, ll m, ll n) // mat - matrix , m - dimension, n - power
{
    // base case
    if (n == 1)
        return mat;

    // sub problem
    vector<vector<ll>> subProblem = compute(mat, m, n / 2);

    // if n is odd
    if (n & 1)
    {
        vector<vector<ll>> temp = multiplyMatrix(subProblem, subProblem, m);
        return multiplyMatrix(temp, mat, m);
    }
    // if n is even
    else
        return multiplyMatrix(subProblem, subProblem, m);
}

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll m, n;
        cin >> m >> n;
        vector<vector<ll>> mat(m + 1, vector<ll>(m + 1));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        mat = compute(mat, m, n);

        printMatrix(mat, m);
        cout << nline << nline;
        mat = compute2(mat, m, n);
        printMatrix(mat, m);
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