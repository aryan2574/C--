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

// Function to insert a new node with given data in BST
Node *insert(Node *root, int data)
{
    // Base case: If the tree is empty, create a new node and return it
    if (root == NULL)
    {
        return new Node(data);
    }

    // If the data to be inserted is less than the root's data, insert in the left subtree
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    // If the data to be inserted is greater than the root's data, insert in the right subtree
    else
    {
        root->right = insert(root->right, data);
    }

    // Return the unchanged root node
    return root;
}

// Function to build the tree by taking user input
Node *buildTree()
{
    int d;
    Node *root = NULL;

    cout << "Enter numbers to insert into BST (enter -1 to stop):" << endl;
    while (true)
    {
        cin >> d;
        if (d == -1)
            break;
        root = insert(root, d);
    }

    return root;
}

// Function to search for a node with a given key in the BST
Node *search(Node *root, int key)
{
    // Base case: If the tree is empty or the root's data matches the key
    if (root == NULL || root->data == key)
    {
        return root;
    }

    // If the key is less than the root's data, search in the left subtree
    if (key < root->data)
    {
        return search(root->left, key);
    }
    // If the key is greater than the root's data, search in the right subtree
    else
    {
        return search(root->right, key);
    }
}

// Function to find the minimum value node in a subtree
Node *findMin(Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Function to delete a node with a given key in the BST
Node *deleteNode(Node *root, int key)
{
    // Base case: If the tree is empty
    if (root == NULL)
        return root;

    // If the key to be deleted is less than the root's data, go to the left subtree
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    // If the key to be deleted is greater than the root's data, go to the right subtree
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    // If the key is equal to the root's data, this is the node to be deleted
    else
    {
        // Node with only one child or no child
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node *temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
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
    // Build the BST from user input
    Node *root = buildTree();

    // Perform inorder traversal to print the BST
    cout << "Inorder traversal of the BST: ";
    inorderTraversal(root);
    cout << endl;

    // Search for a key in the BST
    int key;
    cout << "Enter the number to search in BST: ";
    cin >> key;
    Node *result = search(root, key);
    if (result != NULL)
    {
        cout << "Found node with data: " << result->data << endl;
    }
    else
    {
        cout << "Node with data " << key << " not found in the BST." << endl;
    }

    // Delete a key in the BST
    cout << "Enter the number to delete from BST: ";
    cin >> key;
    root = deleteNode(root, key);

    // Perform inorder traversal to print the BST after deletion
    cout << "Inorder traversal of the BST after deletion: ";
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