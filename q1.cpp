#include<bits/stdc++.h>

#include<iostream>

using namespace std;

int main()

{

string str;

int t1,t2,i,j,count=0;

cin>>str;

cin>>t1;

while(t1--)

{

// int ind;

// char ch;

// cin>>ind>>ch;

// str[ind-1]=ch;

// }
int n;
cin>>n;
for(int i=0;i<n; i++){
    char ch= str[i];
    str[i]=str[i+1];
    
}
cout<<str<<endl;

cin>>t2;

string rev=str;

while(t2--)

{

int start,end;

cin>>start>>end;

reverse(str.begin()+start-1,str.begin()+end);

 

}

cout<<str<<endl;

for(i=0;i<str.length();i++)

{

if(str[i]==rev[i])

{

count++;

}

}

cout<<count;

return 0;
}