#include <iostream>
#include<vector>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data= data;
        left= NULL;
        right=NULL;
    }
};

vector<int> nodeToRoot(Node* root, int ele){
    if(root->data==ele){
        vector<int> vec;
        vec.push_back(root->data);
        cout<<root->data<<" ";
        return vec;
    }

    vector<int> res;
    if(root->left != NULL){
    res= nodeToRoot(root->left, ele);
    }
    if(root->right != NULL && res.size()==0){
    res= nodeToRoot(root->right, ele);
    }
    if(res.size() !=0){
        res.push_back(root->data);
        // cout<<root->data<<" ";
    }
    return res;
}

int main(){
    Node* root = new Node(50);
    root->left= new Node(25);
    root->right= new Node(75);
    root->left->left= new Node(12);
    root->left->right= new Node(37);
    root->left->right->left= new Node(30);
    root->right->left= new Node(62);
    root->right->left->right= new Node(70);
    root->right->right= new Node(57);
    int ele;
    cout<<"Enter the element: "<<endl;
    cin>>ele;
    vector<int> vec= nodeToRoot(root,ele);
    cout<<endl;
    for(int i: vec){
        cout<<i<<" ";
    }
    return 0;
}