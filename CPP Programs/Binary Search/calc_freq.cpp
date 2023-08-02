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

int findIdx(int *arr, int size, int key, bool firstOcc) // We are using single function to calculate both first and
{                                                       // last occ for the key using bool
    int low = 0, high = size - 1, ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            if (firstOcc) // For first occ our sample space will be at the first half part of the array
                high = mid - 1;
            else
                low = mid + 1; // For second occ our sample space will be at second half part of the array
        }
        else if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return ans;
}

void solve()
{
    int n = 10, key = 4;
    int arr[n] = {1, 2, 3, 4, 4, 4, 4, 4, 5, 6};
    int size = sizeof(arr) / sizeof(int);

    int firstOcc = findIdx(arr, size, key, true), lastOcc = findIdx(arr, size, key, false);

    if (firstOcc != -1)
    {
        cout << "Total Frequency of the Key : " << (lastOcc - firstOcc) + 1 << nline;
    }
    else
        cout << "Element not found";
}

// _____________________________________________________________________________________
int main(void)
{
    ayush_2574_cp();
    solve();
    return 0;
}