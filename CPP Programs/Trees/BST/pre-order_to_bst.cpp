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

// Node class to represent each node in the BST
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

// Helper function to construct the BST from pre-order traversal
Node *constructBST(int pre[], int &preIndex, int key, int min, int max, int size)
{
    // Base case
    if (preIndex >= size)
    {
        return NULL;
    }

    Node *root = NULL;

    // If the current key is in the range, then only it is part of the current subtree
    if (key > min && key < max)
    {
        // Create a new node with the current key
        root = new Node(key);
        preIndex = preIndex + 1;

        if (preIndex < size)
        {
            // Construct the left subtree with keys < current key
            root->left = constructBST(pre, preIndex, pre[preIndex], min, key, size);
        }

        if (preIndex < size)
        {
            // Construct the right subtree with keys > current key
            root->right = constructBST(pre, preIndex, pre[preIndex], key, max, size);
        }
    }

    return root;
}

// Function to construct BST from pre-order traversal
Node *constructBST(int pre[], int size)
{
    int preIndex = 0;
    return constructBST(pre, preIndex, pre[0], INT_MIN, INT_MAX, size);
}

// Function to perform inorder traversal of the tree
void inorderTraversal(Node *root)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left);  // Visit left subtree
    cout << root->data << " ";     // Print node's data
    inorderTraversal(root->right); // Visit right subtree
}

void solve()
{
    // Example pre-order traversal array
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof(pre) / sizeof(pre[0]);

    // Construct the BST from the pre-order traversal array
    Node *root = constructBST(pre, size);

    // Perform inorder traversal to verify the BST
    cout << "Inorder traversal of the BST: ";
    inorderTraversal(root);
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