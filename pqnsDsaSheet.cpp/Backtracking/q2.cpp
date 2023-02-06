#include<bits/stdc++.h>
using namespace std;
void solve(int arr[], int n, int i, int sum1, int sum2, vector<int>arr1, 
vector<int>arr2, int &diff, bool res[]){
 

 if(i==n){
     if(arr1.size()== (n+1/2)){
        if(abs(sum1-sum2)<diff){
            diff = abs(sum1-sum2);
            for(int i=0;i<n; i++){
              res[i]= false;
            }
            for(int i=0;i<arr1.size(); i++){
                res[arr1[i]]= true; //setting arr1 elements to true
            }
        }
     }
     return;
 }
   arr1.push_back(i);
   solve(arr,n,i+1,sum1 + arr[i], sum2,arr1,arr2,diff,res);
   arr1.pop_back(); //back tracking

   arr2.push_back(i);
   solve(arr,n,i+1,sum1 , sum2+arr[i],arr1,arr2,diff,res);
   arr2.pop_back();
}
int main(){
 int arr[]= {23,45,-34,12,0,98,-99,4,189,-1,4};

 int n= sizeof(arr)/sizeof(arr[0]);

 vector<int>arr1,arr2;
 bool res[n];
 int diff=INT_MAX;
 solve(arr,n,0,0,0,arr1,arr2,diff,res);

 cout<<"set 1"<<endl;

 for(int i=0;i<n; i++){
    if(res[i]==true){
        cout<<arr[i]<<" ";
    }
 }
 cout<<endl;
 cout<<"set 2"<<endl;
 for(int i=0;i<n; i++){
      if(res[i]== false){
        cout<<arr[i]<<" ";
      }
 }
 cout<<endl;

 cout<<"Mindiff is "<<diff<<endl;




    return 0;
}