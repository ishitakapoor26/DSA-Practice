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

Node *successor;
Node* predecessor;
int state = 0;

void find(Node *node, int data)
{
    if (state == 0)
    {
        if (node->data == data)
        {
            state = 1;
        }
        else
        {
            predecessor = node;
        }
    }
    else if (state == 1)
    {
        successor = node;
        state = 2;
    }
    for (Node *child : node->children)
    {
        find(child,data);
    }
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
    find(root, 90);
    cout<<predecessor->data<<" -> "<<"90 -> "<<successor->data;
    return 0;
}