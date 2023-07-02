#include<iostream>
#include <vector>
#include<numeric>
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

void display(vector<Node*> vec){
    for(Node* node: vec){
        cout<<node->data<<" ";
    }
    cout<<endl;
}

void displayVec(vector<int> vec){
    for(int i : vec){
        cout<<i<<" ";
    }
    cout<<endl;
}

vector<Node*> findLeafHelper(Node* root){
    vector<Node*> res;
    if(root==nullptr){
        return res;
    }
    if(root->left==nullptr && root->right==nullptr){
        res.push_back(root);
        return res;
    }
    vector<Node*> lres= findLeafHelper(root->left);
    vector<Node*> rres= findLeafHelper(root->right);
    res.insert(res.end(),lres.begin(), lres.end());
    res.insert(res.end(),rres.begin(), rres.end());
    return res;
}

vector<int> nodeToRoot(Node* root, int node){
    vector<int> vec;
    if(root->data==node){
        vec.push_back(root->data);
        return vec;
    }
    if(root->left != nullptr){
        vec= nodeToRoot(root->left, node);
    }
    if(root->right!= nullptr && vec.size() == 0){
        vec= nodeToRoot(root->right, node);
    }
    if(vec.size()!=0){
        vec.push_back(root->data);
    }
    // displayVec(vec);
    return vec;
}

vector<vector<int>> pathToLeaf(Node* root, int low, int high){
    vector<Node*> leafNodes= findLeafHelper(root);
    // display(leafNodes);
    vector<int> leafPath;
    vector<vector<int>> finalPath;
    for(Node* i: leafNodes){
        leafPath= nodeToRoot(root, i->data);
        // displayVec(leafPath);
        int sum= accumulate(leafPath.begin(), leafPath.end(),0);
        // cout<<sum;
        if(sum>low && sum<=high){
            finalPath.push_back(leafPath);
        }
    }
    return finalPath;
}

int main(){
    int l, h;
    cout<<"Enter low range: "<<endl;
    cin>>l;
    cout<<"Enter high range: "<<endl;
    cin>>h;
    Node *root = new Node(50);
    root->left = new Node(25);
    root->right = new Node(75);
    root->left->left = new Node(12);
    root->left->right = new Node(37);
    root->left->right->left = new Node(30);
    root->right->left = new Node(62);
    root->right->left->right = new Node(70);
    root->right->right = new Node(57);
    vector<vector<int>> res= pathToLeaf(root, l, h);
    for(vector<int> path : res){
        for(int i: path){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}