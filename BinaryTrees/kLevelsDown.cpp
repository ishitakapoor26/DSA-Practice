#include <iostream>
#include <vector>
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

void kLevelsDown(Node *root, int k)
{
    if (root == NULL || k < 0)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
    }
    kLevelsDown(root->left, k - 1);
    kLevelsDown(root->right, k - 1);
}

int main()
{
    Node *root = new Node(50);
    root->left = new Node(25);
    root->right = new Node(75);
    root->left->left = new Node(12);
    root->left->right = new Node(37);
    root->left->right->left = new Node(30);
    root->left->right->right = new Node(40);
    root->right->left = new Node(62);
    root->right->left->right = new Node(70);
    root->right->left->left = new Node(60);
    root->right->right = new Node(57);
    int k;
    cout << "Enter the value of k: " << endl;
    cin >> k;
    kLevelsDown(root, k);
    return 0;
}