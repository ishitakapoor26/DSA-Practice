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

bool isMirror(Node *n1, Node *n2)
{
    if(n1->children.size()!= n2->children.size()){
        return false;
    }
    for(int i=0;i<n1->children.size();i++){
        if(isMirror(n1->children[i],n2->children[n2->children.size()-1-i])==false){
            return false;
        }
    }
    return true;
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
    Node *alph = newNode(150);
    alph->children.push_back(newNode(151));
    alph->children.push_back(newNode(152));
    alph->children.push_back(newNode(153));
    alph->children[0]->children.push_back(newNode(154));
    // alph->children[0]->children.push_back(newNode(155));
    alph->children[1]->children.push_back(newNode(156));
    alph->children[1]->children.push_back(newNode(157));
    alph->children[1]->children.push_back(newNode(158));
    alph->children[1]->children[1]->children.push_back(newNode(159));
    alph->children[1]->children[1]->children.push_back(newNode(160));
    alph->children[2]->children.push_back(newNode(161));
    alph->children[2]->children.push_back(newNode(162));
    cout << isMirror(root, alph);
    return 0;
}