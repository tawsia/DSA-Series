#include<bits/stdc++.h>
using namespace std;

// print count of duplicates in a string
void fun(string S){
    unordered_map<char,int> mp;

    for(int i=0; i<S.size(); i++){
        mp[S[i]]++;
    }

    for(auto it: mp){
        if(it.second>1){
            cout << it.first << ", count = " << it.second
                 << "\n";
     }
    }
}
/* Driver code*/
int main()
{
    string S = "test string";
    fun(S);
    return 0;
}