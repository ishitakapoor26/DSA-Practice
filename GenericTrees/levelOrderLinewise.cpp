#include <iostream>
#include <vector>
#include <queue>
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

// void levelOrderLinewise(Node* root){
//     queue<Node* > mq,cq;
//     mq.push(root);
//     while(mq.size()>0){
//         root= mq.front();
//         mq.pop();
//         cout<<root->data<<" ";
//         for(Node* child: root->children){
//             cq.push(child);
//         }
//         if(mq.size()==0){
//             mq=cq;
//             cq= {};
//             cout<<endl;
//         }
//     }
// }

// Approach 2: Delimiter approach

// void levelOrderLinewise(Node *node)
// {
//     queue<Node *> q;
//     q.push(node);
//     q.push(NULL);
//     while (q.size() > 0)
//     {
//         node = q.front();
//         q.pop();
//         if (node != NULL)
//         {
//             cout << node->data << " ";
//             for (Node *child : node->children)
//             {
//                 q.push(child);
//             }
//         }else{
//             if(q.size()>0){
//                 q.push(NULL);
//                 cout<<endl;
//             }
//         }
//     }
// }

// Approach 3: Counter Approach

void levelOrderLinewise(Node *node)
{
    queue<Node *> q;
    q.push(node);
    while (q.size() > 0)
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            node = q.front();
            q.pop();
            cout << node->data << " ";
            for (Node *child : node->children)
            {
                q.push(child);
            }
        }
        cout << endl;
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
    root->children[2]->children.push_back(newNode(100));
    root->children[1]->children[1]->children.push_back(newNode(110));
    root->children[1]->children[1]->children.push_back(newNode(120));
    levelOrderLinewise(root);
    return 0;
}