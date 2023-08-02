#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define mod1 998244353
#define INF 1e18
#define PI 3.141592653589793238462
#define nline "\n"
#define sz(x) ((int)(x).size())
#define set_bits __builtin_popcountll
#define setp(x, y) fixed << setprecision(y) << x
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

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
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}
// ____________________________________________________________________________________

void solve()
{
    int row(4), col(4);
    int arr[row][col] = {{10, 20, 30, 40},
                         {15, 25, 35, 45},
                         {27, 29, 37, 48},
                         {32, 33, 39, 50}};

    int key(32);
    pair<int, int> ans(-1, -1);

    // Approach 1 : Brute Force - O( n * m)

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == key)
            {
                ans.first = i;
                ans.second = j;
                break;
            }
        }
    }
    cout << ans.first << " " << ans.second << nline;

    // Approach 2 : Staircase Search - O(n + m)

    int r(0), c(col - 1);
    while (r < row && c >= 0)
    {
        if (arr[r][c] == key)
        {
            ans.first = r;
            ans.second = c;
            break;
        }
        if (arr[r][c] > key)
        {
            --c;
        }
        else
            ++r;
    }
    cout << ans.first << " " << ans.second << nline;

    // Approach 3 : Binary Search - O ( log n * log m )
    // To apply binary search we need array with a conditon that
    //  the first integer of each row is greater than the last integer of the previous row

    int row2 = 3, col2 = 4;

    int matrix[row2][col2] = {{1, 3, 5, 7},
                              {10, 11, 16, 20},
                              {23, 30, 34, 60}};

    int key2 = 9;

    if (key2 < matrix[0][0] || key2 > matrix[row2 - 1][col2 - 1])
    {
        cout << -1 << " " << -1;
    }

    else
    {
        int low = 0, high = row2 - 1, r(-1), c(-1);

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (matrix[mid][0] <= key2 && key2 <= matrix[mid][col2 - 1])
            {
                r = mid;
                break;
            }
            else if (matrix[mid][0] < key2)
                low = mid + 1;
            else
                high = mid - 1;
        }

        low = 0, high = col2 - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (matrix[r][mid] == key2)
            {
                c = mid;
                break;
            }
            else if (matrix[r][mid] < key2)
                low = mid + 1;
            else
                high = mid - 1;
        }
        cout << r << " " << c << nline;
    }

    // Approach 4 : Binary Search - O (log m * n)
    // to access row :  mid / total_col
    // to access col :  mid % total_col

    if (key2 < matrix[0][0] || key2 > matrix[row2 - 1][col2 - 1])
    {
        cout << -1 << " " << -1;
    }

    else
    {
        int low = 0, high = (row2 * col2) - 1, r(-1), c(-1);

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (matrix[mid / col2][mid % col2] == key2)
            {
                r = mid / col2;
                c = mid % col2;
                break;
            }
            else if (matrix[mid / col2][mid % col2] > key2)
                high = mid - 1;
            else
                low = mid + 1;
        }
        cout << r << " " << c << nline;
    }
}

// _____________________________________________________________________________________
int main(void)
{
    ayush_2574_cp();
    solve();
    return 0;
}