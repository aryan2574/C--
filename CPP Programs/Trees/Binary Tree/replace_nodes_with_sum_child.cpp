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

/*
Replace each node in a binary tree with the sum of its child nodes (while not changing the leaf nodes), you need to traverse the tree and update each non-leaf node.
*/

/*
replaceWithChildSum Function:

    Takes a pointer to the root of the tree.
    If the node is NULL, it returns 0.
    If the node is a leaf, it returns the node's data.
    Recursively calculates the sum of the left and right subtrees.
    Updates the current node's data with the sum of its child nodes.
    Returns the sum including the current node's original value.
*/

// I/P = 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

// Output = 1 23 9 16 7 63 27 13 13

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

// Function to print the tree in inorder traversal
void printTree(Node *root)
{
    if (root == NULL)
        return;

    // Recursively print the left subtree
    printTree(root->left);

    // Print the current node's data
    cout << root->data << ' ';

    // Recursively print the right subtree
    printTree(root->right);
}

// Function to replace each node with the sum of its child nodes
int replaceWithChildSum(Node *root)
{
    if (root == NULL)
        return 0;

    // Base case: If the node is a leaf, return its data
    if (root->left == NULL && root->right == NULL)
        return root->data;

    // Recursively calculate the sum of the left and right subtrees
    int leftSum = replaceWithChildSum(root->left);
    int rightSum = replaceWithChildSum(root->right);

    // Update the current node's data with the sum of its child nodes
    int oldValue = root->data;
    root->data = leftSum + rightSum;

    // Return the sum including the current node's original value
    return oldValue + root->data;
}

// Main function to build the tree, replace nodes, and print the tree
void solve()
{
    Node *root = buildTree(); // Build the tree

    replaceWithChildSum(root); // Replace each node with the sum of its child nodes

    printTree(root); // Print the tree
    cout << endl;
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