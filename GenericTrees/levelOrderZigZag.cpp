#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct Node{
    int data;
    vector<Node* > children;
};

Node* newNode(int val){
    Node* node= new Node;
    node->data= val;
    return node;
}

void levelOrderZigZag(Node* node){
    stack<Node* > ms,cs;
    ms.push(node);
    int level=1;
    while(ms.size()>0){
        node= ms.top();
        ms.pop();
        cout<<node->data<<" ";
        if(level%2==1){
            for(int i=0;i<node->children.size();i++){
                Node* child= node->children[i];
                cs.push(child);
            }
        }else{
            for(int i=node->children.size()-1;i>=0;i--){
                Node* child= node->children[i];
                cs.push(child);
            }
        }
        if(ms.size()==0){
            ms=cs;
            cs={};
            level++;
            cout<<endl;
        }
    }
}

int main(){
    Node* root= newNode(10);
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
    levelOrderZigZag(root);
    return 0;
}