#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define mod1 998244353
#define INF 1e18
#define PI 3.141592653589793238462
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define set_bits __builtin_popcountll
#define setp(x, y) fixed << setprecision(y) << x
#define fo(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef vector<int> vi;

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

void aryan_2574_cp()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}
// ____________________________________________________________________________________

// Creating node for binary tree
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class bTree
{
public:
    node *buildtree()
    {
        // input data
        int d;
        cin >> d;
        if (d == -1)
            return NULL;

        // create node
        node *root = new node(d);
        root->left = buildtree();
        root->right = buildtree();
        return root;
    }

    // Printing Pre order tree
    void printPreOrd(node *root)
    {
        if (root == NULL)
            return;

        cout << root->data << " ";
        printPreOrd(root->left);
        printPreOrd(root->right);
    }

    // Printing In Order Tree
    void printInOrd(node *root)
    {
        if (root == NULL)
            return;

        printInOrd(root->left);
        cout << root->data << " ";
        printInOrd(root->right);
    }

    // Printing Post Order
    void printPostOrd(node *root)
    {
        if (root == NULL)
            return;

        printPostOrd(root->left);
        printPostOrd(root->right);
        cout << root->data << " ";
    }

    // Finding height of tree
    int heightOfBTree(node *root)
    {
        if (root == NULL)
            return 0;

        int ans1 = heightOfBTree(root->left);
        int ans2 = heightOfBTree(root->right);
        return max(ans1, ans2) + 1;
    }

    // Printing Kth Level in BTree
    void printKthLevel(node *root, int k)
    {
        if (root == NULL)
            return;
        if (k == 1)
            cout << root->data << " ";

        printKthLevel(root->left, k - 1);
        printKthLevel(root->right, k - 1);
        return;
    }

    // Printing Level Wise using height of the tree
    void printLevelWise(node *root)
    {
        // First we calculate the height of the tree
        int height = heightOfBTree(root);

        // We calculate from i=1 to the height and will print the value.
        // Time Complexity: O(N)^2
        for (int i = 1; i <= height; i++)
        {
            printKthLevel(root, i); // Print the kth level
        }
        return;
    }

    void printLevelWiseUsingBFS(node *root)
    {
        // In BFS we use a Queue. First we push the root node in the queue. And then in while loop
        // we pick the node at the front and push its children and then pop the top element till the
        // queue becomes empty.eg: 1 2 -1 -1 3 -1 -1 push 1 to queue then pop 1 and push it's children
        // 2 and 3. then select 2 and pop and push it's children. Then pop 3 and push its childrean.
        //  [1,2,3] -> [2,3] -> [3] -> []
        // Complexity: O(N)

        // Creating a queue of type node* as we are pushing every node of queue
        queue<node *> q;
        // Pushing root node
        q.push(root);
        while (!q.empty())
        {
            node *front = q.front();
            cout << front->data << " ";
            q.pop();
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
        return;
    }

    void printLevelWiseUsingBFSLineChanged(node *root)
    {
        queue<node *> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            node *frnt = q.front();
            if (frnt == NULL)
            {
                cout << endl;
                q.pop();
                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                cout << frnt->data << " ";
                q.pop();
                if (frnt->left)
                    q.push(frnt->left);
                if (frnt->right)
                    q.push(frnt->right);
            }
        }
        return;
    }

    // Count Number of nodes in a tree
    int countNodes(node *root)
    {
        if (root == NULL)
            return 0;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    // Total sum of nodes values
    int totalSum(node *root)
    {
        if (root == NULL)
            return 0;

        return root->data + totalSum(root->left) + totalSum(root->right);
    }

    // Diameter of the tree
    int diameterTree(node *root)
    {
        if (root == NULL)
            return 0;

        int h1 = heightOfBTree(root->left);
        int h2 = heightOfBTree(root->right);
        int op1 = h1 + h2;
        int op2 = diameterTree(root->left);
        int op3 = diameterTree(root->right);

        return min(max(op1, op2), op3);
    }
};

void solve()
{
    bTree b;
    node *root = b.buildtree();
    b.printPreOrd(root);
    cout << endl;
    b.printInOrd(root);
    cout << endl;
    b.printPostOrd(root);
    cout << endl;
    cout << b.heightOfBTree(root);
    cout << endl;
    b.printLevelWise(root);
    cout << endl;
    b.printLevelWiseUsingBFS(root);
    cout << endl;
    b.printLevelWiseUsingBFSLineChanged(root);
    cout << b.countNodes(root) << endl;
    cout << b.totalSum(root);
    cout << endl;
    cout << b.diameterTree(root) << endl;
}

// _____________________________________________________________________________________
int main(void)
{
    aryan_2574_cp();
    solve();
    return 0;
}