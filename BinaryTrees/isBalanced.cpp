#include<iostream>
#include<math.h>
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

class Balanced{
    public:
    int ht;
    bool isBalanced;
};

Balanced isBalanced(Node* node){
    if(node==nullptr){
        Balanced b= Balanced();
        b.ht=0;
        b.isBalanced=true;
        return b;
    }
    Balanced lobj= isBalanced(node->left);
    Balanced robj= isBalanced(node->right);
    Balanced fobj= Balanced();
    
    fobj.ht= lobj.ht>=robj.ht?lobj.ht+1:robj.ht+1;
    if(abs(lobj.ht-robj.ht)<=1 && lobj.isBalanced==true && robj.isBalanced==true){
        fobj.isBalanced=true;
    }else{
        fobj.isBalanced=false;
        return fobj;
    }
    return fobj;
}

int main(){
    Node *root = new Node(50);
    root->left = new Node(25);
    root->left->left = new Node(12);
    root->left->left->left = new Node(30);
    // root->left->left->left->left= new Node(35);
    root->right= new Node(75);
    root->right->right= new Node(75);
    root->right->right->right= new Node(75);
    // root->right->right->right->right= new Node(75);
    Balanced b= isBalanced(root);
    if(b.isBalanced){
        cout<<"Balanced";
    }else{
        cout<<"Unbalanced";
    }
    return 0;
}