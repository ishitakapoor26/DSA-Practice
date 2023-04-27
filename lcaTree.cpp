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

int lca(vector<int> node1, vector<int> node2)
{
    // for(int i=0;i<node1.size();i++){
    //     for(int j=0;j<node2.size();j++){
    //         if(node1[i]==node2[j]){
    //             return node1[i];
    //         }
    //     }
    // }
    // return -1;
    // Optimized

    int i=node1.size()-1;
    int j=node2.size()-1;
    while(i>=0 && j>=0 && node1[i]==node2[j]){
        i--;
        j--;
    }
    i++;
    j++;
    return node1[i];
}

vector<int> path(Node *node, int data)
{
    if (node->data == data)
    {
        vector<int> vec;
        vec.push_back(node->data);
        return vec;
    }
    for (Node *child : node->children)
    {
        vector<int> ptc = path(child, data);
        if (ptc.size() > 0)
        {
            ptc.push_back(node->data);
            return ptc;
        }
    }
    vector<int> v;
    return v;
}

void vec_traverse(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " -> ";
    }
    cout << endl;
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
    vector<int> sla1, sla2;
    sla1 = path(root, 100);
    sla2 = path(root, 120);
    vec_traverse(sla1);
    vec_traverse(sla2);
    cout << "LCA is " << lca(sla1, sla2);
    return 0;
}