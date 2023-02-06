
#include<iostream>
#include<queue>

using namespace std;
 class circularqueue{
    int* arr;
    int qfront;
    int rear;
    int size;
     public:
    
    circularqueue(int n){
        size= n;
     arr= new int[size];
     qfront=rear = -1;

    }
    bool push(int data){
        if((qfront == 0 && rear == size-1) || (rear== (qfront-1)%(size-1))){
          cout<<"queue is full";
          return false;
        }
        // first element insert krne aye hai
        else if(qfront ==-1){ 
            qfront=rear=0;
            // arr[rear]= data;

        }
        else if(rear== size-1 && qfront !=0){
            rear=0;
            // arr[rear]= data;
        }
        else{
            rear++;
            // arr[rear]= data;
        }
          arr[rear]= data;
          return true;
    }
    int pop(){
        if(qfront==-1 || rear==-1){ // to check queue is empty
            cout<<"Queue is empty"<<endl;
            return -1;
        }
         int ans= arr[qfront];
         arr[qfront]=-1;
       if(qfront==rear){   // sing element hai
            qfront=-1;
            rear=-1;
        }
        else if(qfront==size-1){
            qfront=0;  //to maintain cyclic nature
        }
        else{
            // normal flow
            qfront++;
        }
        return ans;


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

  circularqueue cq(9);

  cq.Display();
  cq.push(12);
  cq.push(13);
  cq.push(14);
  cq.push(15);
  cq.push(16);
  cq.push(17);
  cq.push(18);
  cq.push(-6);

  cq.Display();

  cq.pop();
  cq.pop();

  cout<<"After deletion"<<endl;
  cq.Display();

//   cout<<"front of queue is"<<endl<<cq.qfront();


   
   


    return 0;
}