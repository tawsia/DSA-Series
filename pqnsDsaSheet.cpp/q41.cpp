// stacks n queues
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
      Node* next;
      Node* prev;
      int data;

      Node(int x){
        this->data=x;
        next=prev= NULL;
      }
  
};

Node* dummy = new Node(-1);
Node* head = dummy;
Node* mid = dummy;
int cnt = 0;

void push(int data){
    Node* curr = new Node(data);
    curr->prev = NULL;
    curr->next = head;
    cnt++;
    head->prev = curr;
    head = curr;
    if(cnt ==1){
        mid = curr;
    }
    else if(cnt%2==0){
        mid = mid->prev;   
    }

}

int pop(){
    if(cnt == 0){
         cout<<"Stack is empty"<<endl;
         return -1;
    }
    Node* temp = head;
    int x = head->data;
        if(head != NULL){
            head->prev = NULL;
        }
        cnt--;
        if(cnt&1){
            mid = mid->next;
        }
        free(temp);
      return x;
}
int middle(){
    if(cnt==0){
        cout<<"stack is empty"<<endl;
        return -1;
    }
    return mid->data;
}
void printData(){
    Node* curr = head;
    if(cnt==0){
        cout<<"Stack is empty"<<endl;
        return;
    }
    for(int i=0; i<cnt; i++){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
  cout<<endl;
}
int main(){
  push(1);
  push(2);
  push(3);
  push(4);
  push(5);
  push(6);
  printData();
  cout<<"Middle is->"<<middle()<<endl;

  cout<<"Deleted Element is->"<<pop()<<endl;
  printData();
  cout<<"Middle is->"<<middle()<<endl;
  cout<<"Deleted Element is->"<<pop()<<endl;
  printData();
  cout<<"Middle is->"<<middle()<<endl;
  cout<<"Deleted Element is->"<<pop()<<endl;
  printData();
  cout<<"Middle is->"<<middle()<<endl;
  
  cout<<"Deleted Element is->"<<pop()<<endl;
  printData();
  cout<<"Middle is->"<<middle()<<endl;

  cout<<"Deleted Element is->"<<pop()<<endl;
  printData();

  cout<<"Middle is->"<<middle()<<endl;
  
  cout<<"Deleted Element is->"<<pop()<<endl;
  printData();

  cout<<"Middle is->"<<middle()<<endl;

  





}