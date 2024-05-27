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

// Function as objects

/*
Functional operators, also known as function call operators, in C++ allow you to create objects that can be called as if they were functions. This concept is particularly useful for creating function objects (functors), which can be used in place of function pointers and can maintain state.
*/

/*
    Class Definition with Function Call Operator:
        The class Fun has an overloaded operator() which takes a const string& as an argument.
        This operator allows an instance of Fun to be called like a regular function.

    Const Correctness:
        The operator() is marked as const to indicate that calling this operator does not modify the state of the object.
        This is a good practice, especially if your functor is not supposed to change its state when called.

    Using the Functor:
        In the solve function, an instance of Fun is created.
        The instance f is then used as if it were a function: f("C++");.
        This calls the overloaded operator(), which prints the message to the console.

Benefits of Function Objects (Functors)

    Maintain State:
        Unlike regular functions, functors can maintain state. This is useful in scenarios where you need to keep track of some data across multiple function calls.

    Flexibility:
        Functors can be more flexible than function pointers. You can create multiple instances of the same functor with different states.

    Performance:
        Inlining functors can result in better performance as compared to function pointers, which can reduce the overhead of a function call.

    Use in Algorithms:
        Functors are widely used in C++ Standard Template Library (STL) algorithms. For example, std::sort can take a functor as a comparator.
*/

class Counter
{
private:
    int count;

public:
    Counter() : count(0) {}

    // Overload the function call operator
    void operator()(const string &s)
    {
        cout << "Processing: " << s << " - Count :" << count << nline;
        ++count;
    }

    int getCount() const { return count; }
};

class Fun
{
public:
    void operator()(string s)
    {
        cout << "Having fun with: " << s << nline;
    }
};

void solve()
{
    // Fun f;
    // f("C++");

    vector<string> words = {"C++", "is", "fun", "and", "powerful"};
    Counter c; // Create an instance of the Counter class

    // Use for_each algorithm with the Counter functor
    for_each(words.begin(), words.end(), c);

    cout << "Processed " << c.getCount() << " words." << nline;
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