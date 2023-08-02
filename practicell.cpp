#include <iostream>
using namespace std;

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

void insertNodeAtHead(node *&head, int val)
{
    if (head == NULL)
    {
        head = new node(val);
        return;
    }
    node *n = new node(val);
    n->next = head;
    head = n;
}

int lenOfNodes(node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void insertAtTail(node *&head, int val)
{
    if (head == NULL)
    {
        head = new node(val);
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node *n = new node(val);
    temp->next = n;
}

void insertAtMid(node *&head, int val, int pos)
{
    if (head == NULL || pos == 0)
    {
        insertNodeAtHead(head, val);
    }
    else if (pos > lenOfNodes(head))
    {
        insertAtTail(head, val);
    }
    else
    {

        node *temp = head;
        for (int i = 1; i <= pos - 1; i++)
        {
            temp = temp->next;
        }

        node *n = new node(val);
        n->next = temp->next;
        temp->next = n;
    }
}

void printNode(node *head)
{
    if (head == NULL)
    {
        cout << "List is empty";
        return;
    }
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << endl;
}

void deleteHead(node *&head)
{
    node *temp = head->next;
    delete head;
    head = temp;
}

void deleteNode(node *&head, int pos)
{
    if (head == NULL)
        return;

    node *temp = head;
    int i = 1;
    while (i++ < pos - 1)
    {
        temp = temp->next;
    }

    node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}

void deleteNodeByValue(node *&head, int val)
{
    if (head->data == val)
    {
        node *temp = head->next;
        delete head;
        head = temp;
    }

    node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }

    node *nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

node *contInput()
{
    int data;
    node *head = NULL;
    cin >> data;
    while (data != -1)
    {
        insertNodeAtHead(head, data);
        cin >> data;
    }
    return head;
}

void searchNode(node *head, int val)
{
    while (head != NULL)
    {
        if (head->data == val)
        {
            cout << " FOUND" << endl;
            return;
        }
        head = head->next;
    }
    cout << "Not found";
}

bool searchNodeRec(node *head, int val)
{
    if (head == NULL)
    {
        return false;
    }

    if (head->data == val)
    {
        return true;
    }
    else
    {
        return searchNodeRec(head->next, val);
    }
}

void revList(node *&head)
{
    if (head == NULL)
        return;

    node *prevNode = NULL;
    node *currNode = head;
    while (currNode != NULL)
    {
        node *nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    head = prevNode;
}

node *revLLRec(node *head)
{
    if (head->next == NULL || head == NULL)
        return head;

    node *shead = revLLRec(head->next);
    head->next->next = head;
    head->next = NULL;
    return shead;
}

node *midP(node *head)
{
    node *slow = head;
    node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

int findingKthEle(node *head, int k)
{
    int len = lenOfNodes(head);
    int pos = (len - k) + 1;
    int i = 1;
    while (i++ != pos)
    {
        head = head->next;
    }
    return head->data;
}

// int findingKthEleOpti(node *head, int k)
// {
//     node *slow = head;
//     node *fast = head;
//     while (k--)
//     {
//         fast = fast->next;
//     }
//     while (fast != NULL && fast->next != NULL)
//     {
//         fast = fast->next;
//         slow = slow->next;
//     }
//     return slow->data;
// }

void deleteKthFromLast(node *&head, int k)
{
    int len = lenOfNodes(head);
    int pos = (len - k) + 1;
    int i = 1;
    node *temp = head;
    while (i++ < pos - 1)
    {
        temp = temp->next;
    }
    node *nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

void deleteKthEleFromLastOpt(node *&head, int k)
{
    if (head == NULL)
        return;

    node *fast = head;
    node *slow = head;
    while (k--)
    {
        fast = fast->next;
    }

    if (fast == NULL)
    {
        node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    node *temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
}

node *mergeTwo(node *a, node *b)
{
    // base case
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    node *c;
    if (a->data < b->data)
    {
        c = a;
        c->next = mergeTwo(a->next, b);
    }
    else
    {
        c = b;
        c->next = mergeTwo(a, b->next);
    }
    return c;
}

void ree(node *&head)
{
    if (head == NULL)
        return;

    node *currEle = head;
    node *prevEle = NULL;
    while (currEle != NULL)
    {
        node *nextEle = currEle->next;
        currEle->next = prevEle;
        prevEle = currEle;
        currEle = nextEle;
    }
    head = prevEle;
}

node *reeC(node *head)
{
    if (head->next == NULL || head == NULL)
        return head;

    node *shead = reeC(head->next);
    head->next->next = head;
    head->next = NULL;
    return shead;
}
node *mergeTwotwo(node *&a, node *&b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    node *c;
    if (a->data < b->data)
    {
        c = a;
        c->next = mergeTwotwo(a->next, b);
    }
    else
    {
        c = b;
        c->next = mergeTwotwo(a, b->next);
    }

    return c;
}

node *meSor(node *&head)
{
    if (head->next == NULL || head == NULL)
    {
        return head;
    }

    // break
    node *mid = midP(head);
    node *a = head;
    node *b = mid->next;
    mid->next = NULL;

    // sort
    a = meSor(a);
    b = meSor(b);

    // combine
    node *c = mergeTwo(a, b);
    return c;
}

bool cycleDetect(node *head)
{
    node *fast = head;
    node *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }
    return false;
}

int main()
{

    // node *head = contInput();
    node *head1 = NULL;
    // node *head2 = NULL;
    insertNodeAtHead(head1, 9);
    insertNodeAtHead(head1, 5);
    insertNodeAtHead(head1, 7);
    insertNodeAtHead(head1, 3);
    insertNodeAtHead(head1, 1);
    printNode(head1);

    head1 = meSor(head1);
    // head1 = reeC(head1);
    // insertNodeAtHead(head2, 8);
    // insertNodeAtHead(head2, 6);
    // insertNodeAtHead(head2, 4);
    // insertNodeAtHead(head2, 2);
    // insertNodeAtHead(head2, 0);
    // printNode(head2);

    // node *head3 = mergeTwo(head1, head2);

    // deleteKthEleFromLastOpt(head, 5);
    printNode(head1);

    // cout << findingKthEle(head, 2);
    // cout << findingKthEleOpti(head, 2);

    // cout << midP(head);
    // deleteNode(head, 3);
    // printNode(head);

    // deleteNodeByValue(head, 3);

    // if (searchNodeRec(head, 2))
    // {
    //     cout << "Found" << endl;
    // }
    // else
    //     cout << "Not found" << endl;

    // printNode(head);

    // insertAtMid(head, 22, 4);
    // printNode(head);

    // insertAtMid(head, 11, 4);
    // printNode(head);

    // insertAtTail(head, 99);
    // printNode(head);

    return 0;
}