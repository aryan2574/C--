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

// Reverse bits
// Link - https://leetcode.com/explore/learn/card/bit-manipulation/670/bit-manipulation-practice/4259/discuss/1232842/JAVA-C++-:-0ms-or-O(1)-Time-Complexity-or-in-place-or-Detailed-Explanation

/*
Reversing the bits in a binary number is a common operation in computer programming. This process can be better understood with the help of a diagram and a step-by-step explanation.

Let's say you have an 8-bit binary number "10101010" that you want to reverse. Here's how it's done:

Initial Binary Number:

10101010

Step 1: Swapping Pairs of Bits (16-Bit Block)

    Create two masks, mask1 and mask2, to isolate and swap pairs of bits.
    mask1 = 0xffff0000 isolates the leftmost 16 bits.
    mask2 = 0x0000ffff isolates the rightmost 16 bits.
    Use bitwise AND to preserve these isolated bits: num & mask1 and num & mask2.
    Shift mask1 to the right by 16 positions and mask2 to the left by 16 positions.
    Use bitwise OR to combine the results of shifting mask1 and mask2.
    This swaps the two 8-bit pairs:

01011010 01010101

Step 2: Swapping 4-Bit Blocks

    Create two masks again, mask1 and mask2, to isolate and swap 4-bit blocks.
    mask1 = 0xff00ff00 isolates the 4-bit blocks in the left and right halves of the 8-bit pairs.
    mask2 = 0x00ff00ff isolates the 4-bit blocks within each 8-bit pair.
    Use bitwise AND to preserve these isolated 4-bit blocks: num & mask1 and num & mask2.
    Shift mask1 to the right by 8 positions and mask2 to the left by 8 positions.
    Use bitwise OR to combine the results of shifting mask1 and mask2.
    This swaps the 4-bit blocks within each 8-bit pair:

00110011 11001100

Step 3: Swapping 2-Bit Blocks

    Create two masks, mask1 and mask2, to isolate and swap 2-bit blocks.
    mask1 = 0xf0f0f0f0 isolates the 2-bit blocks in the left and right halves of the 4-bit blocks.
    mask2 = 0x0f0f0f0f isolates the 2-bit blocks within each 4-bit block.
    Use bitwise AND to preserve these isolated 2-bit blocks: num & mask1 and num & mask2.
    Shift mask1 to the right by 4 positions and mask2 to the left by 4 positions.
    Use bitwise OR to combine the results of shifting mask1 and mask2.
    This swaps the 2-bit blocks within each 4-bit block:

00001111 11110000

Step 4: Swapping Individual Bits

    Create two masks, mask1 and mask2, to isolate and swap individual bits.
    mask1 = 0xcccccccc isolates the individual bits in the left and right halves of the 2-bit blocks.
    mask2 = 0x33333333 isolates the individual bits within each 2-bit block.
    Use bitwise AND to preserve these isolated individual bits: num & mask1 and num & mask2.
    Shift mask1 to the right by 2 positions and mask2 to the left by 2 positions.
    Use bitwise OR to combine the results of shifting mask1 and mask2.
    This swaps the individual bits within each 2-bit block:

00000001 11111110

Step 5: Swapping Single Bits

    Create two masks, mask1 and mask2, to isolate and swap single bits.
    mask1 = 0xaaaaaaaa isolates the individual bits in the left and right halves of the single bits.
    mask2 = 0x55555555 isolates the individual bits within each single bit.
    Use bitwise AND to preserve these isolated individual bits: num & mask1 and num & mask2.
    Shift mask1 to the right by 1 position and mask2 to the left by 1 position.
    Use bitwise OR to combine the results of shifting mask1 and mask2.
    This swaps the individual bits within each single bit:

00000010 11111101

Final Result:

0000001011111101

After performing these bitwise operations with the masks, the binary number has been reversed.

Note: The num & mask operation is used to preserve specific bits, and the | operation combines the results while swapping the bits. The masks help isolate and
*/

const int sze = 32;

void solve()
{
    bitset<sze> num("10101010");

    cout << num << nline;

    uint32_t mask1, mask2;

    mask1 = 0xffff0000, mask2 = 0x0000ffff;
    num = ((num & bitset<sze>(mask1)) >> 16) | ((num & bitset<sze>(mask2)) << 16);

    mask1 = 0xff00ff00, mask2 = 0x00ff00ff;
    num = ((num & bitset<sze>(mask1)) >> 8) | ((num & bitset<sze>(mask2)) << 8);

    mask1 = 0xf0f0f0f0, mask2 = 0x0f0f0f0f;
    num = ((num & bitset<sze>(mask1)) >> 4) | ((num & bitset<sze>(mask2)) << 4);

    mask1 = 0xcccccccc, mask2 = 0x33333333;
    num = ((num & bitset<sze>(mask1)) >> 2) | ((num & bitset<sze>(mask2)) << 2);

    mask1 = 0xaaaaaaaa, mask2 = 0x55555555;
    num = ((num & bitset<sze>(mask1)) >> 1) | ((num & bitset<sze>(mask2)) << 1);

    cout << num;
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