
#include <iostream>
#include <vector>
#include <algorithm>
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

int c = INT16_MIN;
int f = INT16_MIN;

void ceilFloor(Node *node, int data)
{
    if (node->data > data && c < data)
    {
        c = node->data;
    }
    else if (node->data < data && node->data > f)
    {
        f = node->data;
    }
    for (Node *child : node->children)
    {
        ceilFloor(child, data);
    }
}

int kLargest(Node* node, int k){
    f=INT16_MIN;
    int factor= INT16_MAX;
    for(int i=0;i<k;i++){
        ceilFloor(node,factor);
        factor= f;
        f= INT16_MIN;
    } 
    return factor;
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
    cout<<kLargest(root,3);
    return 0;
}