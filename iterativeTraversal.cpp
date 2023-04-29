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

void preOrder(Node *node)
{
    cout << node->data << " -> ";
    for (int i = 0; i < node->children.size(); i++)
    {
        preOrder(node->children[i]);
    }
}

void postOrder(Node *node)
{
    
    for (int i = 0; i < node->children.size(); i++)
    {
        postOrder(node->children[i]);
    }
    cout << node->data << " -> ";
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
    cout<<"Preorder is: "<<endl;
    preOrder(root);
    cout<<"Postorder is: "<<endl;
    postOrder(root);
    return 0;
}