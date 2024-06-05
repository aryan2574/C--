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

// Count number of nodes
// Find sum of all the nodes

// Definition of the Node class
class Node
{
public:
    int data;    // Data stored in the node
    Node *left;  // Pointer to the left child
    Node *right; // Pointer to the right child

    // Constructor to initialize the node with data and set children to NULL
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to build a binary tree from user input
Node *buildTree()
{
    int nodeData;
    cin >> nodeData; // Read the data

    // Base case: if the input is -1, return NULL indicating no node
    if (nodeData == -1)
        return NULL;

    // Create a new node with the input data
    Node *root = new Node(nodeData);

    // Recursively build the left subtree
    root->left = buildTree();

    // Recursively build the right subtree
    root->right = buildTree();

    // Return the root of the tree
    return root;
}

// Function to count the total number of nodes in the tree
void countNodes(Node *root, int &count)
{
    if (root == NULL)
        return; // Base case: if the node is NULL, return

    count++; // Increment the count for the current node

    // Recursively count nodes in the left subtree
    countNodes(root->left, count);

    // Recursively count nodes in the right subtree
    countNodes(root->right, count);
}

int countNodes2(Node *root)
{
    // Base Case
    if (root == NULL)
        return 0;

    // Recursive case
    return 1 + countNodes2(root->left) + countNodes2(root->right);
}

// Function to calculate the sum of all nodes in the tree
void sumNodes(Node *root, int &sum)
{
    if (root == NULL)
        return; // Base case: if the node is NULL, return

    sum += root->data; // Add the current node's data to the sum

    // Recursively calculate the sum of nodes in the left subtree
    sumNodes(root->left, sum);

    // Recursively calculate the sum of nodes in the right subtree
    sumNodes(root->right, sum);
}

// Main function to build the tree, count nodes, and find sum of nodes
void solve()
{
    Node *root = buildTree(); // Build the tree for each test case

    int count = 0;
    countNodes(root, count); // Count the total number of nodes
    cout << "Total number of nodes: " << count << endl;

    int sum = 0;
    sumNodes(root, sum); // Calculate the sum of all nodes
    cout << "Sum of all nodes: " << sum << endl;
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