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

void traversalTree(Node *node)
{
    cout << "Node Pre " << node->data << endl;
    for (Node *child : node->children)
    {
        cout << "Edge Pre " << node->data << "--" << child->data << endl;
        traversalTree(child);
        cout << "Edge Post " << node->data << "--" << child->data << endl;
    }
    cout << "Node Post " << node->data << endl;
    return;
}

int main()
{
    Node* root=newNode(10);
    root->children.push_back(newNode(20));
    root->children.push_back(newNode(30));
    root->children.push_back(newNode(40));
    root->children[1]->children.push_back(newNode(50));
    root->children[1]->children.push_back(newNode(60));
    traversalTree(root);
    return 0;
}