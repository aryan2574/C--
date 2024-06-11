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

// Function to print all nodes at distance k from the current node
void printAtLevelK(Node *root, int k)
{
    if (root == NULL)
        return;

    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    printAtLevelK(root->left, k - 1);
    printAtLevelK(root->right, k - 1);
}

// Function to find and print all nodes at distance k from the target node
int printAtDistanceK(Node *root, Node *target, int k)
{
    // Base case: if the root is NULL, return -1
    if (root == NULL)
        return -1;

    // If the current node is the target node
    if (root == target)
    {
        printAtLevelK(target, k);
        return 0;
    }

    // Check in the left subtree
    int DL = printAtDistanceK(root->left, target, k);

    // If target is found in the left subtree
    if (DL != -1)
    {
        // Check if the current node is at distance k from the target
        if (DL + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            // Print nodes at distance (k - DL - 2) in the right subtree
            printAtLevelK(root->right, k - DL - 2);
        }
        return 1 + DL;
    }

    // Check in the right subtree
    int DR = printAtDistanceK(root->right, target, k);

    // If target is found in the right subtree
    if (DR != -1)
    {
        // Check if the current node is at distance k from the target
        if (DR + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            // Print nodes at distance (k - DR - 2) in the left subtree
            printAtLevelK(root->left, k - DR - 2);
        }
        return 1 + DR;
    }

    // Node was not present in the left or right subtree
    return -1;
}

// Main function to solve the problem
void solve()
{
    // Build the tree from input
    Node *root = buildTree();

    // Print the in-order traversal of the tree
    cout << "In-order traversal of the tree: ";
    inOrderTraversal(root);
    cout << endl;

    // Example usage of finding nodes at distance k from a given target node
    int k = 2;                 // Distance k
    Node *target = root->left; // Target node (you can change this to any node in the tree)

    cout << "Nodes at distance " << k << " from the target node " << target->data << ": ";
    printAtDistanceK(root, target, k);
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