#include<bits/stdc++.h>
using namespace std;

void topoSort(int vertex,vector<int>adj[],vector<int>&indegree){
    queue<int>q;
    for(int i=0;i<=indegree.size();i++){
        if(indegree[i]==0)
            q.push(i);
    }
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for(auto x:adj[node]){
            indegree[x]--;
            if(indegree[x]==0)
                {
                    q.push(x);
                }
        }
    }
    return;
}

void addEdge(int u,int v,vector<int>adj[],vector<int>&indegree){
    indegree[v]++;
    adj[u].push_back(v);
}


int main()
    {
        int vertex = 5;
        vector<int>adj[6];
        vector<int>indegree(vertex,0);
        addEdge(5,0,adj,indegree);
        addEdge(4,0,adj,indegree);
        addEdge(5,2,adj,indegree);
        addEdge(4,1,adj,indegree);
        addEdge(3,1,adj,indegree);
        addEdge(2,3,adj,indegree);
        
        topoSort(vertex,adj,indegree);
    }
