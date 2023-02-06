#include<bits/stdc++.h>

using namespace std;
// roti paratha problem
int solve(int a[], int n, int p, int mid){
     int time = 0;
     int paratha = 0;
     for(int i=0; i<n; i++){
        time = a[i];
        int j = 2;
        while(time<=mid){
            paratha++;
            time  = time + (a[i]*j);
            j++;
        }
        if(paratha>=p) return 1;
     }
     return 0;
}
int main(){
  int t;
  cin>>t;
 while(t--){
  int par;
  cin>> par;
  int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++)cin>>a[i];

  int low= 0;
  int high = 1e8;

  int ans = 0;
  while(low<=high){
    int mid = (low+high)/2;
    if(solve(a,n,par,mid)){
        ans = mid;
        high = mid-1;
    }
    else{
        low = mid+1;
    }
  }
  cout<<ans<<endl;
 }


    return 0;
}