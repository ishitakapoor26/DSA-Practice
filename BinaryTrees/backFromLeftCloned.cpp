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

void display(Node* root){
    if(root==nullptr){
        return;
    }
    cout<<root->data<<" ";
    display(root->left);
    display(root->right);
}

Node* backFromLeftClonedTreeTransform(Node* root){
    if(root==nullptr){
        return nullptr;
    }
    Node* lc= backFromLeftClonedTreeTransform(root->left->left);
    Node* rc= backFromLeftClonedTreeTransform(root->right);
    root->left= lc;
    root->right=rc;
    return root;
}

int main(){
    Node* root= new Node(50);
    root->right= new Node(62);
    root->right->left= new Node(62);
    root->right->left->left= new Node(58);
    root->right->left->left->left= new Node(58);
    root->left= new Node(50);
    root->left->left= new Node(25);
    root->left->left->left= new Node(25);
    root->left->left->right= new Node(37);
    root->left->left->right->left= new Node(37);
    Node* newRoot= backFromLeftClonedTreeTransform(root);
    display(newRoot);
    return 0;
}