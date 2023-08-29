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

// Bucket Sort - O(N)

/*
Idea : It is similar to counting sort. Here, there is a bucket(object) and we sort according to an attribute.
Here bucket is a class - Student with marks and name. We know range of marks lies between 1-100.
We create a freq array but this time it will be array of vectors of type Student.
We will push into our array[{Student 1 , Student 2}, Student 4...] according to the marks obtained.
*/

/*
Input:
6
A 4
B 87
C 55
D 99
G 78
I 5

Output:
D 99
B 87
G 78
C 55
I 5
A 4
*/

class Student
{
public:
    string name;
    int marks;
};

void solve()
{
    // Student
    Student s[100];

    int n;
    cin >> n;

    // Input student name and marks
    for (int i = 0; i < n; i++)
        cin >> s[i].name >> s[i].marks;

    // Vector of Student class -> We will push all student objects which have same marks
    vector<Student> students[101];

    for (int i = 0; i < n; i++)
    {
        int currStudentMark = s[i].marks;
        students[currStudentMark].push_back(s[i]);
    }

    // Iterator
    vector<Student>::iterator it;

    // Print Students according to marks (Sort in Descending order)
    for (int marks = 100; marks >= 0; marks--)
    {
        for (it = students[marks].begin(); it != students[marks].end(); it++)
        {
            cout << (*it).name << ' ' << (*it).marks << nline;
        }
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