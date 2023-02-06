#include<bits/stdc++.h>
using namespace std;

#define N 5
//  find a specific pair in the matrix
 int findmaxValue(int mat[][N]){
     int maxVal = INT_MIN;
     for(int i=0; i<N-1; i++){
        for(int j=0; j<N-1; j++){
            for(int k= i+1; k<N; k++){
                for(int l= j+1; l<N; l++){
                    if(maxVal<(mat[k][l]-mat[i][j]))
                    maxVal = mat[k][l] - mat[i][j];
                }
            }
        }
     }
     return maxVal;
 }
int main(){

int mat[N][N] = {
                { 1, 2, -1, -4, -20 },
                { -8, -3, 4, 2, 1 },
                { 3, 8, 6, 1, 3 },
                { -4, -1, 1, 7, -6 },
                { 0, -4, 10, -5, 1 }
            };
    cout << "Maximum Value is "
        << findmaxValue(mat);
 
    return 0;




}