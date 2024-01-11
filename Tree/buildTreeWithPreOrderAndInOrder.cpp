#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left = NULL;
    Node *right = NULL;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
int findPosition(int inOrder[], int n, int element)
{
    for (int i = 0; i < n; i++)
    {
        if (inOrder[i] == element)
            return i;
    }
    return -1;
}

Node *buildTreeFromPreOrderInOrder(int inorder[], int preorder[], int size, int &preIndex, int inorderStart, int inorderEnd)
{

    // base case
    if (preIndex >= size || inorderStart > inorderEnd)
    {
        return NULL;
    }

    // Step A:
    int element = preorder[preIndex++];
    Node *root = new Node(element);
    int pos = findPosition(inorder, size, element);

    // step B: root->left solve
    root->left = buildTreeFromPreOrderInOrder(inorder, preorder, size, preIndex, inorderStart, pos - 1);
    // Step C: root->right solve
    root->right = buildTreeFromPreOrderInOrder(inorder, preorder, size, preIndex, pos + 1, inorderEnd);

    return root;
}
// Node *buildTreeFromPostOrderInOrder(int inorder[], int preorder[], int size, int &preIndex, int inorderStart, int inorderEnd)
// {

//     // base case
//     if (preIndex > 0 || inorderStart > inorderEnd)
//     {
//         return NULL;
//     }

//     // Step A:
//     int element = preorder[preIndex--];
//     Node *root = new Node(element);
//     int pos = findPosition(inorder, size, element);

//     // Step C: root->right solve
//     root->right = buildTreeFromPostOrderInOrder(inorder, preorder, size, preIndex, pos + 1, inorderEnd);
//     // step B: root->left solve
//     root->left = buildTreeFromPostOrderInOrder(inorder, preorder, size, preIndex, inorderStart, pos - 1);

//     return root;
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
int main()
{
    //     7
    // 7 3 11 1 17 3 18
    // 1 3 7 11 3 17 18
    int inOrder[] = {7, 3, 11, 1, 17, 3, 18};
    int preOrder[] = {1, 3, 7, 11, 3, 17, 18};
    int n = sizeof(inOrder) / sizeof(int);
    int preIndex = 0;
    cout << "Building Tree : " << endl;
    Node *root = buildTreeFromPreOrderInOrder(inOrder, preOrder, n, preIndex, 0, n - 1);
    cout << "Printing level order Trraversal : " << endl;
    levelOrderTraversal(root);
    cout << "Printing preOrderTraversal Trraversal : " << endl;
    PreOrdertraversal(root);
    cout << endl;
    InOrdertraversal(root);
    cout << endl;
    PostOrdertraversal(root);
    cout << endl;
    // int inOrder[] = {40, 20, 10, 50, 30, 60};
    // int postOrder[] = {40, 20, 50, 60, 30, 10};
    // int n = sizeof(inOrder) / sizeof(int);
    // int postIndex = n - 1;
    // cout << "Building Tree : " << endl;
    // Node *root = buildTreeFromPostOrderInOrder(inOrder, postOrder, n, postIndex, 0, n - 1);
    // cout << "Printing level order Trraversal : " << endl;
    // levelOrderTraversal(root);
    // cout << "Printing preOrderTraversal Trraversal : " << endl;
    // PreOrdertraversal(root);

    // return 0;
}