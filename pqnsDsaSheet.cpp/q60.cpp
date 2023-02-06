// Longest path in a DAG

#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100005];
bool vis[100005];
int dp[100005];
void dfs(int vertex){
    vis[vertex]= 1;
      dp[vertex]=0;// to stop here or move forward
       for(auto it: adj[vertex]){
          if(!vis[it]){
          dfs(vertex);
      }
       dp[vertex]= max(dp[vertex], 1+dp[it]);

      }
}
 int main(){
 
 int  n, m;
 cin>>n>>m;

 for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
 }

 for(int i=1;i<=n;i++){
    if(!vis[i]){
        dfs(i);
    }
 }

 int ans=0;
 for(int i=1;i<=n;i++){
    ans= max(ans,dp[i]);
 }
 cout<<ans;
//  return 0;
    

}
 