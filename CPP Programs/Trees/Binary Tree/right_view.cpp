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

// Binary tree implementation

/*
IP- 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1


OP-
Enter nodes data (use -1 for NULL): Level-order Traversal (Recursive):
8
10 3
1 6 14
9 7 13
*/

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

// Function to perform pre-order traversal of the tree
void preOrderTraversal(Node *root)
{
    if (root == NULL)
        return; // Base case: if the node is NULL, return

    cout << root->data << " ";      // Visit the current node
    preOrderTraversal(root->left);  // Recursively visit the left subtree
    preOrderTraversal(root->right); // Recursively visit the right subtree
}

// Function to perform post-order traversal of the tree
void postOrderTraversal(Node *root)
{
    if (root == NULL)
        return; // Base case: if the node is NULL, return

    postOrderTraversal(root->left);  // Recursively visit the left subtree
    postOrderTraversal(root->right); // Recursively visit the right subtree
    cout << root->data << " ";       // Visit the current node
}

// Function to print the right view of the binary tree
void printRightView(Node *root, int level, int &maxLevel)
{
    if (root == NULL)
        return; // Base case: if the node is NULL, return

    // If this is the first node of its level
    if (maxLevel < level)
    {
        cout << root->data << ' '; // Print the node's data
        maxLevel = level;          // Update the maximum level visited
    }

    // Recursively visit the right subtree first, then the left subtree
    printRightView(root->right, level + 1, maxLevel);
    printRightView(root->left, level + 1, maxLevel);
}

void solve()
{
    // Build the tree from input
    Node *root = buildTree();

    // Print the in-order traversal of the tree
    cout << "In-order traversal: ";
    inOrderTraversal(root);
    cout << nline;

    // Print the right view of the tree
    cout << "Right view of the tree: ";
    int maxLevel = -1; // Initialize maximum level visited to -1
    printRightView(root, 0, maxLevel);
    cout << nline;
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