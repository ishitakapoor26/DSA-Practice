#include<iostream>
#include<stack>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data= data;
        right=left= NULL;
    }
};

void preOreder(Node* root){
    stack<Node* > st;
    int s= st.size();
    if(s==0){
        st.push(root);
        s++;
    }
    while(s>0){
        for(int i=0;i<s;i++){
            Node* remove= st.top();
            st.pop();
            cout<<remove->data<<" -> ";
            s--;
            if(remove->right !=NULL){
                st.push(remove->right);
                s++;
            }
            if(remove->left !=NULL){
                st.push(remove->left);
                s++;
            }
        }
    }
}

void display(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" -> ";
    display(root->left);
    display(root->right);
}

int main(){
    Node* root = new Node(50);
    root->left= new Node(25);
    root->right= new Node(75);
    root->left->left= new Node(12);
    root->left->right= new Node(37);
    root->right->left= new Node(62);
    root->right->right= new Node(57);
    cout<<"Original Tree: "<<endl;
    display(root);
    cout<<endl;
    cout<<"Tree after Pre Order Iterative Traversal: "<<endl;
    preOreder(root);
    return 0;
}