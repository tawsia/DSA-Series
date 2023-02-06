#include<bits/stdc++.h>
using namespace std;
// Two clique
// int f=0;
bool func(int src,vector<int> &color, vector<int>g1[]){
 color[src]= 0;
 queue<int>q;
 q.push(src);
 while(!q.empty()){
    int curr= q.front();
    q.pop();
    for(auto it: g1[curr]){
        if(!color[it]){
            color[it]= !color[curr];
            q.push(it);
        }
        else if(color[it]== color[curr]){
            return false;
        }
    }
 }
 return true;
}
int main(){
 
  int v, e;
  cin>>v>>e;

  vector<int> g[v];
  for(int i=0;i<e;i++){
    int x,y;
    cin>>x>>y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  vector<int> g1[v];
   for(int i=0;i<v;i++){
    for(int j=0;j<v;j++){
        if(i!=j){
            g1[i].push_back(j);
            g1[j].push_back(i);
        }
    }
   }
  vector<int> color(v,-1);

  if(func(0,color,g1))cout<<"Two Clique";
  else cout<<"Not POssible";
    return 0;
}