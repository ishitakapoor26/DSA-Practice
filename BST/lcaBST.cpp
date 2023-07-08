#include<iostream>
#include<vector>
#include<algorithm>
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

// vector<int> nodeToRoot(Node* root, int ele){
//     vector<int> res;
//     if (root->data == ele)
//     {
//         res.push_back(root->data);
//         // cout << root->data << " ";
//         return res;
//     }

//     if (root->left != NULL && ele<root->data)
//     {
//         res = nodeToRoot(root->left, ele);
//     }
//     if (root->right != NULL && res.size() == 0 && ele>root->data)
//     {
//         res = nodeToRoot(root->right, ele);
//     }
//     if (res.size() != 0)
//     {
//         res.push_back(root->data);
//         // cout<<root->data<<" ";
//     }
//     return res;
// }


// int lcaBST(Node* root, int data1, int data2){
//     vector<int> v1= nodeToRoot(root,data1);
//     vector<int> v2= nodeToRoot(root,data2);
//     sort(v1.begin(),v1.end());
//     sort(v2.begin(),v2.end());
//     return v1.size()<v2.size()?v1[0]:v2[0];
// }

int lcaBSTree(Node* root, int data1, int data2){
    if(data1<root->data && data2<root->data){
        return lcaBSTree(root->left, data1, data2);
    }else if(data1>root->data && data2>root->data){
        return lcaBSTree(root->right,data1,data2);
    }else{
        return root->data;
    }
}

int main(){
    int d1,d2;
    cin>>d1>>d2;
    Node *root = new Node(50);
    root->left = new Node(25);
    root->left->left = new Node(20);
    root->left->right = new Node(37);
    root->right = new Node(75);
    int lca= lcaBSTree(root,d1,d2);
    cout<<"LCA is: "<<lca<<endl;
    // vector<int> res= nodeToRoot(root, d1);
    // vector<int> ans= nodeToRoot(root, d2);
    // for(int i: res){
    //     cout<<i<<" , ";
    // }
    // cout<<endl;
    // for(int i: ans){
    //     cout<<i<<" , ";
    // }
    return 0;
}