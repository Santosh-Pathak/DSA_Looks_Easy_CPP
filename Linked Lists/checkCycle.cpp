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

int findLength(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}
// ITERATIVE WAY
// bool findCircleInList(Node *&head)
// {
//     Node *temp = head->next;
//     while (temp != NULL)
//     {
//         if (temp == head)
//         {
//             return true;
//         }
//         else
//         {
//             temp = temp->next;
//         }
//     }
//     return false;
// }
// TWO POINTERS APPROACH (FCD - FLOYD CYCKE DETECTION)
bool findCircleInList(Node *&head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}
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
    tail->next = head;
    if (findCircleInList(head))
        cout << "YES Cycle is Present !!!" << endl;
    else
        cout << "NO Cycle is Present !!!" << endl;
    tail->next = NULL;
    print(head);
}