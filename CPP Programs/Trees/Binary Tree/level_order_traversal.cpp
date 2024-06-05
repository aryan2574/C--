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

// Function to calculate the height of the tree
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

// Function to print all nodes at a given level
void printCurrentLevel(Node *root, int level)
{
    if (root == NULL)
        return; // Base case: if the node is NULL, return

    if (level == 1)
        cout << root->data << " "; // If the current level is 1, print the node's data
    else if (level > 1)
    {
        // Recursively print nodes at the current level in the left and right subtrees
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

// Function to perform level-order traversal using recursion
void levelOrderTraversal(Node *root)
{
    int h = height(root); // Get the height of the tree

    // Print nodes at each level
    for (int i = 1; i <= h; i++)
    {
        printCurrentLevel(root, i);
        cout << endl; // Print a new line after each level for readability
    }
}

// Function to perform level-order traversal of the tree
void levelOrderTraversalIterative(Node *root)
{
    if (root == NULL)
        return; // Base case: if the root is NULL, return

    // Create a queue to hold nodes at each level
    queue<Node *> q;

    // Start with the root node
    q.push(root);

    while (!q.empty())
    {
        // Get the front node from the queue
        Node *current = q.front();
        q.pop();

        // Print the data of the current node
        cout << current->data << " ";

        // Add the left child to the queue if it exists
        if (current->left != NULL)
            q.push(current->left);

        // Add the right child to the queue if it exists
        if (current->right != NULL)
            q.push(current->right);
    }
    cout << endl; // New line after printing all nodes
}

// Main function to build the tree and perform level-order traversal
void solve()
{
    cout << "Enter nodes data (use -1 for NULL): ";
    Node *root = buildTree();

    cout << "Level-order Traversal (Recursive):" << endl;
    levelOrderTraversal(root);
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