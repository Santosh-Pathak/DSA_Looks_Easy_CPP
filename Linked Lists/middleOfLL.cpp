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
// FUNCTION TO FIND THE MIDDLE OF THE LINKE LIST (APPROACH -1)
// void findMiddleNode(Node *&head)
// {
//     int len = findLength(head);
//     Node *temp = head;
//     int i=1;
//     if (len % 2 == 0)
//     {
//         len = len/2;
//         while (i<len)
//         {
//             temp = temp->next;
//             i++;
//         }
//         cout << " Middle Node is : " << temp->data << endl;
//         return;
//     }
//     else
//     {
//         len = len / 2 ;
//         while (i<len+1)
//         {
//             temp = temp->next;
//             i++;
//         }
// cout << " Middle Node is : " << temp->data << endl;
//     }
// }
// TWO POINTER APPROACH
void findMiddleNode(Node *&head)
{
    if (head == NULL)
    {
        cout << " Linked List is Empty !!" << endl;
    }
    if (head->next == NULL)
    {
        cout << " Middle Node is : " << head->data << endl;
        return;
    }
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && slow != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    cout << " Middle Node is : " << slow->data << endl;
}
int main()
{

    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 60);
    insertAtTail(head, tail, 77);
    insertAtHead(head, tail, 90);
    insertAtHead(head, tail, 95);

    print(head);
    // two pointer approach is better
    findMiddleNode(head);

    return 0;
}