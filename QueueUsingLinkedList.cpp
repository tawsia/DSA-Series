
#include<iostream>
using namespace std;

struct QNode{
    int data;
     QNode* next;
     QNode(int d){
       this->data= d;
       this->next= NULL;
     }

};
  struct queue{
    QNode *front, *rear;
    queue(){
        front=rear= NULL;
    }
  
 void push(int x){
    // create new node
    QNode* temp = new QNode(x);

    // if queue is empty or not, then new node is front and rear both
    if(rear==NULL){
        front=rear=temp;
        return;
    }
    // Add new node at the end of queue and change rear
    rear->next = temp;
    rear= temp;
    
 }
 void pop(){
    // if queue is empty
    // if(front==){
    if(front== NULL){
        return;
    }

    // store front and move front further
     QNode *temp = front;
     front= front->next;
    
    //  if front becomes null then rear also changes to NULL  if(front==NULL)
    if(front == NULL)
    // front= NULL;
     rear= NULL;

     delete(temp);
 }
  };
int main(){
  queue q;
  q.push(10);
  q.push(20);
//   q.push(3);
//   q.push(6);
  q.pop();
  q.pop();
  q.push(30);
  q.push(40);
  q.push(50);
  q.pop();

  cout<<"queue front: "<<(q.front)->data<<endl;
  cout<<"queue rear: "<<(q.rear)->data;



}