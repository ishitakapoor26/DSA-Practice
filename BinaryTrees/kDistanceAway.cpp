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
        left = right = NULL;
    }
};

void display(vector<Node*> vec){
    for(Node* node: vec){
        cout<<node->data<<" ";
    }
    cout<<endl;
}

vector<Node *> nodeToRoot(Node *root, int ele)
{
    vector<Node *> vec;
    if (root->data == ele)
    {
        vec.push_back(root);
        // cout<<root->data<<" ";
        return vec;
    }
    if (root->left != NULL)
    {
        vec = nodeToRoot(root->left, ele);
    }
    if (root->right != NULL && vec.size() == 0)
    {
        vec = nodeToRoot(root->right, ele);
    }
    if (vec.size() != 0)
    {
        // cout << root->data << " ";
        vec.push_back(root);
    }
    return vec;
}

vector<Node *> kLevelsDown(Node *root, int distance, Node* blocker)
{
    vector<Node *> res, rres;
    if (root == nullptr || distance < 0)
    {
        return res;
    }
    if (distance == 0)
    {
        res.push_back(root);
        return res;
    }
    if (root->left != NULL && root->left != blocker)
    {
        res = kLevelsDown(root->left, distance-1, blocker);
    }
    if (root->right != NULL && root->right != blocker)
    {
        rres = kLevelsDown(root->right, distance-1, blocker);
        res.insert(res.end(), rres.begin(), rres.end());
    }
    // display(res);
    return res;
}

vector<Node *> kLevelsDownHelper(Node *root, int ele, int dis)
{
    vector<Node *> res = nodeToRoot(root, ele);
    vector<Node *> fres, vec;
    for (int i=0;i<res.size();i++)
    {
        cout<<"Node data= "<<res[i]->data<<endl;
        if(i==0){
        vec = kLevelsDown(res[i], dis - i, nullptr);
        }else{
        vec = kLevelsDown(res[i], dis - i, res[i-1]);
        }
        display(vec);
        fres.insert(fres.end(), vec.begin(), vec.end());
    }
    // display(fres);
    return fres;
}

int main()
{
    Node *root = new Node(100);
    root->left = new Node(50);
    root->right = new Node(80);
    root->left->left = new Node(25);
    root->left->left->right = new Node(37);
    root->left->left->left = new Node(20);
    root->left->left->left->left = new Node(5);
    root->left->right = new Node(75);
    root->left->right->right = new Node(57);
    root->left->right->left = new Node(62);
    root->left->right->left->left = new Node(58);
    root->left->right->left->left->left= new Node(2);
    root->left->right->left->left->left->right= new Node(10);
    root->left->right->left->left->left->left = new Node(3);
    int ele, dis;
    cout << "Enter the element: " << endl;
    cin >> ele;
    cout << "Enter the distance: " << endl;
    cin >> dis;
    // vector<int> vec = nodeToRoot(root, ele);
    // cout << endl;
    // for (int i : vec)
    // {
    //     cout << i << " ";
    // }
    vector<Node *> res = kLevelsDownHelper(root, ele, dis);
    for (Node *node : res)
    {
        cout << node->data << " ";
    }
    return 0;
}