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

bool isValidPos(int *positionOfStalls, int numberOfStalls, int numberOfCows, int midPos)
{
    int currCows(1), currPos(positionOfStalls[0]);

    for (int i = 1; i < numberOfStalls; ++i)
    {
        if (positionOfStalls[i] - currPos >= midPos)
        {
            ++currCows;
            currPos = positionOfStalls[i];
        }
    }
    if (currCows >= numberOfCows)
        return true;
    else
        return false;
}

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int numberOfStalls, numberOfCows;
        cin >> numberOfStalls >> numberOfCows;

        int positionOfStalls[numberOfStalls];
        for (int i = 0; i < numberOfStalls; i++)
            cin >> positionOfStalls[i];

        sort(positionOfStalls, positionOfStalls + numberOfStalls);

        int mnPos(1), mxPos(positionOfStalls[numberOfStalls - 1] - positionOfStalls[0]), ans(-1);

        while (mxPos - mnPos > 1)
        {
            int midPos = mnPos + (mxPos - mnPos) / 2;

            if (isValidPos(positionOfStalls, numberOfStalls, numberOfCows, midPos))
            {
                ans = midPos;
                mnPos = midPos;
            }
            else
                mxPos = midPos - 1;
        }
        if (isValidPos(positionOfStalls, numberOfStalls, numberOfCows, mxPos))
            cout << mxPos << nline;
        else if (isValidPos(positionOfStalls, numberOfStalls, numberOfCows, mnPos))
            cout << mnPos << nline;
    }
}

// _____________________________________________________________________________________
int main(void)
{
    ayush_2574_cp();
    solve();
    return 0;
}