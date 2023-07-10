#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
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

// Approach1: SC: height, TC: nlogn
// bool findTree(Node *root, int n)
// {
//     if(root==nullptr){
//         return false;
//     }
//     bool res;
//     if (root->data == n)
//     {
//         return true;
//     }
//     if (n < root->data)
//     {
//         int res = findTree(root->left, n);
//         if (res)
//         {
//             return true;
//         }
//     }
//     else if (n > root->data)
//     {
//         int res = findTree(root->right, n);
//         if (res)
//         {
//             return true;
//         }
//     }
//     return false;
// }

// void traversalAndPrint(Node* root,Node* node, int tar){
//     if(node==nullptr){
//         return;
//     }
//     traversalAndPrint(root,node->left,tar);
//     int comp= tar- node->data;
//     if(node->data<comp){
//         if(findTree(root,comp)==true){
//             cout<<node->data<<" , "<<comp<<endl;
//         }
//     }
//     traversalAndPrint(root,node->right,tar);
// }

// Approach2: SC & TC: n
// vector<int> vec;

// void tnf(Node *root)
// {
//     if (root == nullptr)
//     {
//         return;
//     }
//     tnf(root->left);
//     vec.push_back(root->data);
//     tnf(root->right);
// }

// SC & TC: h

class ITPair
{
public:
    Node *node;
    int state = 0;
    ITPair(Node *node, int state)
    {
        this->node = node;
        this->state = state;
    }
};

Node *getNextFromNormalInorder(stack<ITPair> st)
{
    while (st.size() > 0)
    {
        ITPair top = st.top();
        if (top.state == 0)
        {
            if (top.node->left != nullptr)
            {
                st.push(ITPair(top.node->left, 0));
            }
            top.state++;
        }
        else if (top.state == 1)
        {
            if (top.node->right != nullptr)
            {
                st.push(ITPair(top.node->right, 1));
            }
            top.state++;
            return top.node;
        }
        else
        {
            st.pop();
        }
    }
    return nullptr;
}

Node *getNextFromReverseInorder(stack<ITPair> st)
{
    while (st.size() > 0)
    {
        ITPair top = st.top();
        if (top.state == 0)
        {
            if (top.node->right != nullptr)
            {
                st.push(ITPair(top.node->right, 0));
            }
            top.state++;
        }
        else if (top.state == 1)
        {
            if (top.node->left != nullptr)
            {
                st.push(ITPair(top.node->left, 0));
            }
            top.state++;
            return top.node;
        }
        else
        {
            st.pop();
        }
    }
    return nullptr;
}

void bestApproach(Node *root, int tar)
{
    stack<ITPair> ls;
    stack<ITPair> rs;
    ls.push(ITPair(root, 0));
    rs.push(ITPair(root, 0));
    Node *left = getNextFromNormalInorder(ls);
    Node *right = getNextFromReverseInorder(rs);
    while (left->data < right->data)
    {
        if (left->data + right->data < tar)
        {
            left = getNextFromNormalInorder(ls);
        }
        else if (left->data + right->data > tar)
        {
            right = getNextFromReverseInorder(rs);
        }
        else
        {
            cout << left->data << " , " << right->data << endl;
            left = getNextFromNormalInorder(ls);
            right = getNextFromReverseInorder(rs);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    Node *root = new Node(50);
    root->left = new Node(25);
    root->left->left = new Node(20);
    root->left->right = new Node(37);
    root->right = new Node(75);
    // traversalAndPrint(root,root,t);
    // tnf(root);
    // int li = 0, ri = vec.size() - 1;
    // while (li<ri)
    // {
    //     int left= vec[li];
    //     int right= vec[ri];
    //     if(left+right<t){
    //         li++;
    //     }else if(left+right>t){
    //         ri--;
    //     }else{
    //         cout<<left<<" , "<<right<<endl;
    //         li++;
    //         ri--;
    //     }
    // }
    bestApproach(root,t);
    return 0;
}