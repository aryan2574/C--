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

// Given two integers a and b, return the sum of the two integers without using the operators + and -.
// Link - https://leetcode.com/explore/learn/card/bit-manipulation/670/bit-manipulation-practice/4260/discuss/132479/Simple-explanation-on-how-to-arrive-at-the-solution

/*
The core concept behind this code is simulating binary addition with bitwise operations. Let's go through the process step by step:

**Inputs**:
Suppose you want to add two decimal numbers, `x` and `y`, using binary representation. We'll also consider that you're using 8-bit integers for simplicity.

**Step 1 - Initializing Variables**:
- `carry` is initially set to 0. This variable keeps track of the carry bit when adding binary digits.

**Step 2 - The Loop**:
The code uses a `while` loop that continues until `y` becomes 0. In each iteration, the code simulates adding binary digits from the least significant bit (LSB) to the most significant bit (MSB).

**Step 3 - Generating Carry (`carry = x & y`)**:
- `carry` is calculated by performing a bitwise AND operation between `x` and `y`. This operation isolates the bits where both `x` and `y` have 1s (the bits that will generate a carry in binary addition). For example, if `x` is `1101` and `y` is `1010`, `carry` becomes `1000`, which represents the bit positions where both `x` and `y` have 1s.

**Step 4 - Updating `x` (`x = x ^ y`)**:
- `x` is updated by performing a bitwise XOR operation between `x` and `y`. XOR is used because it simulates adding bits without considering the carry. For example, if `x` is `1101` and `y` is `1010`, `x` becomes `0111`, which represents the bits where there are 1s in either `x` or `y`.

**Step 5 - Updating `y` (`y = carry << 1`)**:
- The `carry` is shifted one position to the left. This represents the carry that will be added to the next pair of bits. Shifting left by one is equivalent to multiplying the carry by 2, just as in manual binary addition. For example, if `carry` is `1000`, it becomes `0000` in `y`, which is the effect of shifting the carry to the left.

**Step 6 - Loop Continuation or Termination**:
- The loop continues, simulating the next pair of binary digits (bits) for addition.
- The loop ends when `y` becomes 0, indicating that all the bits have been added.

**Step 7 - Return Result (`return x`)**:
- The code returns the final result stored in `x` after the loop. `x` now contains the binary representation of the sum of the original `x` and `y`.

Here's a simplified example with 4-bit numbers:

Suppose you want to add 3 (`0011` in binary) and 5 (`0101` in binary):

- In the first iteration, `carry` is `0001`, `x` is `0110`, and `y` is `0000`.
- In the second iteration, `carry` is `0010`, `x` is `0100`, and `y` is `0000`.
- In the third iteration, `carry` is `0000`, `x` is `0110`, and `y` is `0000`.

The final result in `x` is `0110`, which is 6 in decimal, the correct sum of 3 and 5.

The code essentially processes the binary digits one by one, handles carry bits correctly, and mimics binary addition using bitwise operations. This is the inner logic of how it works.
*/

int getSum(int x, int y)
{
    unsigned carry;
    while (y != 0)
    {
        // generate carry
        carry = x & y;
        // xor x,y and assign the result into x
        x = x ^ y;
        // left shift carry and assign into y
        y = carry << 1;
    }
    return x;
}

void solve()
{
    int a = -500, b = 50;
    cout << getSum(a, b) << nline;
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