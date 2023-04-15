#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Node
{
    int data;
    vector<Node* > children;
};

Node* newNode(int val){
    Node* node= new Node;
    node->data=val;
    return node;
}

int maxNode(Node* node){
    int maximum= INT_MIN;
    for(Node* child: node->children){
        int cm = maxNode(child);
        maximum= max(cm,maximum);
    }
    maximum=max(node->data,maximum);
    return maximum;
}


int main(){
    Node *root = newNode(10);
    (root->children).push_back(newNode(2));
    (root->children).push_back(newNode(34));
    (root->children).push_back(newNode(56));
    (root->children).push_back(newNode(100));
    (root->children[0]->children).push_back(newNode(77));
    (root->children[0]->children).push_back(newNode(88));
    (root->children[2]->children).push_back(newNode(1));
    (root->children[3]->children).push_back(newNode(7));
    (root->children[3]->children).push_back(newNode(8));
    (root->children[3]->children).push_back(newNode(9));
    return 0;
}