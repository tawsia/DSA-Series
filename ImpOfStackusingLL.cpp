

#include<iostream>
#include<stack>
using namespace std;
 

 class Node{
    public:

     
    int data;
    Node* next;
    Node* top;

    // constructor
    Node(int element){
        this->data= element;
        this->next= NULL;
        this->top= NULL;
        // this->top= N
    }

 };
 void push(int element){
   Node* temp = new Node(element); 
     temp->data= element;
     temp->next;
    
 }

int main(){






    return 0;
}