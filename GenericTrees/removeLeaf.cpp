#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int data;
    vector<Node *> children;
};

Node* newNode(int val){
    Node* node= new Node;
    node->data=val;
    return node;
}

void removeLeaf(Node* node){
    for(int i=node->children.size()-1;i>=0;i--){
        Node* child= node->children[i];
        if(child->children.size()==0){
            node->children[i]=NULL;
        }
    }
    for(Node* child: node->children){
        removeLeaf(child);
    }
}

int main(){
    Node* root=newNode(10);
    root->children.push_back(newNode(20));
    root->children.push_back(newNode(30));
    root->children.push_back(newNode(40));
    root->children[1]->children.push_back(newNode(50));
    root->children[1]->children.push_back(newNode(60));
    removeLeaf(root);
    return 0;
}
