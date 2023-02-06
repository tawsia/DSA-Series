#include<bits/stdc++.h>

// rotate matrix by 90 degree in clock wise;
using namespace std;
#define N 4
// void fun(int a[N][N]){
//     for(int i=0; i<N; i++){
//         for(int j=i; j<N; j++){
//             if(i!= j){
//                 int temp = a[i][j];
//                 a[i][j]= a[j][i];
//                 a[j][i]= temp;
//             }
//         }
//     }
//     for(int i=0; i<N; i++){
//         for(int j = 0; j<N/2; j++){
//             int temp = a[i][j];
//             a[i][j]= a[i][N-j-1];
//             a[i][N-j-1]= temp;
//         }
//     }
// }

void printMatrix(int a[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = N-1; j>=0; j--)
            cout << a[j][i] << " ";
        cout << '\n';
    }
}
 
// Driver code
int main()
{
    int a[N][N] = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 } };
    // fun(a);
    printMatrix(a);
    return 0;
}