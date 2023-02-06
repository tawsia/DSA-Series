#include<bits/stdc++.h>
using namespace std;

// graph colouring problem

void solve(){
    int v,e;
    cin>>v>>e;
    vector<vector<int>> g(v);
    for(int i=0; i<e; i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);

    }
    int res[v];
    bool avail[v];
    res[0]=0; //coloured with zero
    for(int i=1;i<v;i++)res[i]= -1;
    for(int i=0;i<v; i++)avail[i]= false;

    int cN=0;
    for(int i=1;i<v; i++){
        for(auto it: g[i]){
            if(res[it] != -1){
                avail[res[it]]= true;
            }
        }
    
    int cr;
    for(cr=0;cr<v; cr++){
        if(avail[cr]== false)break;
    }

    res[i]= cr;
    cN = max(cN, cr+1);

    // resetting it again
    for(auto it: g[i]){
        if(res[it] != -1){
          avail[res[it]]= false;
        }
      }
    }
    cout<<cN<<endl;
    for(int i=0;i<v; i++)cout<<res[i]<<" ";

}

int main(){
  solve();


    return 0;
}