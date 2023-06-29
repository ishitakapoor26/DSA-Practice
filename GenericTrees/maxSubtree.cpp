// doubt
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

int maxSum = 0;
int maxSumNode = 0;

int maxSumSubtree(Node *node)
{
    int sum = 0;
    for (Node *child : node->children)
    {
        int csum = maxSumSubtree(child);
        sum += csum;
    }
    sum += node->data;
    if (sum > maxSum)
    {
        maxSumNode = node->data;
        maxSum = sum;
    }
    return sum;
}

int main()
{
    Node *root = newNode(10);
    root->children.push_back(newNode(20));
    root->children.push_back(newNode(30));
    root->children.push_back(newNode(40));
    root->children[0]->children.push_back(newNode(-50));
    root->children[0]->children.push_back(newNode(-60));
    root->children[1]->children.push_back(newNode(70));
    root->children[1]->children.push_back(newNode(-80));
    root->children[1]->children.push_back(newNode(90));
    // root->children[1]->children[1]->children.push_back(newNode(-110));
    // root->children[1]->children[1]->children.push_back(newNode(120));
    root->children[2]->children.push_back(newNode(-100));
    cout << maxSumSubtree(root) << " @ " << maxSumNode;
    return 0;
}