// IMPLEMENTATION OF STACK AND QUEUE USING DEQUEUE;
#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node* next;
  Node* prev;
};
 
// Implementation of class deque
class Deque{
    private:
    Node* head;
    Node* tail;

    public:
    // constructor
    Deque(){
        head=tail = NULL;
    }

    // if list is empty
    bool isEmpty(){
        if(head== NULL){
        return true;
        }
        return false;
    }
//   count the no.of nodes in the list
    int size(){

        if(!isEmpty()){
         Node* temp = head;
          int len = 0;
          while(temp != NULL){
            len++;
            temp= temp->next;
          }
          return len;
        }
        return 0;
    }

    // insert at the beginning
    void insertAtFirst(int x){
          Node* curr = new Node[sizeof(Node)];
          curr->data = x;

        //   if ele is first ele
        if(head == NULL){
            head=tail= curr;
            curr->next= curr->prev= NULL;
        }
        else{
            head->prev = curr;
            curr->next = head;
            curr->prev = NULL;
            head = curr;
        }
    }
    void insertAtLast(int x){
        Node* newNode = new Node[sizeof(Node)];
        newNode->data= x;

        // if ele is first ele
        if(head== NULL){
            head=tail= newNode;
            newNode->next= newNode->prev= NULL;
        }
        else{
            tail->next = newNode;
            newNode->next= NULL;
            newNode->prev= tail;
            tail= newNode;
        }
    }

    void removeFirst(){
        // if list is the not empty
        if(!isEmpty()){
            Node* curr = head;
            head= head->next;
            if(head != NULL){
                head->prev= NULL;
                delete curr;
            }
            if(head== NULL)tail= NULL;
            return;
        }
        cout<<"List is Empty"<<endl;
    }

    void removeLast(){
    //    if not empty();
    if(!isEmpty()){
        Node* curr = tail;
        tail= tail->prev;
        if(tail != NULL){
            tail->next= NULL;
            delete curr;
        }
        if(tail== NULL)head== NULL;
        return;
    }
    cout<<"List is empty"<<endl;
    }

    void display(){
        // is not empty
        if(!isEmpty()){
            Node* curr = head;
            while(curr != NULL){
                cout<<curr->data<<" ";
                curr= curr->next;
            }
            cout<<endl;
            return;
        }
        cout<<"List is empty"<<endl;
    }
}; 
// Implementaion of stack using deque
class Stack:public Deque{
    public:

    void push(int x){
        insertAtFirst(x);
    }

    void pop(){
        removeLast();
    }
};
class Queue:public Deque{
    public:
   void EnQueue(int x){
    insertAtLast(x);
   }
   void deQueue(){
    removeFirst();
   }
};

int main(){
     // object of Stack
    Stack stk;
 
    // push 7 and 8 at top of stack
    stk.push(7);
    stk.push(8);
    cout << "Stack: ";
    stk.display();
 
    // pop an element
    stk.pop();
    cout << "Stack: ";
    stk.display();
 
    // // object of Queue
    Queue que;
 
    // // insert 12 and 13 in queue
    que.EnQueue(12);
    que.EnQueue(13);
    cout << "Queue: ";
    que.display();
 
    // // delete an element from queue
    que.deQueue();
    cout << "Queue: ";
    que.display();
 
    cout << "Size of Stack is " << stk.size() << endl;
    cout << "Size of Queue is " << que.size() << endl;
    return 0;
}