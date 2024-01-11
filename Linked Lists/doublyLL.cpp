#include <iostream>
using namespace std;
class Node
{
public:
    Node *prev;
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};
void printLL(Node *&head)
{
    if (head == NULL)
    {
        cout << "Linked List Is Empty !!!" << endl;
        return;
    }
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
    if (head == NULL)
    {
        // cout << "Length is Zero(0) !!!" << endl;
        return 0;
    }
    Node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}
//  INSERT AT HEAD
void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // step 1 - Create a Newnode
    Node *newNode = new Node(data);
    // step 2 - connect newNode with head
    newNode->next = head;
    head->prev = newNode;
    // update head
    head = newNode;
}
// Insert at Tail
void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // step 1 - Create a Newnode
    Node *newNode = new Node(data);
    // step 2 - connect newNode with head
    tail->next = newNode;
    newNode->prev = tail;
    // update head
    tail = newNode;
}
// INSERT AT SPECIFIC POSITION
void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    if (position == 0)
    {
        insertAtHead(head, tail, data);
        return;
    }
    int len = findLength(head);
    if (position >= len)
    {
        insertAtTail(head, tail, data);
        return;
    }
    int i = 1;
    Node *temp = head;
    while (i < position)
    {
        temp = temp->next;
        i++;
    }
    // step 1 - Create a Newnode
    Node *newNode = new Node(data);
    // step 2 - connect newNode with previos data
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}
// DELETE A NODE
void deleteNode(Node *&head, Node *&tail, int position)
{
    // DELETE FROM A HEAD / STARTING POSITION
    if (position == 0)
    {
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete (temp);
        return;
    }
    // DELETE FROM TAIL / ENDING OF THE LINKED LIST
    else if (position == findLength(head))
    {
        Node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete (temp);
        return;
    }
   else { // DELETE FROM A SPECIFIC POSITION
    Node *temp = head;
    Node *curr = NULL;
    int i = 0;
    while (i < position - 1)
    {
        temp = temp->next;
        i++;
    }
    curr = temp->next;
    temp->next = curr->next;
    curr->next->prev = temp;
    delete (curr);
   }
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);

    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);
    insertAtTail(head, tail, 60);

    insertAtPosition(head, tail, 5, 0);
    insertAtPosition(head, tail, 70, 8);
    insertAtPosition(head, tail, 25, 3);

    cout << "Length of Linnked List is  : " << findLength(head) << endl;
    printLL(head);
    deleteNode(head, tail, 0);
    printLL(head);

    deleteNode(head, tail, findLength(head));
    printLL(head);

    deleteNode(head,tail,2);
    printLL(head);
}