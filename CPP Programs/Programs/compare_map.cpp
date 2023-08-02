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

template <typename T>
bool value_compare(T const &value1, T const &value2)
{
    auto pred = [](auto i, auto j)
    { return i.ss == j.ss; };

    return value1.size() == value2.size() && std::equal(value1.begin(), value1.end(), value2.begin(), pred);
}

void solve()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    string s4 = s1 + s2;
    map<char, int> m1;
    map<char, int> m2;
    fo(i, 0, s4.length()) m1[s4[i]]++;
    fo(i, 0, s3.length()) m2[s3[i]]++;
    if (value_compare(m1, m2))
        cout << "YES";
    else
        cout << "NO";
}

// _____________________________________________________________________________________
int main(void)
{
    aryan_2574_cp();
    solve();
}