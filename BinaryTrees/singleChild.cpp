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

void printSingleChild(Node* root){
    if(root==NULL){
        return;
    }
    if(root->left==nullptr || root->right==nullptr){
        cout<<root->data<<" ";
    }
    printSingleChild(root->left);
    printSingleChild(root->right);
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
    root->right->left->left = new Node(60);
    printSingleChild(root);
}