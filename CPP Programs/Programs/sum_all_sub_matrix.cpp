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

void aryan_2574_cp()
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
    int arr[row][col] = {{1, 1, 1},
                         {1, 1, 1},
                         {1, 1, 1}};
    //____________________________________________________________________________________________
    // Method : 1     Time :  O(N^6)      | Brute force
    //  Since we have two coordinate for each box in a matrix we are taking first top left coordinate
    //  in the first two loop and then bottom right coordinate in the second two loop. And then we are
    //  traversing between those coordinates and calculating the sum.We can find the size of the sub-
    //  matrices by finding top left and bottom right coordinate.
    for (int tli = 0; tli < row; tli++)
    {
        for (int tlj = 0; tlj < col; tlj++)
        {
            for (int bri = tli; bri < row; bri++)
            {
                for (int brj = tlj; brj < col; brj++)
                {
                    for (int i = tli; i <= bri; i++)
                    {
                        for (int j = tlj; j <= brj; j++)
                        {
                            sum += arr[i][j];
                        }
                    }
                }
            }
        }
    }
    cout << sum;

    //____________________________________________________________________________________
    // Method : 2   - Using Prefix Array    Time: O(N^4)        Extra Space
    int dp[row + 1][col + 1];
    memset(dp, 0, sizeof(dp));

    // Copying the first row
    for (int j = 1; j < col + 1; j++)
    {
        dp[1][j] = arr[0][j - 1];
    }

    // Adding Rows
    for (int i = 2; i < row + 1; i++)
    {
        for (int j = 1; j < col + 1; j++)
        {
            dp[i][j] += dp[i - 1][j] + arr[i - 1][j - 1];
        }
    }

    // Adding Columns
    for (int i = 0; i < row + 1; i++)
    {
        for (int j = 1; j < row + 1; j++)
        {
            dp[i][j] += dp[i][j - 1];
        }
    }

    // Iterating though each position and using our formula
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

    //____________________________________________________________________________________
    // Method : 3  - Using Formula         Time: O(N^2)
    // First we have to select a square box in the matrix and check in which all other
    // submatrices it will be present. For that we will first select top left
    // and bottom right. We will traverse through each sub matrix and calcuate the total sum for that
    // particular box in the whole matrix(total number of times it'll be present in different sub matrices).
    // Our aim is to find the toal number of sub matrices with our selected square box included.
    // For aur arr[i][j] box we are calculating top left and bottom right and finding total number of
    // sub matrices.
    // Area of rectangle = (x2-x1+1) * (y2-y1+1)
    // In this wasy we are finding total sum of that particular box in the whole
    // matrix and similarly we have to calculate sum of all the boxes

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int top_left = (i + 1) * (j + 1);           // Choices to make top_left
            int bottom_right = (n - i) * (n - j);       // Choices to make bottom_right
            sum += top_left * bottom_right * arr[i][j]; // Total sum for our sub-matrix arr[i][j]
        }
    }
    cout << sum;

    //_____________________________________________________________________________________
    // Calulating the max sum of any sub matrix in the matrix when the matrix is in ascending order
    // We will create the prefix matrix just like what we did earlier. In this case we will go from bottom right
    // to top left and create our prefix matrix.
    //  {{-5, -4, -1}, ^            Prefix Matrix : 0 0 0 0
    //    {-3, 2, 4},  |                            0 8 14 11
    //    {2, 5, 8}};  |                            0 18 19 12
    //        <-------                              0 15 13 8

    vector<vector<int>> matrix = {{-5, -4, -1},
                                  {-3, 2, 4},
                                  {2, 5, 8}};

    int r = matrix.size(), c = matrix[0].size(), sum(0), mxsum(INT_MIN);
    int dp[r + 1][c + 1];
    memset(dp, 0, sizeof(dp));

    // Copying last row
    for (int j = c + 1; j > 0; --j)
    {
        dp[r][j] = matrix[r - 1][j - 1];
    }

    // Adding Rows to prev rows and saving it
    for (int i = r - 1; i > 0; --i)
    {
        for (int j = c; j > 0; --j)
        {
            dp[i][j] = dp[i + 1][j] + matrix[i - 1][j - 1];
        }
    }

    // Adding Cols to the next col and saving
    for (int i = r; i > 0; --i)
    {
        for (int j = c - 1; j > 0; --j)
        {
            dp[i][j] += dp[i][j + 1];
        }
    }

    // Finding the max sum in the array with just iterating over our sub matrix because our max sum is already
    // stored in the sub matrix sum we did earlier.

    for (int i = 0; i < r + 1; i++)
    {
        for (int j = 0; j < c + 1; j++)
        {
            sum = dp[i][j];
            mxsum = max(mxsum, sum);
        }
    }
    cout << mxsum; // OUTPUT: 19
    //______________________________________________________________________________
}

// _____________________________________________________________________________________
int main(void)
{
    aryan_2574_cp();
    solve();
    return 0;
}