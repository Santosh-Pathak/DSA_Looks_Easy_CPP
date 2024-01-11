#include <iostream>
#include <queue>
#include<vector>
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
void levelOrderTraversal(Node *root, vector<int>& ans)
{   
    queue<Node *> q;
    // initially
    q.push(root);
    q.push(NULL);
    int sum=0;
    while (!q.empty())
    {
        // A
        Node *temp = q.front();
        // B
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            ans.push_back(sum);
            sum=0;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            // C
            cout << temp->data << " ";
            sum+=temp->data;
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

int main()
{   vector<int>ans;
    int inOrder[] = {7, 3, 11, 1, 17, 3, 18};
    int preOrder[] = {1, 3, 7, 11, 3, 17, 18};
    int n = sizeof(inOrder) / sizeof(int);
    int preIndex = 0;
    cout << "Building Tree : " << endl;
    Node *root = buildTreeFromPreOrderInOrder(inOrder, preOrder, n, preIndex, 0, n - 1);
    cout << endl
         << "Level Order Traversing of Tree " << endl;

    levelOrderTraversal(root,ans);
    cout<<"LEvel Order Sum "<<endl;
    int max =0;
    for(int i=0;i<ans.size();i++)
    {
        if(max < ans[i]);
             max =ans[i];
    }
    cout<<endl<<  max;

    
}