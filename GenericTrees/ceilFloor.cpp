// ceil is smallest among larger: just larger
// floor is largest among smaller: just smaller

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

// vector<int> c= {0};
// vector<int> f= {0};

// void ceilFloor(Node*  node, int data){
//     if(node->data>data){
//         c.push_back(node->data);
//     }else if(node->data<data){
//         f.push_back(node->data);
//     }
//     for(Node* child:node->children){
//         ceilFloor(child,data);
//     }
// }

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
    ceilFloor(root, 110);
    cout << "Ceil is " << c << endl;
    cout << "Floor is " << f;
    return 0;
}