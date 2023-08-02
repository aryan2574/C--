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

vector<int> div2(vector<int> sum)
{
    vector<int> ans;
    int val = 0;
    for (int i = 0; i < sum.size(); i++)
    {
        if (val)
        {
            val = val * 10 + sum[i];
            ans.push_back(val / 2);
            val = val % 2;
        }
        else
        {
            if (sum[i] < 2)
            {
                val += sum[i];
                ans.push_back(0);
            }
            else
            {
                val = sum[i] % 2;
                ans.push_back(sum[i] / 2);
            }
        }
    }

    vector<int> arr;
    int i = 0;
    while (ans[i] == 0)
        i++;

    while (i < ans.size())
    {
        arr.push_back(ans[i]);
        i++;
    }
    return arr;
}

// Substraction of two Big Integers
vector<int> sub(vector<int> x, vector<int> y) // Substracting Y from X
{
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    vector<int> ans;

    int len = y.size();

    for (int i = 0; i < len; i++)
    {
        if (x[i] < y[i])
        {
            x[i + 1]--;
            ans.push_back(10 + x[i] - y[i]);
        }
        else
            ans.push_back(x[i] - y[i]);
    }

    if (x.size() > len)
    {
        for (int i = len; i < x.size(); i++)
        {
            if (x[i] < 0)
            {
                x[i + 1]--;
                ans.push_back(10 + x[i]);
            }
            else
            {
                ans.push_back(x[i]);
            }
        }
    }

    reverse(ans.begin(), ans.end());

    vector<int> arr;
    int i = 0;
    while (ans[i] == 0)
        i++;
    for (; i < ans.size(); i++)
        arr.push_back(ans[i]);

    return arr;
}

// Addition of two Big Integers
vector<int> add(vector<int> cnum, vector<int> dnum)
{
    reverse(cnum.begin(), cnum.end());
    reverse(dnum.begin(), dnum.end());

    vector<int> ans;

    int len = min(cnum.size(), dnum.size());

    int carry = 0;

    for (int i = 0; i < len; i++)
    {
        int val = cnum[i] + dnum[i] + carry;
        ans.push_back(val % 10);
        carry = val / 10;
    }

    if (cnum.size() > len)
    {
        for (int i = len; i < cnum.size(); i++)
        {
            int val = cnum[i] + carry;
            ans.push_back(val % 10);
            carry = val / 10;
        }
    }

    if (dnum.size() > len)
    {
        for (int i = len; i < dnum.size(); i++)
        {
            int val = dnum[i] + carry;
            ans.push_back(val % 10);
            carry = val / 10;
        }
    }

    while (carry > 0)
    {
        ans.push_back(carry % 10);
        carry = carry / 10;
    }

    reverse(ans.begin(), ans.end());

    vector<int> arr;
    int i = 0;
    while (ans[i] == 0)
        i++;
    for (; i < ans.size(); i++)
        arr.push_back(ans[i]);

    return arr;
}

void solve()
{
    int t = 1;
    while (t--)
    {
        string c, d;
        cin >> c >> d;

        vector<int> cnum;
        vector<int> dnum;

        for (size_t i = 0; i < c.length(); ++i)
        {
            cnum.push_back(c[i] - '0');
        }

        for (size_t i = 0; i < d.length(); ++i)
        {
            dnum.push_back(d[i] - '0');
        }

        vector<int> sum = add(cnum, dnum); // Adding two big integer
        vector<int> div = div2(sum);       // Dividing by 2

        for (int i = 0; i < div.size(); i++)
        {
            cout << div[i];
        }
        cout << nline;

        vector<int> diff = sub(cnum, div);
        for (int i = 0; i < diff.size(); i++)
        {
            cout << diff[i];
        }
        cout << nline;
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