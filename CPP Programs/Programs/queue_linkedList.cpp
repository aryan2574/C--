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

// Node class
class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

//QUEUE class
class Queue
{

    node *front;
    node *back;

public:
    //Constructor
    Queue()
    {
        front = NULL;
        back = NULL;
    }

    //ENQUEUE Function
    void enque(int val)
    {
        node *n = new node(val);
        if (front == NULL)
        {
            front = n;
            back = n;
            return;
        }
        back->next = n;
        back = n;
    }

    //DEQUEUE Function
    void deque()
    {
        if (empty())
        {
            cout << "Queue Underflow";
            return;
        }
        node *toDelete = front;
        front = front->next;
        delete toDelete;
    }

    //PEEK Function
    int peek()
    {
        if (empty())
        {
            cout << "Queue Underflow ";
            return -1;
        }
        return front->data;
    }

    //Empty Function
    bool empty()
    {
        return front == NULL;
    }
};

void solve()
{

    Queue q;
    q.enque(5);
    q.enque(6);
    q.enque(7);
    cout << q.peek() << nline;
    q.deque();
    cout << q.peek() << nline;
    q.deque();
    cout << q.peek() << nline;
    q.deque();
    cout << q.peek() << nline;
    cout << q.empty() << nline;
}

// _____________________________________________________________________________________
int main(void)
{
    aryan_2574_cp();
    solve();
}