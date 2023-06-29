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

Node *getTail(Node *node)
{
    while (node->children.size() == 1)
    {
        node = node->children[0];
    }
    return node;
}

// void linearise(Node *node)
// {
//     for (Node *child : node->children)
//     {
//         linearise(child);
//     }
//     while(node->children.size()>1){
//         Node* lc= node->children[node->children.size()-1];
//         node->children.pop_back();
//         Node* sl= node->children[node->children.size()-1];
//         Node* slt= getTail(sl);
//         slt->children.push_back(lc);
//     }
// }

// Optimised approach- O(n)

Node *linearise(Node *node)
{
    if (node->children.size() == 0)
    {
        return node;
    }
    Node *lkt = linearise(node->children[node->children.size() - 1]);
    while (node->children.size() > 1)
    {
        Node *last = node->children[node->children.size() - 1];
        node->children.pop_back();
        Node *sl = node->children[node->children.size() - 1];
        Node *slkt = linearise(sl);
        slkt->children.push_back(last);
    }
    return lkt;
}

void traverse(Node *node)
{
    cout << node->data << " -> ";
    for (Node *child : node->children)
    {
        traverse(child);
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
    linearise(root);
    return 0;
}
