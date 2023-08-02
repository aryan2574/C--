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

class Stack
{
private:
    string *arr;
    int top;

public:
    Stack()
    {
        arr = new string;
        top = -1;
    }

    void push(string val)
    {
        if (top == arr.length() - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = val;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "No element to pop" << endl;
            return;
        }
        top--;
    }

    string top_ele()
    {
        if (top == -1)
        {
            return "Empty";
        }
        return arr[top];
    }

    bool empty()
    {
        return top == -1;
    }
};

void reverseString(Stack *st, string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        string ch = "";
        while (str[i] != ' ' && i < str.length())
        {
            ch += str[i];
            i++;
        }
        st->push(ch);
    }
    while (!st->empty())
    {
        cout << st->top_ele() << " ";
        st->pop();
    }
}

void solve()
{
    Stack *st = new Stack();
    string str;
    getline(cin, str);
    reverseString(st, str);
}

// _____________________________________________________________________________________
int main(void)
{
    aryan_2574_cp();
    solve();
}