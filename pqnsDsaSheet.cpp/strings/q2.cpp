// check if strings are rotations of each other


#include<bits/stdc++.h>
using namespace std;


int main(){
  string s1,s2;
  cin>>s1>>s2;

  if(s1.length() != s2.length()){
    cout<<"No";
  }
  else{
    string temp = s1+s1;
    if(temp.find(s2) != string::npos){
        cout<<"Yes";
    }
    else cout<<"No";
  }




    return 0;
}