

// print all sequences 
#include<bits/stdc++.h>
using namespace std;

void printSeq(string input, string output){
    if (input.empty()){
        cout<<output<<endl;
        return;
        // break;
    }

    // pick
    printSeq(input.substr(1), output+input[0]);
    // not pick
    printSeq(input.substr(1), output);
}

int main(){

    string pick = "abcd";
    string Notpick = "";
    printSeq(pick,Notpick);
}