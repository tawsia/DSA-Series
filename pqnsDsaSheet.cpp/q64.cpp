#include<bits/stdc++.h>
using namespace std;
// vertex cover problem
int main(){

    int v,e;
    cin>>v>>e;
    vector<int>g[v+1];
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<bool> vis(v, false);

    for(int i=0;i<v;i++){
        if(vis[i]== false){
            for(auto it: g[i]){
                if(!vis[it]){
                    vis[it]= true;
                    vis[i]= true;
                    break;
                }
            }
        }
 
    }
    for(int i=0;i<v;i++){
        if(vis[i]){
            cout<<i<<"  ";
        }
    }
    return 0;
}