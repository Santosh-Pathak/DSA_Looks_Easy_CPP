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
// TRAVERSAL TECHINIQES OF TREE
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
void preOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void postOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}
// SEARCH A NODE IN BST
Node *search(Node *root, int data)
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

Node *inorderPredecessor(Node *root, int data)
{
    if (!root)
        return NULL;
    Node *x = search(root, data);

    Node *pred = NULL;
    while (root)
    {
        if (root->data < x->data)
        {
            pred = root;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }

    return pred;
}
// DELETION IN BST (4-CASES)

Node* deleteNodeInBST(Node* root, int target) {
	
	//base cae
	if(root == NULL ) {
		return NULL;
	}
//cout << "Request recieved for " >> root->data << " with target" << target << endl;
	if(root->data == target) {
		//isi ko delete krna h 
		//4 cases 
		if(root->left == NULL && root->right == NULL) {
			//leaf node
			//delete root;
			return NULL;
		}
		else if(root->left == NULL && root->right != NULL) {
			Node* child = root->right;
			//delete root;
			return child;
		}
		else if(root->left != NULL && root->right == NULL) {
			Node* child  = root->left;
			//delete root;
			return child;
		}
		else {
			//both child
			//find inorder predecessor inb left subtree
            Node *pred = inorderPredecessor(root,target);

			int inorderPre =pred->data;
			//replace root->data value with inorder predecessor
			root->data = inorderPre;
			//delete inorder predecessor from left subtree
			root->left = deleteNodeInBST(root->left,inorderPre);
			return root;
			
		}
		
	}
	else if(target > root -> data) {
		//right jana chahiye
		root->right =  deleteNodeInBST(root->right, target);
	}
	else if(target < root->data) {
		//left jana chahioye
		root->left = deleteNodeInBST(root->left, target);
	}
	return root;
}

int main()
{
    Node *root = NULL;
    cout << "Enter The Data for Node : ";
    takeInputs(root);
    cout << "INORDER TRAVERSAL : ";
    inOrderTraversal(root);
    cout << endl;
    cout << "PREORDER TRAVERSAL : ";
    preOrderTraversal(root);
    cout << endl;
    cout << "POSTORDER TRAVERSAL : ";
    postOrderTraversal(root);
    cout << endl;
    cout << "LEVEL ORDER TRAVERSAL : " << endl;
    levelOrderTraversal(root);
    cout << endl;
    int data;
    cout << "Enter a Node Data to Search : ";
    cin >> data;
    if (search(root, data))
    {
        cout << "ELEMENT FOUND !!!";
    }
    else
    {
        cout << "ELEMENT NOT FOUND !!";
    }
    cout << endl;
    cout << "Enter a Node to delete from BST : ";
    cin >> data;
    deleteNodeInBST(root, data);
    cout << endl;
    cout << "INORDER TRAVERSAL : ";
    inOrderTraversal(root);
    cout << endl;
    cout << "PREORDER TRAVERSAL : ";
    preOrderTraversal(root);
    cout << endl;
    cout << "POSTORDER TRAVERSAL : ";
    postOrderTraversal(root);
    cout << endl;
    cout << "LEVEL ORDER TRAVERSAL : " << endl;
    levelOrderTraversal(root);
}