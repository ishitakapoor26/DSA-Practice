#include <iostream>
#include <vector>
#include<queue>
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


void levelOrder(Node *node)
{
    queue<Node*> q;
    q.push(node);
    while(q.size()>0){
        node= q.front();
        cout<<node->data<<" ";
        q.pop();
        for(Node* child: node->children){
            q.push(child);
        }
    }
}

int main()
{
    Node *root = newNode(10);
    root->children.push_back(newNode(20));
    root->children.push_back(newNode(30));
    root->children.push_back(newNode(40));
    root->children[1]->children.push_back(newNode(50));
    root->children[1]->children.push_back(newNode(60));
    levelOrder(root);
    return 0;
}