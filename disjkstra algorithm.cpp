#include<bits/stdc++.h>
using namespace std;

void dijsktra(vector<pair<int,int>>adj[],int vertex,int src){
    // pq = {dist,node}
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>distance(vertex+1,INT_MAX);
    pq.push({0,src});
    distance[src] = 0;
    while(!pq.empty()){
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto x:adj[node]){
            if(dist + x.second<distance[x.first]){
                distance[x.first] = dist + x.second;
                pq.push({dist+x.second,x.first});
            }
        }
    }
    for(int i=1;i<distance.size();i++)
        cout<<distance[i]<<" ";
    return;
}

void addEdge(int u,int v,int wt,vector<pair<int,int>>adj[]){
    adj[u].push_back({v,wt});
    adj[v].push_back({u,wt});
    return;
}

int main()
    {
        vector<pair<int,int>>adj[6];
        int vertex = 5;
        addEdge(1,2,2,adj);
        addEdge(1,4,1,adj);
        addEdge(2,5,5,adj);
        addEdge(2,3,4,adj);
        addEdge(3,5,1,adj);
        addEdge(4,3,3,adj);
        int src = 4;
        dijsktra(adj,vertex,src);
    }
