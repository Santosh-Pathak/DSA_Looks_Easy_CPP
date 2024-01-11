#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // TODO: Write a destrcutor to delete a node
    ~Node()
    {
        // write your code here
        cout << "Node with value: " << this->data << " deleted" << endl;
    }
};

// I want to insert a node right at the head of Linked List
void insertAtHead(Node *&head, Node *&tail, int data)
{
    // check for Empty LL
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // step1:
        Node *newNode = new Node(data);
        // step2:
        newNode->next = head;
        // step3:
        head = newNode;
    }
}
// I want to insert a node right at the end of LINKED LIST
void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // step1: creatae a node
    Node *newNode = new Node(data);
    // step2: connect woth tail ndoe
    tail->next = newNode;
    // step3: update tail;
    tail = newNode;
}
void print(Node *head)
{

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

 
// REVERSE THE LINKED LIST (RECURSION)
Node *reverseLL(Node *prev, Node *curr)
{
    // base case
    if (curr == NULL)
    {
        return prev;
    }

    // recursion
    Node *next = curr->next;
    curr->next = prev;
    // for next calls prev = current and current = next
    reverseLL(curr, next);
}
// REVERSE THE LL (ITERATIVE METHOD0
Node *reverseLL(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
// REVERSE TH NODES IN GROUP OF  K
Node *reverseInGroup(Node *&head, int k)
{
    if (head == NULL)
    {
        cout << "Linked List is Empty !!" << endl;
        return NULL;
    }
    int len = findLength(head);
    if (k > len)
    {
        // cout << "Enter a Valid Value of K!!" << endl;
        return head;
    }

    // it means number of nodess >= k

    // STEP 1 : Reverse first K nodes of Linked Lost
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = curr->next;
    int count = 0;

    while (count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // step B : recursive call
    if (forward != NULL) // we still have nodes left to reverse
    {
        head->next = reverseInGroup(forward, k);
    }
    // step C : return head of the modifies ll
    return prev;
}
// REVERSE LINKED LIST IN K GROUPS
// Node *reverseInk(Node *&head, int k)
// {
//     if (head == NULL)
//     {
//         cout << "LInked list is empty !!";
//         return NULL;
//     }
//     int len = findLength(head);
//     if (k > len)
//     {
//         return head;
//     }

//     // this means that we have nodes to reverse
//     // STEP 1 : reverse First K Nodes in LL
//     Node *prev = NULL;
//     Node *curr = head;
//     Node *forward = curr->next;
//     int count = 0;
//     while (count < k)
//     {
//         forward = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = forward;
//         count++;
//     }
//     // STEP 2 : FIND THE ANSWER USING RECURSION
//     if (forward != NULL)
//         head->next = reverseInk(forward, k);
//     // STEP 3 : return the New Modified head of LInked list
//     return prev;
// }

int main()
{

    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 60);
    insertAtHead(head, tail, 90);
    insertAtTail(head, tail, 95);
    insertAtTail(head, tail, 99);

    print(head);
    // head = reverseLL(NULL, head);
    // print(head);
    // head = reverseLL(head);
    // print(head);
    int g = 3;
    // cout << "Enter the Value of Reversing K : ";
    // cin >> g;
    // head = reverseInGroup(head, g);
    head = reverseInk(head, g);
    print(head);
    return 0;
}