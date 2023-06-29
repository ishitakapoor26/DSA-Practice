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

vector<int> nodeToRoot(Node* node, int data){
    if(node->data==data){
        vector<int> vec;
        vec.push_back(node->data);
        return vec;
    }
    for(Node* child: node->children){
        vector<int> ptc= nodeToRoot(child, data);
        if(ptc.size()>0){
            ptc.push_back(node->data);
            return ptc;
        }
    }
    vector<int> r;
    return r;
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
    vector<int> result= nodeToRoot(root, 110);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" -> ";
    }
    return 0;
}