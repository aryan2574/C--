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

// Friends problem:
/*
Given N friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.
Note: Since answer can be very large, return your answer mod 10^9+7.


Example 1:

Input:N = 3
Output: 4
Explanation:
{1}, {2}, {3} : All single
{1}, {2,3} : 2 and 3 paired but 1 is single.
{1,2}, {3} : 1 and 2 are paired but 3 is single.
{1,3}, {2} : 1 and 3 are paired but 2 is single.
Note that {1,2} and {2,1} are considered same.
*/

/*
To solve the problem of counting the number of ways to pair up or leave friends single, we can use a dynamic programming approach. The problem can be broken down using a recurrence relation based on whether a particular friend remains single or is paired with another friend.
Recurrence Relation

    If the ii-th friend remains single, then the problem reduces to i−1i−1 friends.
    If the ii-th friend pairs up with any of the (i−1)(i−1) other friends, the problem reduces to (i−2)(i−2) friends and there are (i−1)(i−1) ways to choose a pair.

Hence, the recurrence relation can be derived as:
F(n)=F(n−1)+(n−1)×F(n−2)F(n)=F(n−1)+(n−1)×F(n−2)

Where:

    F(n)F(n) is the number of ways to pair up or leave nn friends single.
    F(n−1)F(n−1) represents the case when the nn-th friend is single.
    (n−1)×F(n−2)(n−1)×F(n−2) represents the cases where the nn-th friend pairs with one of the (n−1)(n−1) friends.

Base Cases

    F(0)=1F(0)=1: One way to pair zero friends.
    F(1)=1F(1)=1: One way to leave one friend single.
    F(2)=2F(2)=2: Two ways (either both single or one pair).

Implementation

Using the above recurrence relation, we can compute the number of ways for nn friends iteratively and efficiently using dynamic programming.
*/

int countFriendsPairingsOptimised(int n)
{
    // Base cases
    if (n <= 2)
        return n;

    long long a = 1; // dp[0]
    long long b = 1; // dp[1]
    long long c = 2; // dp[2]

    for (int i = 3; i <= n; i++)
    {
        long long temp = (c + (i - 1) * b) % mod;
        a = b;
        b = c;
        c = temp;
    }

    return c;
}

int countFriendsPairings(int n)
{
    // Base cases
    if (n <= 2)
        return n;

    // Create a table to store results of subproblems
    vector<long long> dp(n + 1, 0);

    // Fill the base cases
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    // Fill dp[] in bottom-up manner using the recursive relation
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + (i - 1) * dp[i - 2]) % mod;
    }

    return dp[n];
}

void solve()
{
    int n;
    cin >> n;
    cout << countFriendsPairings(n) << endl;
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