#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};

Node* removeLeaf(Node* root){
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right == NULL){
        return NULL;
    }
    root->left= removeLeaf(root->left);
    root->right =removeLeaf(root->right);

    return root;
}

void display(Node* root){
    if(root==NULL){
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
    root->right->left = new Node(62);
    root->right->left->left = new Node(60);
    cout<<"Original Tree: "<<endl;
    display(root);
    cout<<endl;
    cout<<"After removing leaves: "<<endl;
    Node* node= removeLeaf(root);
    display(node);
}