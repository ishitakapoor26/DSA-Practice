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

static int sum = 0;
void sumLargerTree(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    sumLargerTree(root->right);
    int od = root->data;
    root->data = sum;
    sum += od;
    sumLargerTree(root->left);
}

void display(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " -> ";
    display(root->left);
    display(root->right);
}

int main()
{
    Node *root = new Node(50);
    root->left = new Node(25);
    root->left->left = new Node(20);
    root->left->right = new Node(37);
    root->right = new Node(75);
    sumLargerTree(root);
    display(root);
    return 0;
}