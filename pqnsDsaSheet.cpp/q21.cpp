// Given an array of size n and a number k, find all elements that appear more than n/k times

#include<bits/stdc++.h>
using namespace std;


void fun(int arr[], int n, int k){
    int x = n/k;

    unordered_map<int,int> mp;

    for(int i=0; i<n; i++){
        mp[arr[i]]++;
    }

    for(auto it : mp){
      if(it.second > x){
        cout<<it.first<<endl;
      }
    }
}
int main(){
 int arr[] = { 1, 1, 2, 2, 3, 5,
                  4, 2, 2, 3, 1, 1, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    fun(arr,n,k);


    return 0;
}