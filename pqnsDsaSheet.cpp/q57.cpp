#include<bits/stdc++.h>
using namespace std;

#define maxi 100000

// mini time to complete jobs in dag
vector<int> adj[maxi];
int inDegree[maxi];
int jobs[maxi];
void addEdge( int u, int v){
    adj[u].push_back(v);
  
  inDegree[v]++;
}

void func(int n, int m){
    queue<int> q;

    for(int i=1; i<=n; i++){
        if(inDegree[i]==0){
         q.push(i);
         jobs[i] =1;
        }
    }

    while(!q.empty()){
        int curr= q.front();
        q.pop();
        for(auto it: adj[curr]){
            inDegree[it]--;
            if(inDegree[it]==0) jobs[it]= jobs[curr]+1;q.push(it);
        }
    }
    for(int i=1; i<=n; i++){
        cout<<jobs[i]<<" ";
        cout<<endl;
    }
}
int main(){
      int n, m;
    n = 10;
    m = 13;
 
    // Given Directed Edges of graph
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(1, 5);
    addEdge(2, 3);
    addEdge(2, 8);
    addEdge(2, 9);
    addEdge(3, 6);
    addEdge(4, 6);
    addEdge(4, 8);
    addEdge(5, 8);
    addEdge(6, 7);
    addEdge(7, 8);
    addEdge(8, 10);
 
    // Function Call
    func(n, m);
    return 0;
}