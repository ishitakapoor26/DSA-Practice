#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void levelOrder(Node *node)
{
    queue<Node *> q;
    q.push(node);
    while (q.size() > 0)
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            Node *remove = q.front();
            q.pop();
            cout << remove->data << " ";
            if (remove->left != NULL)
            {
                q.push(remove->left);
            }
            if (remove->right != NULL)
            {
                q.push(remove->right);
            }
        }
        cout << endl;
    }
}

int main()
{
    Node *root = new Node(50);
    root->left = new Node(25);
    root->right = new Node(75);
    root->left->left = new Node(12);
    root->left->right = new Node(37);
    root->left->right->left = new Node(30);
    root->right->left = new Node(62);
    root->right->left->right = new Node(70);
    root->right->right = new Node(87);
    levelOrder(root);
    return 0;
}