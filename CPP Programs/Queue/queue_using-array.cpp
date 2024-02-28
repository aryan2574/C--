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

// QUEUE IMPLEMENTATION

// We take two variables - front , rear

#define N 5
int que[N];
int front = -1, rear = -1;

void enque(int x)
{
    // Check for overflow condition - rear at the last - QUEUE is full
    if (rear == N - 1)
    {
        cout << "Overflow\n";
    }
    // QUEUE is empty -> front = rear = -1
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        que[rear] = x;
    }
    // If already some data
    else
    {
        rear++;
        que[rear] = x;
    }
}

void deq()
{
    // If queue is empty
    if (front == -1 && rear == -1)
    {
        cout << "NO elements present" << nline;
    }
    // If there is only one element
    else if (front == rear)
    {
        front = rear = -1;
    }
    // Queue is not empty & there are more then 1 element
    else
    {
        cout << que[front] << nline;
        front++;
    }
}

void displayElements()
{
    // Empty queue condition
    if (front == -1 && rear == -1)
    {
        cout << "QUEUE is empty";
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            cout << que[i] << ' ';
        }
        cout << nline;
    }
}

void peek()
{
    // Empty queue condition
    if (front == -1 && rear == -1)
    {
        cout << "QUEUE is empty";
    }
    else
    {
        cout << "DATA at front - " << que[front] << nline;
    }
}

void solve()
{
    enque(1);
    enque(2);
    enque(3);
    enque(4);
    enque(5);

    displayElements();
    peek();

    deq();
    peek();

    displayElements();

    enque(6);
    displayElements();
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