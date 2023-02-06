#include<bits/stdc++.h>
using namespace std;

void NSE(int arr[], int n){
    stack<int>st;
    st.push(-1);

    vector<int> ans(n);
//    int n = arr.size();
    for(int i=n-1; i>=0; i--){
        int curr= arr[i];
        while(st.top()>=curr){
            st.pop();
        }

        ans[i]= st.top();
        st.push(curr);
    }
     for (int i = 0; i < n; i++) {
        cout << arr[i] << " ---> " << ans[i] << endl;
    }
}

int main(){
   int arr[]= {11, 13, 21, 3 };
   int n= sizeof(arr) / sizeof(arr[0]);
    NSE(arr,n);
   return 0;

}