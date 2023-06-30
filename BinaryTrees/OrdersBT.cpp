#include<iostream>
#include<utility>
#include<stack>
#include<string>
using namespace std;

// Using pair class method:
// 1-> pre, state increase, move towards left
// 2-> in, state increase, move towards right
// 3-> post, state increase, pop

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

void iterativePrePostInTraversal(Node* node){
    stack<pair<Node* , int>> st;
    st.push(make_pair(node, 1));
    string pre="";
    string post="";
    string in="";
    while(st.size()!=0){
        if(st.top().second==1){
            pre+= to_string(st.top().first->data) + " ";
            st.top().second++;
            if(st.top().first->left !=nullptr){
                st.push(make_pair(st.top().first->left, 1));
            }
        }else if(st.top().second==2){
            in+= to_string(st.top().first->data) + " ";
            st.top().second++;
            if(st.top().first->right !=nullptr){
                st.push(make_pair(st.top().first->right, 1));
            }
        }else{
            post+= to_string(st.top().first->data) + " ";
            st.pop();
        }
    }
    cout<<pre<<endl;
    cout<<in<<endl;
    cout<<post<<endl;
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
    // cout<<"Tree after Pre Order Iterative Traversal: "<<endl;
    // preOreder(root);
    iterativePrePostInTraversal(root);
    return 0;
}