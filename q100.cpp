#include<bits/stdc++.h>
using namespace std;

int main(){


    int n;
    cin>>n;

    int i,j,num;
    for(i=0;i<n;i++){
        num=1;
        for(j=0;j<=i;j++){

            if(num%2 != 0){
        //   cout<<"#"<<"";
             cout<<num <<" ";
            }
            else{
                cout<<"#"<<" ";
            }
            num++;
        }
        cout<<endl;
    } 
    return 0;
}