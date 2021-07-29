#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>adj[],vector<int>&vis,stack<int>&s){
    vis[node] = 1;
    for(auto x:adj[node]){
        if(vis[x]==0){
            dfs(x,adj,vis,s);
        }
    }
    s.push(node);
}

void topoSort(int vertex,vector<int>adj[]){
    vector<int>vis(vertex,0);
    stack<int>s;
    for(int i=0;i<=vertex;i++){
        if(vis[i]==0){
            dfs(i,adj,vis,s);
        }
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return;
}

void addEdge(int u,int v,vector<int>adj[]){
    adj[u].push_back(v);
}


int main()
    {
        int vertex = 5;
        vector<int>adj[6];
        addEdge(5,0,adj);
        addEdge(4,0,adj);
        addEdge(5,2,adj);
        addEdge(4,1,adj);
        addEdge(3,1,adj);
        addEdge(2,3,adj);
        
        topoSort(vertex,adj);
    }
