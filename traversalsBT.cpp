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

void traversal(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    cout << "Pre -> " << node->data << endl;
    traversal(node->left);
    cout << "In -> " << node->data << endl;
    traversal(node->right);
    cout << "Post -> " << node->data << endl;
}

int main()
{
    Node *root = new Node(50);
    root->left = new Node(25);
    root->right = new Node(75);
    root->left->left = new Node(12);
    root->left->right = new Node(37);
    root->left->right->left = new Node(30);
    root->right->left = new Node(62);
    root->right->left->right = new Node(70);
    root->right->right = new Node(87);
    traversal(root);
    return 0;
}