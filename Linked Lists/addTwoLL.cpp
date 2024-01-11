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
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first = reverseLL(first);
        second = reverseLL(second);
        struct Node* ansHead =NULL; 
        struct Node* ansTail = NULL;
        int carry = 0;
        // STEP 1- Add two Linked List
        while(first !=NULL && second !=NULL)
        {
            //calculate sum
            int sum = carry + first->data + second->data;
            //find digit to create node for
            int digit = sum % 10;
            carry = sum /10;
            Node* newNode = new Node(digit);
         
            if(ansHead == NULL)
         {
                 ansHead= newNode;
                 ansTail = newNode;
         }
             else
         {
                 ansTail->next =newNode;
                 ansTail = newNode;
         }
         
         
         first = first->next;
         second = second->next;
        }
        
        while(first !=  NULL)
        {
         int sum = carry + first->data + second->data;
         int digit = sum % 10;
         carry = sum /10;
         struct Node* newNode = new Node(digit);
         ansTail->next =newNode;
         ansTail = newNode;
         
         first = first->next;
        }
        
        
        while(second != NULL)
        {
         int sum = carry + first->data + second->data;
         int digit = sum % 10;
         carry = sum /10;
         struct Node* newNode = new Node(digit);
         ansTail->next =newNode;
         ansTail = newNode;
         
         second = second->next;
        }
        
        //handle th carry 
        while(carry !=0 )
        {
            int sum = carry;
            int digit  =sum%10;
            carry = sum/10;
            Node * newNode  = new Node(digit);
            ansTail->next = newNode;
            ansTail = newNode;
        }
        //step 2 - return HEAD
        
        return reverseLL(ansHead);
    }



int main() {

        Node* head1 = NULL;
        Node* tail1 = NULL;
        insertAtTail(head1, tail1,2);
        insertAtTail(head1, tail1,5);
        insertAtTail(head1, tail1,5);

       
        Node* head2 = NULL;
        Node* tail2 = NULL;
        insertAtTail(head2, tail2,2);
        insertAtTail(head2, tail2,5);
        insertAtTail(head2, tail2,5);

       
       Node *head = addTwoLists(head1,head2);
        print(head);
        return 0;
}

