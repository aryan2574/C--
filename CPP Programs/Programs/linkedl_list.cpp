#include <bits/stdc++.h>
#include <iostream>
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

//Node Datatype for Linked List
class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class LinkedList
{
public:
    node *head;
    LinkedList()
    {
        head = NULL;
    }
    /*_____________________________________________________________*/
    //Insert elements in the nodes funciton
    void insertNode(node *&head, int val)
    {
        node *n = new node(val);
        if (head == NULL)
        {
            head = n;
            return;
        }
        node *t = head;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = n;
    }

    //Insert at front function
    void insertAtFront(node *&head, int val)
    {
        node *temp = new node(val);
        temp->next = head;
        head = temp;
    }

    //Insert Multiple Inputs function
    node *multipleInputs()
    {
        int data;
        node *head = NULL;
        while (cin >> data)
        {
            insertAtFront(head, data);
        }
        return head;
    }

    /*_____________________________________________________________*/
    /*_____________________________________________________________*/

    //Delete a node function
    void deleteANode(node *&head, int val)
    {

        if (head == NULL)
        {
            return;
        }
        if (head->data == val)
        {
            if (head->next == NULL)
            {
                node *toDelete = head;
                head = head->next;
                delete toDelete;
                return;
            }
            else
            {
                node *toDelete = head;
                head = head->next;
                delete toDelete;
                return;
            }
        }

        node *temp = head;
        while (temp->next->data != val)
        {
            temp = temp->next;
        }
        node *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    //Delete a node at the tail
    void tailDelete(node *head)
    {
        //Corner case
        if (head == NULL)
        {
            return;
        }
        node *del = head->next;
        while (del->next != NULL)
        {
            del = del->next;
            head = head->next;
        }
        delete del;
        head->next = NULL;
    }

    /*_____________________________________________________________*/
    /*_____________________________________________________________*/

    //Search Function - Iterative
    bool searchNode(node *head, int key)
    {
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    //Search function - Recursive
    bool searchNodeRec(node *head, int key)
    {
        if (head == NULL)
            return false;

        if (head->data == key)
            return true;
        else
            return searchNodeRec(head->next, key);
    }

    /*_____________________________________________________________*/
    /*_____________________________________________________________*/

    //Reverse function O(n)
    void reverseFunc(node *&head)
    {
        node *prev = NULL;
        node *curr = head;
        node *nex;
        while (curr != NULL)
        {
            //save the next node
            nex = curr->next;
            //make the current node point to previous
            curr->next = prev;
            //update prev and current and take one step forward
            prev = curr;
            curr = nex;
        }
        head = prev;
    }

    //Recursive Reverse Function #1 O(n^2)
    node *recReverse(node *head)
    {
        //Base case
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        //Recursive Case
        node *shead = recReverse(head->next);
        node *temp = shead;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        head->next = NULL;
        temp->next = head;
        return shead;
    }

    //Recursive Reverse Function #2 O(n)
    node *recReverseOpti(node *head)
    {
        //base case
        if (head == NULL or head->next == NULL)
        {
            return head;
        }

        //recursive case
        node *shead = recReverseOpti(head->next);
        head->next->next = head;
        head->next = NULL;
        return shead;
    }

    /*_____________________________________________________________*/
    /*_____________________________________________________________*/

    //Finding Mid-Element #1
    node *mid_elem(node *head)
    {
        if (head == NULL or head->next == NULL)
            return head;
        int count = 0;
        node *ele_count = head;
        node *find_ele = head;
        while (ele_count->next != NULL)
        {
            count++;
            ele_count = ele_count->next;
        }
        count /= 2;
        while (count > 0)
        {
            find_ele = find_ele->next;
            count--;
        }
        return find_ele;
    }

    //Finding Mid-Element #2 Runner Technique
    node *mid_elem_2(node *head)
    {
        if (head == NULL or head->next == NULL)
            return head;

        node *slow = head;
        node *fast = head->next;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    //Finding Kth node from end
    node *k_element(node *head, int k)
    {
        if (head == NULL)
            return head;
        node *curr = head;
        node *ele;
        while (k--)
        {
            curr = curr->next;
        }
        ele = curr;
        while (ele != NULL)
        {
            ele = ele->next;
            head = head->next;
        }
        return head;
    }

    /*_____________________________________________________________*/
    /*_____________________________________________________________*/

    //Merge two sorted linkedlists
    node *mergell(node *a, node *b)
    {
        if (a == NULL)
            return b;
        if (b == NULL)
            return a;

        //Take head pointer
        node *c;
        if (a->data < b->data)
        {
            c = a;
            c->next = mergell(a->next, b);
        }
        else
        {
            c = b;
            c->next = mergell(a, b->next);
        }
        return c;
    }

    //Sort linkedlist using merge sort

    // node *mergeSort(node *head)
    // {
    //     //base condition
    //     if (head == NULL or head->next == NULL)
    //         return head;

    //     node *mid = midpoint(head);
    //     //Break
    //     node *a = head;
    //     node *b = mid->next;
    //     mid->next = NULL;

    //     //Sort
    //     a = mergeSort(a);
    //     b = mergeSort(b);

    //     //Merge
    //     node *c = mergell(a, b);
    //     return c;
    // }

    /*_____________________________________________________________*/
    /*_____________________________________________________________*/

    //LinkedList Cycle Detection

    /*_____________________________________________________________*/
    /*_____________________________________________________________*/

    //Print Function
    void printNodes(node *head)
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << nline;
    }
};

/*_____________________________________________________________*/
/*_____________________________________________________________*/

void solve(void)
{
    LinkedList llobj;
    node *head = NULL;
    int i = 0;
    while (++i < 6)
    {
        llobj.insertNode(head, i);
    }
    llobj.printNodes(head);

    llobj.printNodes(head);
}

// _____________________________________________________________________________________
int main(void)
{
    aryan_2574_cp();
    solve();
}