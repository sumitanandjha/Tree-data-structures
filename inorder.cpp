#include<bits/stdc++.h>
using namespace std;
//creating a tree.
struct Node {
    int data;
    struct Node *left,*right;

};
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data =data;
    temp->left = temp->right = NULL;
    return temp; 
}
void printinorder(struct Node *node)
{
    if(node == NULL)
    return;
    printinorder(node->left);
    cout<<node->data<<" ";
    printinorder(node->right);

}
int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    // function call
    cout<<"Inorder traversal of binary tree is"<<endl;
    printinorder(root);
    return 0;

}