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

const int N = 100; //SIZE OF QUEUE
class Queue
{
private:
    int *arr;
    int front;
    int back;

public:
    //Constructor
    Queue()
    {
        arr = new int[N];
        front = -1; //Inittialising the value of front and back to -1
        back = -1;
    }

    //ENQUEUE function of QUEUE
    void enque(int val)
    {
        if (back == N - 1)
        {
            cout << "Queue Overflow" << nline;
            return;
        }
        back++;          //Incrementing back
        arr[back] = val; //Asigning value to the array

        if (front == -1) //When queue is empty we will increment front
        {
            front++;
        }
    }

    //EMPTY Function of QUEUE
    bool empt()
    {
        return front == -1 || front > back;
    }

    //DEQUEUE Function of QUEUE
    void deque()
    {
        if (!empt())
            front++;
    }

    //PEEK function of QUEUE
    int pek()
    {
        if (!empt())
            return arr[front];
        else
            return -1;
    }
};

void solve()
{
    Queue q;
    q.enque(5);
    q.enque(6);
    q.enque(7);
    cout << q.pek() << nline;
    q.deque();
    cout << q.pek() << nline;
    q.deque();
    q.deque();
    cout << q.pek();
}

// _____________________________________________________________________________________
int main(void)
{
    aryan_2574_cp();
    solve();
}