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

void mirrorTree(Node* root){
    for(Node* child: root->children){
        mirrorTree(child);
    }
    reverse(root->children.begin(), root->children.end());
    // int i=0,j= root->children.size()-1;
    // while(i<j) swap(root->children[i++],root->children[j--]);
}

int main(){
    Node* root=newNode(10);
    root->children.push_back(newNode(20));
    root->children.push_back(newNode(30));
    root->children.push_back(newNode(40));
    root->children[1]->children.push_back(newNode(50));
    root->children[1]->children.push_back(newNode(60));
    mirrorTree(root);
    return 0;
}
