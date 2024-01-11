#include <iostream>
using namespace std;

class Node {
        public:
        int data;
        Node* next;

        Node() {
                this->data = 0;
                this->next = NULL;
        }
        Node(int data) {
                this->data = data;
                this->next = NULL;
        }

        //TODO: Write a destrcutor to delete a node
        ~Node() {
                //write your code here
                cout << "Node with value: " << this->data << " deleted" << endl;
        }
};

//I want to insert a node right at the head of Linked List
void insertAtHead(Node* &head, Node* &tail, int data) {
        //check for Empty LL
        if(head == NULL) {
                Node* newNode = new Node(data);
                head = newNode;
                tail = newNode;
        }
        else {
                //step1:
                Node* newNode = new Node(data);
                //step2:
                newNode -> next = head;
                //step3:
                head = newNode;
        }


}
//I want to insert a node right at the end of LINKED LIST
void insertAtTail(Node* &head,Node* &tail, int data) {
        if(head == NULL) {
                Node* newNode = new Node(data);
                head = newNode;
                tail = newNode;
                return;
        }
        //step1: creatae a node
        Node* newNode = new Node(data);
        //step2: connect woth tail ndoe
        tail->next = newNode;
        //step3: update tail;
        tail = newNode;
}
void print(Node* head) {

        Node* temp = head;
        while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
        }
        cout<<endl;
}

int findLength(Node* &head ) {
        int len = 0;
        Node* temp = head;
        while(temp != NULL) {
                temp = temp->next;
                len++;
        }
        return len;
}

void insertAtPosition(int data, int position, Node* &head, Node* &tail) {
        if(head == NULL) {
                Node* newNode = new Node(data);
                head = newNode;
                tail = newNode;
                return;
        }
        //step1: find the position: prev & curr;

        if(position == 0) {
                insertAtHead(head, tail , data);
                return;
        }
       
        int len = findLength(head);
        
        if(position >= len) {
                insertAtTail(head, tail, data);
                return;
        }
        //ste1:find prev and curr
        int i = 1;
        Node* prev = head;
        while(i < position) {
                prev= prev -> next;
                i++;
        }
        Node* curr = prev -> next;

        //step2;
        Node* newNode = new Node(data);

        //step3:
        newNode -> next = curr;

        //step4:
        prev -> next = newNode;
}

void deleteNode(int position, Node* &head, Node* &tail) {
        if(head == NULL) {
                cout << "Cannot delete, LL is empty";
                return;
        }

        //deleting first node
        if(position == 1) {
                Node* temp = head;
                head = head -> next;
                temp -> next = NULL;
                delete temp;
                return;
        }
        int len  = findLength(head);


        //deleting last node
        if(position == len) {
                //find prev
                int i = 1;
                Node* prev = head;
                while(i < position - 1) {
                        prev = prev->next;
                        i++;
                }
                //step2:
                prev->next = NULL;
                //step3:
                Node* temp = tail;
                //step4:
                tail = prev;
                //step5:
                delete temp;
                return;
        }

        //deleting middle node

        //step  : find prev and curr
        int i =1;
        Node* prev = head;
        while( i < position-1) {
                prev= prev -> next;
                i++;
        }
        Node* curr = prev -> next;

        //step2:
        prev -> next = curr -> next;
        //step3:
        curr -> next = NULL;
        //step4:
        delete curr;

}
// delete Duplicates in sorted LInked list
void removeDuplicates(Node *&head)
{
    if(head == NULL)
        return;
    
    // ------------------------------------------
    
    Node* temp = head;
 
    while(temp!=NULL)
    {
        if(temp->data == temp->next->data && (temp->next !=NULL))
        {
            Node* next_next = temp->next->next;
            Node* todelete = temp->next;
            delete(todelete);
            temp->next = next_next;
        
        }
        else
        {
            temp = temp->next; 
        }
    }
}
int main() {

        Node* head = NULL;
        Node* tail = NULL;
        insertAtTail(head, tail,20);
        insertAtTail(head, tail,20);
        insertAtTail(head, tail,60);
        insertAtTail(head,tail, 60);
        insertAtTail(head, tail, 77);

        // print(head);
        // cout << endl;
        // cout << "head: " << head -> data << endl;
        // cout << "tail: " << tail->data << endl;

        // insertAtPosition(101, 5, head, tail);
        // cout<< "Printing after insert at position call" << endl;
        // print(head);
        // cout << endl;
        // cout << "head: " << head -> data << endl;
        // cout << "tail: " << tail->data << endl;

        // deleteNode(3, head, tail);
        // cout << endl;
        // print(head);
        // cout << endl;

        // removeDuplicates(head);
        print(head);
        Node *prev;
        while(head->next)
        {
                prev = head;
                head = head->next;
        }
        cout<<prev->data;
        cout<<head->data;

        return 0;
}