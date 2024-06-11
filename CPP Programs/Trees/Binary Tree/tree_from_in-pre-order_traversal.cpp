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
To generate a binary tree from its inorder and preorder traversals, you need to follow a systematic approach. Here is the corrected and commented code, which includes the function to build a tree from inorder and preorder arrays.
Explanation

    Node Class:
        Represents a node in the binary tree with data, left, and right attributes.
        Constructor initializes the node with the given data and sets children pointers to NULL.

    buildTreeFromArray Function:
        Parameters: The function takes an array, a start index, and an end index.
        Base Case: If start exceeds end, return NULL, indicating no node is created for this segment.
        Recursive Case: Find the middle element of the current segment (mid = (start + end) / 2), create a new node with this element, and recursively build the left and right subtrees using the left and right subarrays. This ensures that the tree remains balanced since each node's left and right subtrees are built from equally divided subarrays.

    createTreeFromTrav Function:
        Parameters: Takes inorder and preorder arrays, start index (s), and end index (e).
        Base Case: If s exceeds e, return NULL.
        Recursive Case: The next element in the preorder array (pre[index]) is the root of the current subtree. Find this element in the inorder array to divide the array into left and right subtrees. Recursively build the left and right subtrees.

    printInOrder Function:
        Prints the tree's nodes in an inorder traversal to verify the tree structure.
        Inorder traversal of a BST yields the elements in sorted order.
*/

/*
Explanation of Changes

    Global Index for Preorder: The static variable preIndex keeps track of the current root in the preorder traversal array.
    Finding Root in Inorder Array: The root of the current subtree is found in the inorder array to split it into left and right subtrees.
    Recursive Calls: After finding the root, recursive calls are made to build the left and right subtrees.
    Debugging and Verifying: The solve function prints the inorder traversal of both the balanced tree and the tree built from inorder and preorder arrays to verify the correctness.

Complexity

    Time Complexity: O(n), where n is the number of nodes. Each node is visited once during the construction of the tree.
    Space Complexity: O(n) for the recursion stack in the worst case (when the tree is completely unbalanced). For a balanced tree, the space complexity is O(log n).
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

// Function to create a binary tree from inorder and preorder traversals
Node *createTreeFromTrav(int *in, int *pre, int s, int e)
{
    static int preIndex = 0;

    // Base case
    if (s > e)
        return NULL;

    // Create the root node with the current element in preorder array
    Node *root = new Node(pre[preIndex++]);

    // Find the index of the root node in the inorder array
    int inIndex = -1;
    for (int i = s; i <= e; i++)
    {
        if (in[i] == root->data)
        {
            inIndex = i;
            break;
        }
    }

    // Recursively build the left and right subtrees
    root->left = createTreeFromTrav(in, pre, s, inIndex - 1);
    root->right = createTreeFromTrav(in, pre, inIndex + 1, e);

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

// Main function to demonstrate the functionality
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

    // Inorder and Preorder arrays for building the tree from traversals
    int inorder[] = {4, 2, 5, 1, 6, 3, 7};
    int preorder[] = {1, 2, 4, 5, 3, 6, 7};
    int len = sizeof(inorder) / sizeof(inorder[0]);

    // Build the tree from inorder and preorder traversals
    Node *rootFromTrav = createTreeFromTrav(inorder, preorder, 0, len - 1);

    // Print the tree in inorder traversal to verify
    printInOrder(rootFromTrav);
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