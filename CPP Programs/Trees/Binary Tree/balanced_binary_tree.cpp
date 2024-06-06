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

// Balanced binary tree
/*
For any node in the tree, the height of the left subtree and the height of the right subtree differ by at most one.
This ensures that the tree does not become skewed, leading to operations that can be performed in logarithmic time.
*/

/*
Balanced binary tree from an array, you'll want to leverage the sorted nature of the array (assuming it is sorted) to ensure that the tree remains balanced. The middle element of the array will become the root of the tree, the middle element of the left subarray will become the left child, and the middle element of the right subarray will become the right child, recursively.
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

// Function to create a balanced binary tree from a sorted array
Node *buildTreeFromArray(int *arr, int start, int end)
{
    // Base case: if the start index exceeds the end index, return NULL
    if (start > end)
        return NULL;

    // Find the middle element to make it the root
    int mid = (start + end) / 2;
    Node *root = new Node(arr[mid]);

    // Recursively build the left subtree from the left subarray
    root->left = buildTreeFromArray(arr, start, mid - 1);

    // Recursively build the right subtree from the right subarray
    root->right = buildTreeFromArray(arr, mid + 1, end);

    return root;
}

// Function to print the tree in inorder traversal
void printInOrder(Node *root)
{
    if (root == NULL)
        return;

    // Traverse the left subtree
    printInOrder(root->left);

    // Print the root node's data
    cout << root->data << " ";

    // Traverse the right subtree
    printInOrder(root->right);
}

void solve()
{
    // Sorted array from which to build the balanced binary tree
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Build the balanced binary tree
    Node *root = buildTreeFromArray(arr, 0, n - 1);

    // Print the tree in inorder traversal to verify
    printInOrder(root);
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