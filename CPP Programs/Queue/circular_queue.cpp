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

class MyCircularQueue
{
private:
    vector<int> q;
    int start_p;
    int curr;
    int end_p;
    int size;

public:
    MyCircularQueue(int k)
    {
        q.resize(k);
        size = k;
        start_p = -1;
        curr = 0;
        end_p = -1;
    }

    bool enQueue(int value)
    {
        if (isFull())
        {
            return false;
        }

        end_p = (end_p + 1) % size;
        q[end_p] = value;
        if (start_p == -1)
        {
            start_p = 0;
        }
        curr++;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
        {
            return false;
        }

        if (start_p == end_p)
        {
            start_p = -1;
            end_p = -1;
        }
        else
        {
            start_p = (start_p + 1) % size;
        }
        curr--;
        return true;
    }

    int Front()
    {
        if (isEmpty())
        {
            return -1;
        }
        return q[start_p];
    }

    int Rear()
    {
        if (isEmpty())
        {
            return -1;
        }
        return q[end_p];
    }

    bool isEmpty()
    {
        return curr == 0;
    }

    bool isFull()
    {
        return curr == size;
    }
};

void solve()
{
    MyCircularQueue *myCircularQueue = new MyCircularQueue(3);
    cout << myCircularQueue->enQueue(1) << nline; // return True
    cout << myCircularQueue->enQueue(2) << nline; // return True
    cout << myCircularQueue->enQueue(3) << nline; // return True
    cout << myCircularQueue->enQueue(4) << nline; // return False
    cout << myCircularQueue->Rear() << nline;     // return 3
    cout << myCircularQueue->isFull() << nline;   // return True
    cout << myCircularQueue->deQueue() << nline;  // return True
    cout << myCircularQueue->enQueue(4) << nline; // return True
    cout << myCircularQueue->Rear() << nline;     // return 4

    delete myCircularQueue;
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