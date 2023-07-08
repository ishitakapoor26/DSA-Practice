#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

int max(Node* root){
    if(root->right==nullptr){
        return root->data;
    }
    return max(root->right);
}

Node *removeNode(Node *root, int data)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (data < root->data)
    {
        root->left = removeNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = removeNode(root->right, data);
    }
    else
    {
        if (root->left != nullptr && root->right != nullptr)
        {
            int m = max(root->left);
            root->data=m;
            root->left= removeNode(root->left,m);
            cout<<"Node removed"<<endl;
            return root;
        }
        else if (root->left != nullptr)
        {
            cout<<"Node removed"<<endl;
            return root->left;
        }
        else if (root->right != nullptr)
        {
            cout<<"Node removed"<<endl;
            return root->right;
        }
        else
        {
            cout<<"Node removed"<<endl;
            return nullptr;
        }
    }
    return root;
}

void display(Node* root){
    if(root==nullptr){
        return;
    }
    cout<<root->data<<" -> ";
    display(root->left);
    display(root->right);
}

int main()
{
    int data;
    cin>>data;
    Node *root = new Node(50);
    root->left = new Node(25);
    root->left->left = new Node(20);
    root->left->right = new Node(37);
    root->right = new Node(75);
    root->right->left = new Node(72);
    Node* newNode= removeNode(root,data);
    display(root);
    return 0;
}