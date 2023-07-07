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
    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

Node *constructorBST(int *arr, int l, int h)
{
    if (l > h)
    {
        return NULL;
    }
    int mid = (l + h) / 2;
    Node *root = new Node(arr[mid]);
    root->left = constructorBST(arr, l, mid - 1);
    root->right = constructorBST(arr, mid + 1, h);
    return root;
}

void display(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout <<root->left->data<<" <- "<<root->data << " -> "<<root->right->data<<endl;
    display(root->left);
    display(root->right);
}

int main()
{
    int n;
    cout << "Number of elements in BST: " << endl;
    cin >> n;
    cout << "Enter array elements: ";
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Node *root = constructorBST(arr, 0, n - 1);
    display(root);
    return 0;
}