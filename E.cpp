// C++ code to wish happY Women's DaY

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=7;
    // cin>>n;
cout<<"This is for all the Engineers over there.";
cout<<endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=(2*n); j++){
            if(i<j)
                cout<<" ";
            else
          cout<<"*";
          system("Color B5");

            if(i<=(2*n)-j){
                cout<<" ";
            }
            else{
                cout<<"*";
            }
        }
        cout<<endl;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=(2*n); j++){
            if(i>(n-j+1))
                cout<<" ";
            else
            // system("Color 0D");
            cout<<"*";

            if((i+n)>j){
                cout<<" ";
            }
            else{
                cout<<"*";
            }
        }
        cout<<endl;
    }
    system("Color B5");
     cout<<"             "<<"HAPPY ENGINEER'S DAY"<<endl;
     system("Color 16");
     cout<<"TO"<<endl;
     system("Color DE");
     cout<<"             "<<"ALL THE ENGINEERS"<<endl;
    //  cout<<"Engineers";
}
