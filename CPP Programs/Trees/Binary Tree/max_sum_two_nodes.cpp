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

// Helper function to find the maximum sum path
int findMaxSumUtil(Node *root, int &maxSum)
{
    // Base case: if the node is NULL, return 0
    if (root == NULL)
        return 0;

    // Recursively find the maximum sum path in the left and right subtrees
    int left = findMaxSumUtil(root->left, maxSum);
    int right = findMaxSumUtil(root->right, maxSum);

    // Maximum path sum passing through the current node
    int maxSingle = max(max(left, right) + root->data, root->data);

    // Maximum path sum with the current node as the root of the path
    int maxTop = max(maxSingle, left + right + root->data);

    // Update the maximum sum encountered so far
    maxSum = max(maxSum, maxTop);

    return maxSingle;
}

// Function to find the maximum sum path from any node to any node in the tree
int findMaxSum(Node *root)
{
    int maxSum = INT_MIN;
    findMaxSumUtil(root, maxSum);
    return maxSum;
}

void solve()
{
    // Build the tree from input
    Node *root = buildTree();

    // Print the in-order traversal of the tree
    cout << "In-order traversal of the tree: ";
    inOrderTraversal(root);
    cout << endl;

    // Find and print the maximum sum path
    int maxSum = findMaxSum(root);
    cout << "Maximum sum path from any node to any node: " << maxSum << endl;
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