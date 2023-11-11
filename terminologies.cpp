//c++ program todemonstrate some of the tree terminologies.
#include<bits/stdc++.h>
using namespace std;

//function to add an edgeb/w vertices x and y.

void addEdge(int x,int y,vector<vector<int> >&adj)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}

//function to print the parent of each node.
void printparents(int node,vector<vector<int>>&adj,int parent)
{
    if(parent == 0)
    cout<<node<<"->Root"<<endl;
    else
    {
        cout<<node<< "->"<<parent<<endl;
    }
    //using DFS
    for(auto cur:adj[node])
    if(cur!=parent)
    printparents(cur,adj,node);
}
//function to print children of each node.
void printchildren(int root,vector<vector<int>>&adj)
{
    //use queue for bfs
    queue<int>q;
    //pushing the root.
    q.push(root);
    //visit array ro keep track of nodes that have been visited.
    int vis[adj.size()]={0};
    //BFS

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        vis[node]=1;
        cout<<node<<"->";
        for(auto cur: adj[node])
        if(vis[cur] == 0)
        {
            cout<<cur<<" ";
            q.push(cur);
        }
        cout<<endl;

    }
}
// function to print leaf nodes.
void printleafnodes(int root,vector<vector<int>>& adj)
{
    //leaf nodes have only one edge and are not the root.
    for(int i=1;i<adj.size();i++)
    {
        if(adj[i].size() == 1 && i!=root)
        cout<<i<<" ";
    }
    cout<<endl;
}
//function to print the degrees .
void printdegrees(int root,vector<vector<int>>& adj)
{
    for(int i=1;i<adj.size();i++)
    {
        cout<<i<<" ";
        if(i==root)
        cout<<adj[i].size()<<endl;
        else
        cout<<adj[i].size() - 1<<endl;
    }
}
int main()
{
    int N=7,root =1;
    vector<vector<int>> adj(N+1,vector<int>());
    // creating tree
    addEdge(1,2,adj);
    addEdge(1,3,adj);
    addEdge(1,4,adj);
    addEdge(2,5,adj);
    addEdge(2,6,adj);
    addEdge(4,7,adj);
    //printing the parents of each node.
    cout<<"the parents of each node are:"<<endl;
    printparents(root,adj,0);

    //printing the children of each node()
    cout<<"the children are:"<<endl;
    printchildren(root,adj);
    //printing the leaf of each node.
    cout<<"the degrees of each node are"<<endl;
    printdegrees(root,adj);
    return 0;
}