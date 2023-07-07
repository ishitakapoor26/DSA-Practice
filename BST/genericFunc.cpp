#include <iostream>
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

int sizeTree(Node *root)
{
    int lcount=0, rcount=0;
    lcount+= sizeTree(root->left);
    rcount+= sizeTree(root->right);
    return lcount+rcount+1;
}

int sumTree(Node *root)
{
    int lsum = 0, rsum = 0;
    if (root == nullptr)
    {
        return 0;
    }
    lsum += sumTree(root->left);
    rsum += sumTree(root->right);
    return lsum + rsum + root->data;
}

int maxTree(Node *root)
{
    if (root->right == nullptr && root->left == nullptr)
    {
        return root->data;
    }
    int ans = maxTree(root->right);
    return ans;
}

int minTree(Node *root)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        return root->data;
    }
    int ans = minTree(root->left);
    return ans;
}

bool findTree(Node *root, int n)
{
    bool res;
    if (root->data == n)
    {
        return true;
    }
    if (n < root->data)
    {
        int res = findTree(root->left, n);
        if (res)
        {
            return true;
        }
    }
    else if (n > root->data)
    {
        int res = findTree(root->right, n);
        if (res)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    Node *root = new Node(4);
    root->left= new Node(2);
    root->left->left= new Node(1);
    root->left->right= new Node(3);
    root->right= new Node(6);
    root->right->left= new Node(5);
    root->right->right= new Node(7);
    int sum = sumTree(root);
    bool find = findTree(root, n);
    int min = minTree(root);
    int max = maxTree(root);
    int size = sizeTree(root);
    if(find){
        cout<<n<<" is found!"<<endl;
    }
    // cout<<"Size is: "<<size<<endl;
    // cout<<"Max: "<<max<<endl;
    // cout<<"Min: "<<min<<endl;
    // cout<<"Sum: "<<sum<<endl;
    return 0;
}