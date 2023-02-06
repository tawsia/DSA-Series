// Reverse a linked list
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;


    // Constructor
    Node(int d){
        this->data=d;
        this->next= NULL;
    }
};
// it will return head of the linked list
Node* reverse1(Node* &head){
    // base case
       if(head==NULL || head->next==NULL){
            return head;
       }
       Node* chotaHead= reverse1(head->next);
       head->next->next= head;
       head->next= NULL;
       return chotaHead;
}
// reverse rest of the linkedlist// 
// void reverse(Node* &head, Node* curr, Node* prev){
//              if(curr==NULL){//                 head= prev;
//                 return;//              }
//              Node* forwrd = curr->next;
//              reverse(head,forward,curr);
//              curr->next=prev;
// }
Node* reverseLinkedList(Node *head){

     return reverse1(head);

/*
     Node* curr= head;
      Node* prev= NULL;
      reverse(head,curr,prev);
      return head;
      */
//     if(head==NULL || head->next== NULL){
//         return head;
//     }
//     Node* prev= NULL;
//     Node* curr= head;
// while (curr!= NULL)
// {
//     Node* forward= curr->next;
//     curr->next= prev;
//     prev= curr;
//     curr= forward;
// }
// //   return prev;
// }


// doubly linked list ko reverse krna

}
void print(Node* &head){
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    Node* temp= head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    cout<<endl;
}

int main(){
    // Node* tem= head;
    

}