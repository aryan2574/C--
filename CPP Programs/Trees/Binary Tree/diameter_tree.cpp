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

// Find diameter of the binary tree

/*
Initial Approach -

The initial approach involves two separate functions: one for calculating the height and one for calculating the diameter.

    Height Calculation Function:
        This function calculates the height of a tree by recursively traversing it.
        Time Complexity: O(n), where n is the number of nodes.
        Space Complexity: O(h), where h is the height of the tree (due to recursion stack).

    Diameter Calculation Function:
        This function calculates the diameter by calling the height function for each node.
        It calculates the diameter of the left and right subtrees, and also considers the path through the root.
        Time Complexity: For each node, it calls the height function which is O(n). Since it does this for all n nodes, the overall time complexity is O(n2).
        Space Complexity: O(h) due to recursion stack.

Optimized Approach

The optimized approach combines the height and diameter calculations into a single recursive function, avoiding redundant calculations.

    Combined Height and Diameter Calculation:
        This function calculates the height of the tree and the diameter in a single traversal.
        It uses an additional parameter (reference) to keep track of the height while calculating the diameter.
        Time Complexity: O(n), as each node is visited only once.
        Space Complexity: O(h) due to recursion stack.
*/

class Pair
{
public:
    int height;
    int diameter;
};

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

// Helper function to calculate the height of the tree
int height(Node *root)
{
    if (root == NULL)
        return 0; // Base case: if the node is NULL, height is 0

    // Recursively calculate the height of the left and right subtrees
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Height of the tree is the maximum of left and right subtree heights plus 1
    return max(leftHeight, rightHeight) + 1;
}

// Function to calculate the diameter of the tree - O(N^2)
int diameter(Node *root)
{
    if (root == NULL)
        return 0; // Base case: if the node is NULL, diameter is 0

    // Get the height of the left and right subtrees
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Get the diameter of the left and right subtrees
    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);

    // The diameter of the tree is the maximum of:
    // 1. Diameter of the left subtree
    // 2. Diameter of the right subtree
    // 3. Height of the left subtree + height of the right subtree + 1 (for the root node)
    return max(leftHeight + rightHeight + 1, max(leftDiameter, rightDiameter));
}

// Function to calculate the diameter of the tree - O(N)
int diameterUtil(Node *root, int &height)
{
    if (root == NULL)
    {
        height = 0; // Base case: if the node is NULL, height is 0
        return 0;   // Diameter is also 0
    }

    int leftHeight = 0, rightHeight = 0;

    // Calculate the diameter of the left and right subtrees
    int leftDiameter = diameterUtil(root->left, leftHeight);
    int rightDiameter = diameterUtil(root->right, rightHeight);

    // Height of the current node is the maximum of the heights of the left and right subtrees plus 1
    height = max(leftHeight, rightHeight) + 1;

    // The diameter of the current node is the maximum of:
    // 1. Diameter of the left subtree
    // 2. Diameter of the right subtree
    // 3. Height of the left subtree + height of the right subtree + 1 (for the root node)
    return max(leftHeight + rightHeight + 1, max(leftDiameter, rightDiameter));
}

// Function to calculate the diameter of the tree
int diameter2(Node *root)
{
    int height = 0;
    return diameterUtil(root, height);
}

// Method 3
Pair diameter3(Node *root)
{
    Pair p;
    if (root == NULL)
    {
        p.diameter = p.height = 0;
        return p;
    }

    // Otherwise
    Pair left = diameter3(root->left);
    Pair right = diameter3(root->right);

    p.height = max(left.height, right.height) + 1;
    p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));
    return p;
}

void solve()
{
    Node *root = buildTree(); // Build the tree for each test case

    int dia = diameter(root); // Calculate the diameter of the tree
    cout << "Diameter of the tree: " << dia << endl;
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