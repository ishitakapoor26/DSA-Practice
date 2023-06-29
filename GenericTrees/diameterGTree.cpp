// doubt

#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    vector<Node *> children;
};

Node *newNode(int val)
{
    Node *node = new Node;
    node->data = val;
    return node;
}

int dia=0;

int diameterTree(Node* node){
    int dch=-1;
    int sdch=-1;
    for(Node *child: node->children){
        int ch= diameterTree(child);
        if(ch>dch){
            sdch=dch;
            dch=ch;
        }else if(ch>sdch){
            sdch=ch;
        }
    }
    int cand= dch+sdch+2;
    if(cand>dia){
        dia= cand;
    }
    dch+=1;
    return dch;
}

int main()
{
    Node *root = newNode(10);
    root->children.push_back(newNode(20));
    root->children.push_back(newNode(30));
    root->children.push_back(newNode(40));
    root->children[0]->children.push_back(newNode(50));
    root->children[0]->children.push_back(newNode(60));
    root->children[1]->children.push_back(newNode(70));
    root->children[1]->children.push_back(newNode(80));
    root->children[1]->children.push_back(newNode(90));
    root->children[1]->children[1]->children.push_back(newNode(110));
    root->children[1]->children[1]->children.push_back(newNode(120));
    root->children[2]->children.push_back(newNode(100));
    cout<<diameterTree(root);
    return 0;
}