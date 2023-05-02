#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree(Node *root)
{
    int d;
    cout << "Enter data:" << endl;
    cin >> d;
    root = new Node(d);
    if (d == -1)
    {
        return NULL;
    }

    cout << "Enter left data" << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting data in right" << endl;
    root->right = buildTree(root->right);
    return root;
}

int main()
{
    Node *root = NULL;
    buildTree(root);
    return 0;
}