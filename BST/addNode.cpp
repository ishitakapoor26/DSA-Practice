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
        left = right = NULL;
    }
};

Node *addNode(Node *root, int data)
{
    if (root == nullptr)
    {
        Node *node = new Node(data);
        return node;
    }
    if (data < root->data)
    {
        Node *lnode = addNode(root->left, data);
        root->left = lnode;
        cout << root->data << " ->" << root->left->data << endl;
        cout << "Node added!" << endl;
        return root->left;
    }
    else if (data > root->data)
    {
        Node *rnode = addNode(root->right, data);
        root->right = rnode;
        cout << root->data << " ->" << root->right->data << endl;
        cout << "Node added!" << endl;
        return root->right;
    }
    return root;
}

int main()
{
    int data;
    cin >> data;
    Node *root = new Node(50);
    root->left = new Node(25);
    root->left->left = new Node(20);
    root->left->right = new Node(37);
    root->right = new Node(75);
    Node* newNode = addNode(root, data);
    return 0;
}