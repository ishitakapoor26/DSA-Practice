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

pair<int,int> tiltOfTree(Node* root){
    int lsum=0,rsum=0;
    pair<int,int> p;
    if(root==nullptr){
        p.first=0;
        p.second=0;
        return p;
    }
    pair<int,int> lpair= tiltOfTree(root->left);
    lsum+=lpair.first;
    pair<int,int> rpair= tiltOfTree(root->right);
    rsum+=rpair.first;
    if(root!=nullptr){
        p.second+= (lsum-rsum>0?lsum-rsum:rsum-lsum)+lpair.second+rpair.second;
        p.first= root->data+ lsum+ rsum;
    }
    cout<<p.first<<" , "<<p.second<<endl;
    return p;
}

int main(){
    Node* root= new Node(50);
    root->left= new Node(40);
    root->left->left= new Node(20);
    root->left->left->left= new Node(60);
    root->left->left->right= new Node(70);
    root->left->right= new Node(10);
    root->left->right->left= new Node(80);
    root->left->right->right= new Node(90);
    root->right= new Node(30);
    pair<int,int> p= tiltOfTree(root);
    cout<<"Tilt of Binary Tree is: "<<p.second<<endl;
    cout<<p.first;
}