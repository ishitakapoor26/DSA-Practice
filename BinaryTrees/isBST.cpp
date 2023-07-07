#include <iostream>
#include <vector>
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
        left = right = nullptr;
    }
};

bool isBST = true;

vector<int> isBSTree(Node *root)
{
    vector<int> p;
    if (root == NULL)
    {
        p.push_back(0);
        return p;
    }
    vector<int> lBST = isBSTree(root->left);
    vector<int> rBST = isBSTree(root->right);
    if (isBST == true && root->left!=NULL && root->right != NULL)
    {
        for (int i : lBST)
        {
            if (root->data < i)
            {
                isBST = false;
                return p;
            }
        }
        for (int i : rBST)
        {
            if (root->data > i)
            {
                isBST = false;
                return p;
            }
        }
        lBST.push_back(root->data);
        lBST.insert(lBST.end(), rBST.begin(), rBST.end());
        p=lBST;
        for (int i : p)
        {
            cout << i << " , ";
        }
    }
    return p;
}

int main(){
    Node* root= new Node(50);
    root->left= new Node(25);
    root->left->left= new Node(12);
    root->left->right= new Node(52);
    root->left->right->left= new Node(30);
    root->left->right->right= new Node(40);
    root->right= new Node(75);
    root->right->left= new Node(62);
    root->right->left->left= new Node(60);
    root->right->left->right= new Node(70);
    root->right->right= new Node(87);
    vector<int>p= isBSTree(root);
    if(isBST){
        cout<<endl<<"Given Tree is Binary Search Tree";
    }else{
        cout<<endl<<"Not BST";
    }
    return 0;
}