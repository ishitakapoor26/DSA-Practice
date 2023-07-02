#include <iostream>
#include<math.h>
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

class DiaPair{
    public:
    int ht;
    int dia;
};

DiaPair diameter2(Node* node){
    if(node==nullptr){
        DiaPair bp= DiaPair();
        bp.ht=-1;
        bp.dia=0;
        return bp;
    }
    DiaPair lp= diameter2(node->left);
    DiaPair rp= diameter2(node->right);

    DiaPair mp= DiaPair();
    mp.ht= max(lp.ht, rp.ht) +1;

    int fes= lp.ht + rp.ht+2;
    mp.dia= max(fes, max(lp.dia, rp.dia));

    return mp;
}


int main()
{
    Node* root= new Node(50);
    root->left= new Node(25);
    root->left->left= new Node(30);
    root->left->right= new Node(37);
    root->left->right->right= new Node(45);
    root->right= new Node(75);
    root->right->right= new Node(57);
    root->right->left= new Node(62);
    root->right->left->left= new Node(58);
    root->right->left->left->left= new Node(70);
    DiaPair p= diameter2(root);
    cout<<p.dia;
    return 0;
}