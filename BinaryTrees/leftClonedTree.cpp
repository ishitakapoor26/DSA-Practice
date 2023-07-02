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

    Node(int data, Node* left, Node* right){
        this->data=data;
        this->left=left;
        this->right=right;
    }
};

Node* leftClonedTreeTransform(Node* root){
    if(root==nullptr){
        return nullptr;
    }
    Node* lcr = leftClonedTreeTransform(root->left);
    Node* rcr = leftClonedTreeTransform(root->right);
    Node* nn = new Node(root->data, lcr, nullptr);
    root->left=nn;
    root->right= rcr;
    return root;
}

void display(Node* root){
    if(root==nullptr){
        return;
    }
    cout<<root->data<<" ";
    display(root->left);
    display(root->right);
}

int main(){
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
    Node* newRoot= leftClonedTreeTransform(root);
    display(newRoot);
    return 0;
}