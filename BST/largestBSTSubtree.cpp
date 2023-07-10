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

class BSTPair
{
public:
    bool isBST;
    int min;
    int max;
    Node* lbstroot;
    int lbstsize;
};

BSTPair isBST(Node *node)
{
    if (node == nullptr)
    {
        BSTPair bp = BSTPair();
        bp.min = INT32_MAX;
        bp.max = INT32_MIN;
        bp.isBST = true;
        return bp;
    }
    BSTPair lp = isBST(node->left);
    BSTPair rp = isBST(node->right);
    BSTPair mp = BSTPair();
    mp.isBST = lp.isBST && rp.isBST && (node->data >= lp.max && node->data <= rp.min);
    mp.min = min(node->data, min(lp.min, rp.min));
    mp.max = min(node->data, min(lp.max, rp.max));

    if(mp.isBST){
        mp.lbstroot = node;
        mp.lbstsize= lp.lbstsize+rp.lbstsize+1;
    }else if(lp.lbstsize>rp.lbstsize){
        mp.lbstroot= lp.lbstroot;
        mp.lbstsize= lp.lbstsize;
    }else{
        mp.lbstroot=rp.lbstroot;
        mp.lbstsize=rp.lbstsize;
    }
    return mp;
}

int main()
{
    int n;
    cin >> n;
    Node *root = new Node(4);
    root->left= new Node(2);
    root->left->left= new Node(1);
    root->left->right= new Node(3);
    root->right= new Node(6);
    root->right->left= new Node(5);
    root->right->right= new Node(7);
    return 0;
}