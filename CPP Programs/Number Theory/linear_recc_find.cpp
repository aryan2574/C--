#include <bits/stdc++.h>
using namespace std;

#define mod 1000000000
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

// Ques : https://www.spoj.com/problems/SEQ/
// There is a linear recurrence given. Find the value of f(n).

ll k;
vector<ll> a, b, c;

vector<vector<ll>> multiplyMatrix(vector<vector<ll>> A, vector<vector<ll>> B)
{
    // temp matrix
    vector<vector<ll>> M(k + 1, vector<ll>(k + 1));

    // Logic to multiply matrices
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            for (int x = 1; x <= k; x++)
            {
                M[i][j] = (M[i][j] + (A[i][x] * B[x][j]) % mod) % mod;
            }
        }
    }
    return M;
}

vector<vector<ll>> calExpoMat(vector<vector<ll>> A, ll p)
{
    // base case
    if (p == 1)
        return A;

    // if power is odd - we do A * A^(p-1)
    if (p & 1)
    {
        return multiplyMatrix(A, calExpoMat(A, p - 1));
    }
    // else if even - we do A^(n/2) * A^(n/2)
    vector<vector<ll>> subProblem = calExpoMat(A, p / 2);
    return multiplyMatrix(subProblem, subProblem);
}

ll compute(ll n)
{
    // base case
    if (n == 0)
        return 0;

    if (n <= k)
        return b[n - 1];

    // Ohterwise compute nth term using matrix exponentiation

    // Step - 1 : Create F1 vector
    vector<ll> F1(k + 1); // We are doing indexing from 1
    for (int i = 1; i <= k; i++)
    {
        F1[i] = b[i - 1];
    }

    // Step - 2 : Build transformation matrix
    vector<vector<ll>> T(k + 1, vector<ll>(k + 1)); // We are doing indexing from 1 that's why K+1
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i < k) // For all other rows except the last one - Fill 1 and 0 at respective positions
            {
                if (j == (i + 1))
                    T[i][j] = 1;
                else
                    T[i][j] = 0;
            }
            else // This is for last row - we are filling coefficients in the reverse order
            {
                T[i][j] = c[k - j];
            }
        }
    }

    // Step - 3 : Calculate exponential matrix - T^n-1
    T = calExpoMat(T, n - 1);

    // Step - 4 : Multiply T^n-1 and F1
    // We do not need to multiply whole T^n-1 and F1. Since, we only need value of f(n) we can multiply first row of T^n-1 and first col of F1
    // to get the answer.

    ll res = 0;
    for (int i = 1; i <= k; i++)
    {
        res = (res + (T[1][i] * F1[i]) % mod) % mod;
    }

    return res;
}

void solve()
{
    ll t, n, num;
    cin >> t;

    while (t--)
    {
        cin >> k;

        // Make vector F1
        for (int i = 0; i < k; i++)
        {
            cin >> num;
            b.push_back(num);
        }

        // Take coefficients
        for (int i = 0; i < k; i++)
        {
            cin >> num;
            c.push_back(num);
        }

        // Take power - n
        cin >> n;
        cout << compute(n) << nline;

        // Clear the vector
        b.clear();
        c.clear();
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