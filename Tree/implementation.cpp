#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *buildTree()
{
    int data;
    cout << "Enter the Data : ";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    // step A : create A Node
    Node *root = new Node(data);

    // step B : Recursion on Left Part of Root
    cout << "Enter the Data for Left Part of " << data << endl;
    root->left = buildTree();

    // step C : Recursion on nright part of root
    cout << "Enter the Data for Right Part of " << data << endl;
    root->right = buildTree();

    return root;
}
// void levelOrderTraversal(Node *root)
// {
//     queue<Node*> q;

//     // intitally
//     q.push(root);
//     while (!q.empty())
//     { // a- Extract the front of queue
//         Node *temp = q.front();
//         // b- pop the Node pointer
//         q.pop();
//         // C-Print th data
//         cout << temp->data << " ";
//         // check if Left is Valid
//         if (temp->left)
//         {
//             q.push(temp->left);
//         }
//         // checck if right is Valid
//         if (temp->right)
//         {
//             q.push(temp->right);
//         }
//     }
// }
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
void PreOrdertraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    PreOrdertraversal(root->left);
    PreOrdertraversal(root->right);
}
void InOrdertraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    InOrdertraversal(root->left);
    cout << root->data << " ";
    InOrdertraversal(root->right);
}
void PostOrdertraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    PostOrdertraversal(root->left);
    PostOrdertraversal(root->right);
    cout << root->data << " ";
}
int heightOfBinaryTree(Node* root)
{
    if(root==NULL)
    return 0;

    int left  = heightOfBinaryTree(root->left);
    int right  = heightOfBinaryTree(root->right);

    return max(left,right)+1;

}
int main()
{
    Node *root = NULL;
    root = buildTree();
    cout << endl
         << "Level Order Traversing of Tree " << endl;
    levelOrderTraversal(root);
    cout << endl;
    cout<<"InOrdertraversal :";
    InOrdertraversal(root);
    cout << endl;
    cout<<"PreOrdertraversal :";
    PreOrdertraversal(root);
    cout << endl;
    cout<<"PostOrdertraversal :";
    PostOrdertraversal(root);
    cout<<endl;
    cout<<"Height Of B-Tree = "<<heightOfBinaryTree(root);
}