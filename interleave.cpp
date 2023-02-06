
#include<bits/stdc++.h>
using namespace std;

 void interLeave(queue<int>& q){
    if(q.size()%2 != 0){
        cout<<"Input even no.of integers"<<endl;
    }

    stack<int>s;
    int hs= q.size()/2;

for(int i=0; i<hs; i++){
    int val= q.front();
    q.pop();
    s.push(val);
}
while(!s.empty()){
    int val= s.top();
    s.pop();
    q.push(val);
}
for(int i=0; i<hs; i++){
    int val= q.front();
    q.pop();
    q.push(val);
}
for(int i=0; i<hs; i++){
    int val=q.front();
    q.pop();
    s.push(val);

}
while(!s.empty()){
    int val=s.top();
    s.pop();
    q.push(val);
    int element= q.front();
    q.pop();
    q.push(element);
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
    q.push(20);
    interLeave(q);
    int length = q.size();
    for (int i = 0; i < length; i++) {
        cout << q.front() << " ";
        q.pop();
    }




    return 0;
}