#include<bits/stdc++.h>
using namespace std;
#define M 4
#define N 5

// common elements in all rows

void fun(int Mat[M][N]){
   unordered_map<int,int> mp;

   for(int j=0;j<N; j++){
     mp[Mat[0][j]] = 1;
   }

   for(int i=1; i<M; i++){
    for(int j=0; j<N; j++){
        if(mp[Mat[i][j]]== i){
            mp[Mat[i][j]] = i+1;



             if (i==M-1 && mp[Mat[i][j]]==M)
                  cout << Mat[i][j] << " ";
        }
    }
   }
}

int main(){

  int Mat[M][N] =
    {
         {1,2, 1, 4, 8},
        {3, 7, 8, 5, 1},
        {8, 7, 7, 3, 1},
        {8, 1, 2, 7, 9},
    };
 
    fun(Mat);


    return 0;
}