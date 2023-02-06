
#include<iostream>
#include<queue>

using namespace std;

class Queue{
    int*arr;
    int size;
    int qfront;
    int rear;
    public:

    // constrctor
    Queue(int s){
        size= s;
        arr= new int[size];
        qfront=0;
        rear=0;
    }
    void push(int data){
    if( rear == size){
    cout<<"Queue is full"<<endl;
    }
    else{
        arr[rear]= data;
        rear++;
    }
}

 int pop(){
    if(qfront==rear){
        return -1;
    }
    else{
        int ans= arr[qfront];
        arr[qfront]=-1;
        qfront++;
        if(qfront==rear){
            qfront=0;
            rear=0;
        }

    return ans;
    }
 }
 int front(){
    if(qfront==rear){
        return -1;
    }
    else{
        return arr[qfront];
    }
 }
 bool isEmpty(){
    if(qfront==rear){
        return true;
    }
    return false;
 }
 void Display(){
    int i;
    if(qfront==rear){
       cout<<"queue is empty"<<endl;
       return;
    }

    for(i=qfront; i<rear; i++){
        cout<<arr[i]<<endl;
    }
    return;
 }
};



int main(){
  
//   queue<int> q;

//   q.push(17);
// //   q.pop();
// cout<<"Front of Queue is "<<q.front()<<endl;
//   q.push(18);
  
// cout<<"Front of Queue is "<<q.front()<<endl;
//   q.push(19);
  
// cout<<"Rearer of Queue is "<<q.front()<<endl;

// cout<<"size of queue is "<<q.size()<<endl;
// q.pop();
// cout<<"size of queue is "<<q.size()<<endl;

// if(q.empty()){
//     cout<<"Queue is empty"<<endl;
// }
// else{
//     cout<<"Queue is not empty"<<endl;
// }
 Queue q(5);
  
  q.Display();
//   push operation
  q.push(22);
  q.push(43);
  q.push(33);
  q.push(11);


   q.Display();

  q.push(70);
   q.Display();

   q.pop();
   q.pop();

cout<<"After deleting two elements"<<endl;
   q.Display();

   cout<<"Front of Queue "<<q.front()<<endl;

  
    return 0;
}










