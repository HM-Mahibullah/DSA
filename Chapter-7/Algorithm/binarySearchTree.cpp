#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST
{
public:
    Node *root;
    BST() { root = NULL; }

    Node *insertInBST(Node *root, int data)
    {
        if (root == NULL)
            return new Node(data);

        if (root->data > data)
            root->left = insertInBST(root->left, data);
        else if (root->data < data)
            root->right = insertInBST(root->right, data);

        return root;
    }

    void input()
    {
        int data;
        cout << "Enter values for the BST (end with -1): ";
        cin >> data;
        while (data != -1)
        {
            root = insertInBST(root, data);
            cin >> data;
        }
    }

    void inorder(Node *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

int main()
{
    BST bst;//bst is an object of the class BST.
    bst.input();

    cout << "Inorder traversal of BST: ";
    bst.inorder(bst.root);
    cout << endl;
}
