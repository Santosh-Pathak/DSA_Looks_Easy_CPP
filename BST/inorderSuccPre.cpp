#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    Node *left;
    int data;
    Node *right;

    Node(int data)
    {
        this->left = NULL;
        this->data = data;
        this->right = NULL;
    }
};
Node *insertBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (root->data < data)
    {
        root->right = insertBST(root->right, data);
    }
    else
    {
        root->left = insertBST(root->left, data);
    }
    return root;
}
void takeInputs(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertBST(root, data);
        cin >> data;
    }
}
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    // initially
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        // A
        Node *temp = q.front();
        // B
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            // C
            cout << temp->data << " ";
            // D
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void inOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

Node* search(Node *root, int data)
{
    if (root == NULL)
        return NULL;

    if (root->data == data)
        return root;

    if (data > root->data)
    {
        return search(root->right, data);
    }
    else
    {
       return search(root->left, data);
    }
    return NULL;
}

Node* inorderSuccess(Node* root,int data)
{
    if(!root) return NULL;
    Node* x = search(root,data);

     Node* pred = NULL;
        while(root)
        {
            if(root->data > x->data)
            {
                pred = root;
                root=root->left;
            }
            else
            {
                root=root->right;
            }
        }
        
        return pred;

}

Node* inorderPredecessor(Node* root,int data)
{
    if(!root) return NULL;
    Node* x = search(root,data);

    Node* pred = NULL;
        while(root)
        {
            if(root->data < x->data)
            {
                pred = root;
                root=root->right;
            }
            else
            {
                root=root->left;
            }
        }
        
        return pred;

}
int main()
{
    Node *root = NULL;
    cout << "Enter The Data for Node : ";
    takeInputs(root);
    cout << "INORDER TRAVERSAL : ";
    inOrderTraversal(root);
    cout << endl;
    cout << "LEVEL ORDER TRAVERSAL : " << endl;
    levelOrderTraversal(root);
    cout << endl;
    int data;
    cout<<"Enter a Node data to search Inorder Success : ";
    cin>>data;
    cout<<"InOrder Successor of "<<data<<" is "<<(inorderSuccess(root,data))->data<<endl;
    cout<<"InOrder Predesessor of "<<data<<" is "<<(inorderPredecessor(root,data))->data;
    
}