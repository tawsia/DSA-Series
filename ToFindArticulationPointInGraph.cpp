#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int> &disc, vector<int> &low, 
unordered_map<int,bool> &vis,unordered_map<int,list<int>> &adj, 
vector<int> &ap,int timer ){
vis[node]= true;
disc[node]=low[node]= timer++;
int child= 0;

for(auto neighbour: adj[node]){
    if(neighbour== parent){
        continue;
    }
    if(!vis[neighbour]){
        dfs(neighbour,node,disc,low,vis,adj,ap,timer);
        low[node]= min(low[node], low[neighbour]);

        // check AP or not
        if(low[neighbour]>=disc[node] && parent != -1){
            ap[node]= true;
        }
        child++;
    }
    else{
        // back edge
        low[node]= min(low[node], disc[neighbour]);
    }

}
if(parent == -1 && child>1){
    ap[node] = true;
}

   
}
int main(){

int n=5;
int e= 5;
vector<pair<int,int>> edges;
edges.push_back(make_pair(0,3));
edges.push_back(make_pair(3,4));
edges.push_back(make_pair(0,4));
edges.push_back(make_pair(0,1));
edges.push_back(make_pair(1,2));

// create adj list
unordered_map<int,list<int>> adj;
for(int i=0; i<edges.size(); i++){
    int u= edges[i].first;
    int v= edges[i].second;

    adj[u].push_back(v);
    adj[v].push_back(u);

}


  int timer= 0;
  vector<int> disc(n);
  vector<int> low(n);
// int parent = -1;
unordered_map<int,bool> vis;
vector<int> ap(n,0);

for(int i=0; i<n; i++){
    disc[i]= -1;
    low[i]= -1;
    // vis[i]= false;
}
// do dfs
for(int i=0; i<n; i++){
    if(!vis[i]){
        dfs(i,-1,disc,low,vis,adj,ap,timer);
    }
}

// print ap
cout<<"Articulation Points are as follows: "<<endl;
for(int i=0; i<n; i++){
    if(ap[i] != 0){
        cout<<i<<" ";
    }
}
    return 0;
}