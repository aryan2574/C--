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

// SPOJ - EXPEDI - Expedition
// https://www.spoj.com/problems/EXPEDI/

void solve()
{
    int t;
    cin >> t;

    while (t--)
    {
        int N;
        cin >> N;

        vector<pair<int, int>> stops(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> stops[i].first >> stops[i].second;
        }

        int L, P;
        cin >> L >> P;

        // Transform the stops distances from the truck's starting point
        for (int i = 0; i < N; ++i)
        {
            stops[i].first = L - stops[i].first;
        }

        // Sort stops by their distance from the starting point
        sort(stops.begin(), stops.end());

        // Max-heap to store the fuel amounts
        priority_queue<int> maxHeap;

        int currentFuel = P;
        int stopsCount = 0;
        int idx = 0;

        while (currentFuel < L)
        {
            // Add all reachable fuel stops to the max-heap
            while (idx < N && stops[idx].first <= currentFuel)
            {
                maxHeap.push(stops[idx].second);
                ++idx;
            }

            // If we can't reach any further and the max-heap is empty, it's impossible
            if (maxHeap.empty())
            {
                stopsCount = -1;
                break;
            }

            // Refuel with the largest amount available
            currentFuel += maxHeap.top();
            maxHeap.pop();
            ++stopsCount;
        }

        cout << stopsCount << '\n';
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