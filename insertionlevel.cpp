//c++ program to insert a node ina binary tree in level order traversal
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node * create(int data)
{
    Node *newNode = new Node();
    if(!newNode)
    {
        cout<<"memory error"<<endl;
        return NULL;
    }
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    return newNode;

}
Node *InsertNode(Node *root,int data)
{
    if(root == NULL)
    {
        root = create(data);
        return root;
    }
    queue<Node *> q;
    q.push(root);
    while(!q.empty())
    {
        Node *temp =q.front();
        q.pop();
        if(temp->left!=NULL)
        q.push(temp->left);
        else
        {
            temp->left=create(data);
            return root;
        }
        if(temp->right!=NULL)
        q.push(temp->right);
        else
        {
            temp->right=create(data);
            return root;
        }
    }
}
void inorder(Node *temp)
{
    if(temp==NULL)
    return ;
    inorder(temp->left);
    cout<<temp->data<<" ";
    inorder(temp->right);
}
int main()
{
    Node *root =create(10);
    root->left=create(11);
    root->left->left=create(7);
    root->right=create(9);
    root->right->right=create(8);

    inorder(root);
    cout<<endl;
    int key =12;
    root=InsertNode(root,key);
    inorder(root);
    return 0;
}