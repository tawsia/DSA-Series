// Check if a string is a valid shuffle of two distinct strings  

#include<bits/stdc++.h>
using namespace std;


int main(){
  string s1,s2;
  cin>>s1>>s2;

  string res;
  cin>> res;

  if(s1.length() + s2.length() != res.length()){
    cout<<"No";
  }
  else{
    bool flag  = 0;
    int i=0,j=0,k=0;
     while(k<res.length()){
        if(i<s1.length() && s1[i]== res[k])i++;
        else if(j<s2.length() && s2[j]==res[k])j++;
     
     else{
        flag = 1;
        break;
     }
     k++;
    }

    if(i<s1.length() || j< s2.length())cout<<"No";
    else cout<<"Yes";
  }

    return 0;
}