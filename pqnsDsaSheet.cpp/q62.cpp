#include<bits/stdc++.h>
using namespace std;
// Find if there is a path of more than k length from a source
bool func(int src, int k, vector<bool> &vis,vector<pair<int,int>> g[]){
    vis[src]=true;
    if(k<=0)return true;
    
    for(auto it: g[src]){
       int v= it.first;
       int w= it.second;

       if(vis[v]== true)continue; //cycle is prsent, ignore
       if(w>=k)return true; //existing weiht is greater than k then we found our ans 

       vis[v]=true;

       if(func(v,k-w,vis,g))return true;

    }
    vis[src]=false; //backtracking
  return false;

}
int main(){

    int v,e;
    cin>>v>>e;
    // cin>>n;
    int k;
    cin>>k;
    vector<pair<int,int>> g[v+1];
    for(int i=0;i<e;i++){
        int x,y,w;
        cin>>x>>y>>w;
        g[x].push_back({y,w});
        g[y].push_back({x,w});
    }

    vector<bool>vis(v+1,false);
     cout<<func(1,k,vis,g);
     return 0;
}