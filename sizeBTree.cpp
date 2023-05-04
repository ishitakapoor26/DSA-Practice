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

int sum(Node *node)
{
    int lsum = 0, rsum = 0, fsum = 0;
    if (node == NULL)
    {
        return 0;
    }
    lsum += sum(node->left);
    rsum += sum(node->right);
    fsum = lsum + rsum + node->data;
    return fsum;
}

int max(Node *node)
{
    int lmax = 0, rmax = 0, fmax = 0;
    if (node == NULL)
    {
        return 0;
    }
    lmax = max(node->left);
    rmax = max(node->right);
    fmax = lmax > rmax ? lmax : rmax;
    fmax = fmax > node->data ? fmax : node->data;
    return fmax;
}

int height(Node *node)
{
    int lh = 0, rh = 0, fh = 0;
    if (node == NULL)
    {
        return -1;
    }
    lh += height(node->left);
    rh += height(node->right);
    fh = lh > rh ? lh : rh;
    return fh + 1;
}

int size(Node *node)
{
    int ls = 0, rs = 0, fs = 0;
    if (node == NULL)
    {
        return 0;
    }
    ls += size(node->left);
    rs += size(node->right);
    fs = ls + rs + 1;
    return fs;
}

void displayTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " -> ";
    displayTree(root->left);
    displayTree(root->right);
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
    cout << "Sum of the nodes is: " << sum(root) << endl;
    cout << "Size of the tree is: " << size(root) << endl;
    cout << "Height of the tree is: " << height(root) << endl;
    cout << "Max node of the tree is: " << max(root) << endl;
    // displayTree(root);
}