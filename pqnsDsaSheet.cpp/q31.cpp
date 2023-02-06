#include<bits/stdc++.h>
using namespace std;


 int main(){

// double helix problem
    while(true){
        int n;
        cin>>n;
        if(n==0)break;
        else{

            int a[n];
            for(int i=0; i<n; i++)cin>>a[i];
            int m;
            cin>>m;
            int b[m];
            for(int i=0; i<m; i++)cin>> b[i];

            int sum1=0,sum2=0;
            int i=0,j=0;
            int Equal = 0;
            while(i<n && j<m){
                if(a[i]<b[j]){
                    sum1 += a[i++];
                }
                else if(b[j]<a[i]){
                    sum2 += b[j++];
                }
                else{
                    Equal += max(sum1,sum2) + a[i]; // common element;
                    sum1=sum2=0;
                    i++;
                    j++;
                }
            }
           while(i<n)sum1 += a[i++];
           while(j<m)sum2 += b[j++];

           Equal += max(sum1,sum2);
           cout<<Equal<<endl; 


        }
    }
    return 0;
}