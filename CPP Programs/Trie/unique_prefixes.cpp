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

// Node class represents each node in the Trie
class Node
{
public:
    char data;                            // Character stored in the node
    unordered_map<char, Node *> children; // Pointers to children nodes
    int count;                            // Number of words passing through this node
    bool terminal;                        // Marks if this node represents the end of a word

    // Constructor to initialize the node
    Node(char d) : data(d), terminal(false), count(0) {}
};

// Trie class represents the Trie data structure
class Trie
{
    Node *root; // Pointer to the root of the Trie

public:
    // Constructor to initialize the Trie
    Trie() : root(new Node('\0')) {}

    // Destructor to clean up memory
    ~Trie()
    {
        clear(root);
    }

    // Recursive function to delete nodes
    void clear(Node *node)
    {
        for (auto child : node->children)
        {
            clear(child.second);
        }
        delete node;
    }

    // Function to insert a word into the Trie
    void insert(const string &w)
    {
        Node *temp = root;
        for (char ch : w)
        {
            // If the character is not already present in the Trie, add it
            if (temp->children.count(ch) == 0)
            {
                temp->children[ch] = new Node(ch);
            }
            temp = temp->children[ch]; // Move to the child node
            temp->count++;             // Increment the count for each node
        }
        temp->terminal = true; // Mark the last node as terminal
    }

    // Function to find the shortest unique prefix for a word
    string findUniquePrefix(const string &w)
    {
        Node *temp = root;
        string prefix = "";

        // Traverse the Trie for the given word
        for (char ch : w)
        {
            prefix += ch;              // Add character to the prefix
            temp = temp->children[ch]; // Move to the next node
            // If the count is 1, this prefix is unique among all words
            if (temp->count == 1)
            {
                break; // Stop traversal
            }
        }
        return prefix; // Return the unique prefix
    }
};

// Function to test the Trie implementation
void solve()
{
    Trie trie;
    // List of words to be inserted into the Trie
    vector<string> words = {"cobra", "dog", "dove", "duck"};
    // Insert each word into the Trie
    for (const string &word : words)
    {
        trie.insert(word);
    }

    vector<string> uniquePrefixes;
    // Calculate unique prefixes for each word in the list
    for (const string &word : words)
    {
        uniquePrefixes.push_back(trie.findUniquePrefix(word));
    }

    // Print the unique prefixes for each word
    cout << "Unique Prefixes: " << endl;
    for (const string &prefix : uniquePrefixes)
    {
        cout << prefix << endl;
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