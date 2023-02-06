#include<bits/stdc++.h>
using namespace std;

// void insertToBottom(stack<int> S, int n){
//     stack<int> st;
//     while(!S.empty()){

//         st.push(S.top());
//          S.pop();
//     }
//    S.push(n);
//     while(!st.empty()){
//             S.push(st.top());
//             st.pop();
//     }

//      while (!S.empty()) {
//         cout << S.top() << " ";
//         S.pop();
//     }
// }

// using recursion
stack<int> New(stack<int> S, int n){
//   base case
if(S.empty()){
  S.push(n);
}
else{
int ele = S.top();
S.pop();

// recurr for remaining elements
S = New(S,n);

// push ele back to stack
S.push(ele);
}
  return S;
}

void insertToBottom(stack<int> S, int N)
{
 
    // Recursively insert
    // N at the bottom of S
    S = New(S, N);
 
    // Print the stack S
    while (!S.empty()) {
        cout << S.top() << " ";
        S.pop();
    }
}
int main(){
  

stack<int> S;
    S.push(5);
    S.push(4);
    S.push(3);
    S.push(2);
    S.push(1);
 
    int n = 7;
 
    insertToBottom(S, n);
 
    return 0;

}