#include<bits/stdc++.h>
using namespace std;


int main(){
       int u=4;
    int g[][u]= { {0, 1, 1, 0},
                       {1, 0, 1, 1},
                       {1, 1, 0, 1},
                       {0, 1, 1, 0}
                     };

    bool flag=0;
    int count=0;
    for(int i=0;i<u;i++){
      for(int j=0;j<u;j++){
        for(int k=0;k<u;k++){
            if(g[i][j] && g[j][k] && g[k][i]){
                count++;
                // flag=1;
            }
        }
      }
    }
    if(flag)count /= 3;
    else count /= 6;

    cout<<count<<endl;
}