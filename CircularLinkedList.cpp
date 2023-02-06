
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;


    // constructor
    Node(int d){
        this->data= d;
        this->next= NULL;
    }

        // destructor

        ~Node(){
            int val= this->data;
            if(this->next!= NULL){
                delete next;
                next = NULL;
            }
            cout<<"Memory is free for node with data "<<val<<endl;
        }
    

};

void insertNode(Node* & tail, int element, int d){
    // Assuming that the element is present in the list
    // empty list
    if(tail==NULL){
Node* node1= new Node(d);
tail = node1;
node1->next= node1;
    }
    else{
        // non emepty list
          Node* curr= tail;
          while(curr->data!= element){
            curr= curr->next;
          }
        //   element found ->curr is representing element wala node
        Node* temp = new Node(d);
        temp->next= curr->next;
        curr->next= temp;
    }
      
}
void print(Node* &tail){
    if(tail==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    Node* temp = tail;
    do{
         cout<<tail->data<<" ";
           tail= tail->next;
    }while(tail!= temp);
    cout<<endl;
}
void deleteNode(Node* &tail, int val){
    // empty list
    if(tail== NULL){
        cout<<"list is empty"<<endl;
        return;

    }
    else{
        // Non empty list
        // Assuming that val is present in linked list
        Node* prev= tail;
        Node* curr= prev->next;
        while(curr->data!= val){
            prev= curr;
            curr= curr->next;
        }
        prev->next= curr->next;

        // one node linked list
        if(curr==prev){
            tail= NULL;
        }
        // >= 2 Node linkedlist
      else  if(tail==curr){
            tail= prev;
        }
        curr->next= NULL;
        delete curr;



    }
}
bool isCircular(Node* head){
    // empty list
    if(head==NULL){
        return true;
    }
    Node* temp = head->next;
    while(temp!= NULL && temp != head){
        temp = temp->next;
    }
    if(temp==head){
        return true;
    }

    return false;
}

int main(){
    Node* tail = NULL;
// inserting in empty list
    insertNode(tail, 5,3);
    print(tail);
    insertNode(tail, 3,5);
    print(tail);
    // insertNode(tail, 5,7);
    // print(tail);
    // insertNode(tail, 7,9);
    // print(tail);
    // insertNode(tail, 5,6);
    // print(tail);
    // insertNode(tail, 9,10);
    // print(tail);
    // insertNode(tail, 3,4);
    // print(tail);
    // insertNode(tail, 7,8);
    // print(tail);

//    deleteNode(tail,3);
//    print(tail);

  if(isCircular(tail)){
    cout<<"Linked list is circular"<<endl;
  }
  else{
    cout<<"linkedlist is not circular";
  }


    return 0;
}