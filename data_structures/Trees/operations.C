
/*******************************************************
 * Binary search tree and basic operations.
 *
 *
 *
 * ****************************************************/

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node():data(0), left(NULL), right(NULL)
    {}

    Node(int num):data(num), left(NULL), right(NULL)
    {}
};

typedef Node* pNode;

void insert(pNode &root, int num)
{
    if(!root)
    {
        root = new Node(num);
        return;
    }
    Node *temp = root;
    Node *parent = NULL;
    while(temp)
    {
        parent = temp;
        if(num < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    if(num < parent->data)
        parent->left = new Node(num);
    else
        parent->right = new Node(num);
}

void printInorder(pNode root)
{
    if(root)
    {
        printInorder(root->left);
        cout << root->data << "  ";
        printInorder(root->right);
    }
}

void printPostorder(pNode root)
{
    if(root)
    {
        printPostorder(root->left);
        printPostorder(root->right);
        cout << root->data << "  ";
    }
}

int main()
{
    pNode root = NULL;
    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printInorder(root);
    cout << endl;
    printPostorder(root);
    cout << endl;
    return 0;
}
