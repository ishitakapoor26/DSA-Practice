#include <iostream>
#include <vector>
#include <algorithm>
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

void printInRange(Node *root, int lo, int hi)
{
    if (root == nullptr)
    {
        return;
    }
    printInRange(root->left, lo, hi);
    if (root->data >= lo && root->data <= hi)
    {
        cout << root->data << " , ";
    }
    printInRange(root->right, lo, hi);
    return;
}

int main()
{
    int lo, hi;
    cin >> lo >> hi;
    Node *root = new Node(50);
    root->left = new Node(25);
    root->left->left = new Node(20);
    root->left->right = new Node(37);
    root->right = new Node(75);
    printInRange(root, lo, hi);
    return 0;
}