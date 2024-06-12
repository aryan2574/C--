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
    int d;
    cin >> d; // Read the data

    // Base case: if the input is -1, return NULL indicating no node
    if (d == -1)
        return NULL;

    // Create a new node with the input data
    Node *root = new Node(d);

    // Recursively build the left subtree
    root->left = buildTree();

    // Recursively build the right subtree
    root->right = buildTree();

    // Return the root of the tree
    return root;
}

// Function to perform in-order traversal of the tree
void inOrderTraversal(Node *root)
{
    if (root == NULL)
        return; // Base case: if the node is NULL, return

    inOrderTraversal(root->left);  // Recursively visit the left subtree
    cout << root->data << " ";     // Visit the current node
    inOrderTraversal(root->right); // Recursively visit the right subtree
}

// Function to find the LCA of two given nodes in the binary tree
Node *findLCA(Node *root, Node *n1, Node *n2)
{
    // Base case: if root is NULL or root is one of n1 or n2
    if (root == NULL || root == n1 || root == n2)
        return root;

    // Recur for left and right subtrees
    Node *leftLCA = findLCA(root->left, n1, n2);
    Node *rightLCA = findLCA(root->right, n1, n2);

    // If n1 and n2 are found in left and right subtrees of this node, then this node is the LCA
    if (leftLCA != NULL && rightLCA != NULL)
        return root;

    // Otherwise, check if left subtree or right subtree is LCA
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

void solve()
{
    // Build the tree from input
    Node *root = buildTree();

    // Print the in-order traversal of the tree
    cout << "In-order traversal of the tree: ";
    inOrderTraversal(root);
    cout << endl;

    // Example usage of finding LCA
    Node *n1 = root->left;  // Example node 1
    Node *n2 = root->right; // Example node 2

    Node *lca = findLCA(root, n1, n2);

    if (lca != NULL)
        cout << "LCA of " << n1->data << " and " << n2->data << " is: " << lca->data << endl;
    else
        cout << "LCA does not exist in the tree." << endl;
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