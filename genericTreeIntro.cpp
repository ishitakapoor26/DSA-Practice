#include <iostream>
#include<stack>
#include<vector>
using namespace std;

struct Node
{
    int data;
    vector<Node *> children;
};

Node* newNode(int val){
    Node *node =new Node;
    node->data=val;
    return node;
}

Node* constructor(vector<int> arr, int n){
    Node* root =NULL;
    stack<Node*> st;
    for(int i=0;i<n;i++){
        if(arr[i]==-1){
            st.pop();
        }else{
            Node* t= newNode(arr[i]);
            if(st.size()==0){
                root=t;
            }else{
                st.top()->children.push_back(t);
            }
            st.push(t);
        }
    }
    return root;
}

void display(Node* node){
    cout<<node->data<<"-> ";
    for(Node *child: node->children){
        cout<<child->data<<", ";
    }
    cout<<endl;
    for(Node *child: node->children){
        display(child);
    }
}

int main(){
    Node *root = newNode(10);
    (root->children).push_back(newNode(2));
    (root->children).push_back(newNode(34));
    (root->children).push_back(newNode(56));
    (root->children).push_back(newNode(100));
    (root->children[0]->children).push_back(newNode(77));
    (root->children[0]->children).push_back(newNode(88));
    (root->children[2]->children).push_back(newNode(1));
    (root->children[3]->children).push_back(newNode(7));
    (root->children[3]->children).push_back(newNode(8));
    (root->children[3]->children).push_back(newNode(9));
    display(root);
    return 0;
}
