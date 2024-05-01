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

// Node class representing each node in the Trie
class Node
{
public:
    Node *left;                               // Pointer to the left child
    Node *right;                              // Pointer to the right child
    Node() : left(nullptr), right(nullptr) {} // Constructor to initialize the node
};

// Trie class to implement the Trie data structure
class Trie
{
    Node *root; // Pointer to the root of the Trie

public:
    Trie() : root(new Node()) {} // Constructor to initialize the Trie

    // Function to insert a number into the Trie
    void insert(int n)
    {
        Node *temp = root;
        // Loop through each bit of the number
        for (int i = 31; i >= 0; i--)
        {
            int bit = (n >> i) & 1; // Extract the i-th bit of the number

            // If the bit is 0, go left in the Trie
            if (bit == 0)
            {
                if (temp->left == nullptr)
                {
                    temp->left = new Node(); // Create a new node if it doesn't exist
                }
                temp = temp->left; // Move to the left child
            }
            else
            {
                // If the bit is 1, go right in the Trie
                if (temp->right == nullptr)
                {
                    temp->right = new Node(); // Create a new node if it doesn't exist
                }
                temp = temp->right; // Move to the right child
            }
        }
    }

    // Helper function to find the maximum XOR value for a given number
    int max_xor_helper(int value)
    {
        int current_xor = 0;
        Node *temp = root;

        // Loop through each bit of the number
        for (int j = 31; j >= 0; j--)
        {
            int bit = (value >> j) & 1; // Extract the j-th bit of the number

            // If the bit is 0, try to find a complementary 1 bit
            if (bit == 0)
            {
                if (temp->right != nullptr)
                {
                    temp = temp->right;      // Move to the right child
                    current_xor += (1 << j); // Update the current XOR value
                }
                else
                {
                    temp = temp->left; // Move to the left child
                }
            }
            else
            {
                // If the bit is 1, try to find a complementary 0 bit
                if (temp->left != nullptr)
                {
                    temp = temp->left;       // Move to the left child
                    current_xor += (1 << j); // Update the current XOR value
                }
                else
                {
                    temp = temp->right; // Move to the right child
                }
            }
        }

        return current_xor;
    }

    // Function to find the maximum XOR value between any two numbers in an array
    int max_xor(int *input, int n)
    {
        int max_xor = 0;

        // Loop through each number in the array
        for (int i = 0; i < n; i++)
        {
            int val = input[i];
            insert(val);                           // Insert the number into the Trie
            int current_xor = max_xor_helper(val); // Find the maximum XOR value for the current number
            max_xor = max(current_xor, max_xor);   // Update the maximum XOR value
        }

        return max_xor;
    }
};

// Function to solve the problem
void solve()
{
    int input[] = {3, 10, 5, 25, 2, 8};
    Trie t;

    cout << "Maximum XOR value: " << t.max_xor(input, 6) << endl;
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