#include<bits/stdc++.h>
using namespace std;

// mim ops to make all disconnected computers connected
void dfs(unordered_map<int, vector<int> >& adj, int curr, vector<bool> &vis){
    if(vis[curr]==true)return;

    if(!vis[curr])vis[curr]= true;
    for(auto it: adj[curr]){
        if(vis[it]== false){
            dfs(adj,it,vis);
        }
    }
}

int makeConnections(int N, int connections[][2], int M){
    vector<bool> vis(N, false);
   unordered_map<int, vector<int> > adj;

   int edges=0;
   for(int i=0; i<M; i++){
   adj[connections[i][0]].push_back(connections[i][1]);
   adj[connections[i][1]].push_back(connections[i][0]);
     edges +=1;
   }
   int components=0;
   for(int i=0; i<N; i++){
      if (vis[i] == false) {
 
            components += 1;
 
            // Perform DFS
            dfs(adj, i, vis);
        }
   }
   if(edges< N-1)return -1;

    int redundant = edges - ((N - 1)
                             - (components - 1));
 
    // Check if components can be
    // rearranged using redundant edges
    if (redundant >= (components - 1))
        return components - 1;
 
    return -1;

}
void fun(int N, int connections[][2], int M){
    int minOps = makeConnections(N,connections,M);

    cout<<minOps;
}
int main(){
      int N = 4;
 
    // Given set of connections
    int connections[][2] = {
        { 0, 1 }, { 0, 2 }, { 1, 2 }
    };
    int M = sizeof(connections)
            / sizeof(connections[0]);
 
    // Function call to check if it is
    // possible to connect all computers or not
    fun(N, connections, M);
    return 0;
}