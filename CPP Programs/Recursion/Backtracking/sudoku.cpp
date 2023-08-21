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

const int N = 9;

void printMatrix(int matrix[][N], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << nline;
    }
    cout << nline;
}

bool canWePlace(int matrix[][N], int N, int i, int j, int currNum)
{
    // Check for current row and col
    for (int x = 0; x < N; x++)
    {
        if (matrix[x][j] == currNum || matrix[i][x] == currNum)
            return false;
    }

    // Check in the current sub-matrix
    // Start Index of current sub-matrix -
    // sx = (i / sqrt(N)) * sqrt(N)
    // sy = (j / sqrt(N)) * sqrt(N)

    int n = sqrt(N);
    int sx = (i / n) * n;
    int sy = (j / n) * n;

    for (int p = sx; p < sx + n; p++)
    {
        for (int q = sy; q < sy + n; q++)
        {
            if (matrix[sx][sy] == currNum)
            {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(int matrix[][N], int N, int i, int j)
{
    // Base Case
    // Idea : If i == N, it means we have checked for each row and print the matrix and return true
    if (i == N)
    {
        // print matrix
        printMatrix(matrix, N);
        return true;
    }

    // Edge cases
    // If we are at end of the current row - last col : call for next row and first col
    if (j == N)
    {
        // Return the sudoku solver with next row and first col
        return solveSudoku(matrix, N, i + 1, 0);
    }

    // If there is already a number in the matrix : call for next col
    if (matrix[i][j] != 0)
    {
        // Return the sudoku solver with next col
        return solveSudoku(matrix, N, i, j + 1);
    }

    // Recursive Case
    // Idea : we need to check for each number from 1 to N, whether we can place it at current position or not
    // If we can place it, we assume it to be the solution and return true
    // If no options are left - then backtrack and put 0 at the current position
    for (int currNum = 1; currNum <= N; currNum++)
    {
        if (canWePlace(matrix, N, i, j, currNum))
        {
            // Place the current number
            matrix[i][j] = currNum;

            // Call for recursion for next col
            bool nextNumberRakhPaye = solveSudoku(matrix, N, i, j + 1);

            if (nextNumberRakhPaye == true)
                return true;
        }
    }
    // If we can not place any of the number from 1 to N : backtrack place 0 and return false
    matrix[i][j] = 0;
    return false;
}

void solve()
{
    // Sudoku matrix
    int matrix[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                        {5, 2, 0, 0, 0, 0, 0, 0, 0},
                        {0, 8, 7, 0, 0, 0, 0, 3, 1},
                        {0, 0, 3, 0, 1, 0, 0, 8, 0},
                        {9, 0, 0, 8, 6, 3, 0, 0, 5},
                        {0, 5, 0, 0, 9, 0, 6, 0, 0},
                        {1, 3, 0, 0, 0, 0, 2, 5, 0},
                        {0, 0, 0, 0, 0, 0, 0, 7, 4},
                        {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    solveSudoku(matrix, N, 0, 0);
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