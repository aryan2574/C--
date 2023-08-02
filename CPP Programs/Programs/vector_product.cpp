#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define mod1 998244353
#define INF 1e18
#define PI 3.141592653589793238462
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define set_bits __builtin_popcountll
#define setp(x, y) fixed << setprecision(y) << x
#define fo(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
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
void _print(lld t) { cerr << t; }
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

struct vect
{
    int x, y;

    vect() {}
    vect(int a, int b)
    {
        x = a;
        y = b;
    }
    void ip()
    {
        cin >> x >> y;
    }
};

vect operator-(vect a, vect b)
{
    return vect(a.x - b.x, a.y - b.y);
}
ll operator%(vect a, vect b)
{
    return ll(a.x) * b.y - ll(a.y) * b.x;
}

void solve()
{
    vect a, b, c;
    a.ip();
    b.ip();
    c.ip();
    vect ab = b - a, bc = c - b;
    if (ab % bc == 0)
        cout << "TOWARDS";
    else if (ab % bc > 0)
        cout << "LEFT";
    else
        cout << "RIGHT";
}

// _____________________________________________________________________________________
int main(void)
{
    aryan_2574_cp();
    solve();
}