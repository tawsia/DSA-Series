#include<bits/stdc++.h>
using namespace std;

void fun(queue<int> &q){
    if (q.size() % 2 != 0)
        cout << "Input is not even number of integers." << endl;
    int n = q.size()/2;
    queue<int>q1;

    for(int i=0; i<n; i++){
        q1.push(q.front());
        q.pop();
    }

    while(!q1.empty()){
       q.push(q1.front());
       q1.pop();

       q.push(q.front());
       q.pop();
    }
}
int main(){
  queue<int> q;
  q.push(11);
  q.push(12);
  q.push(13);
  q.push(14);
  q.push(15);
  q.push(16);
  q.push(17);
  q.push(18);
  q.push(19);
//   q.push(20);

 fun(q);
  int length = q.size();
    for (int i = 0; i < length; i++) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}