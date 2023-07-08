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

bool findTree(Node *root, int n)
{
    if(root==nullptr){
        return false;
    }
    bool res;
    if (root->data == n)
    {
        return true;
    }
    if (n < root->data)
    {
        int res = findTree(root->left, n);
        if (res)
        {
            return true;
        }
    }
    else if (n > root->data)
    {
        int res = findTree(root->right, n);
        if (res)
        {
            return true;
        }
    }
    return false;
}

void traversalAndPrint(Node* root,Node* node, int tar){
    if(node==nullptr){
        return;
    }
    traversalAndPrint(root,node->left,tar);
    int comp= tar- node->data;
    if(node->data<comp){
        if(findTree(root,comp)==true){
            cout<<node->data<<" , "<<comp<<endl;
        }
    }
    traversalAndPrint(root,node->right,tar);
}

int main()
{
    int t;
    cin >> t;
    Node *root = new Node(50);
    root->left = new Node(25);
    root->left->left = new Node(20);
    root->left->right = new Node(37);
    root->right = new Node(75);
    traversalAndPrint(root,root,t);
    return 0;
}