#include<bits/stdc++.h>
using namespace std;


struct Node 
{
  int key;
  struct  Node*left,*right;
};
struct Node* newnode(int key)
{
    struct Node *temp =new Node;
    temp->key=key;
    temp->left=temp->right=NULL;
    return temp;
};
void inorder(struct Node* temp)
{
    if(!temp)
    return;
    inorder(temp->left);
    cout<<temp->key<<" ";
    inorder(temp->right);
}
//function to delete the given deepest node.
void deletedeepest(struct Node* root,struct Node* d_node)
{
    queue<struct Node*>q;
    q.push(root);
    //do level order traversal.
    struct Node *temp;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        if(temp == d_node)
        {
            temp == NULL;
        }
        delete (d_node);
        return;

    }
    if(temp->right)
    {
        if(temp->right == d_node)
        {
            temp->right = NULL;
            delete(d_node);
            return;
        }
        else
        q.push(temp->right);
    }
    if(temp->left)
    {
        if(temp->left== d_node)
        {
            temp->left = NULL;
            delete(d_node);
            return;
        }
        else
        q.push(temp->left);
    }
}
//function to delete element in binary tree
Node *deletion(struct Node *root,int key)
{
    if(root==NULL)
    return root;
    if(root->left == NULL && root->right ==NULL)
    {
        if(root->key ==key)
        return NULL;
        else
        return root;
    }
    queue<struct Node *>q;
    q.push(root);

    struct Node *temp;
    struct Node *key_node =NULL;
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp->key == key)
        key_node =temp;
        if(temp->left)
        q.push(temp->left);
        if(temp->right)
        q.push(temp->right);
    }
    if(key_node != NULL)
    {
        int x =temp->key;
        deletedeepest(root,temp);
        key_node->key =x;
    }
    return root;
}
int main()
{
    struct Node *root = newnode(10);
    root->left=newnode(11);
    root->left->left=newnode(7);
    root->left->right=newnode(12);
    root->right=newnode(9);
    root->right->right=newnode(15);
     inorder(root);
     cout<<endl;
     int key =11;
    root =deletion(root,key);
    inorder(root);
    cout<<endl;
}