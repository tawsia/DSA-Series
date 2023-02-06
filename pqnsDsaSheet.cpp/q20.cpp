// factorial of large numbers using linked list
#include<bits/stdc++.h>

#define rep(i,a,b) for(int i=a;i<=b; i++)
 using namespace std;
 class Node{
  int data;
  Node* prev;
  Node(int n){
    data = n;
    prev = NULL;
  }
};
 void Multi(Node* tail, int n){
   Node* temp = tail;
   Node* prvNode = tail;

   int carry = 0;
   while(temp != NULL){
   int d = temp->data *n + carry;
   temp->data = d%10;
   carry = d/10;
   prvNode = temp;
   temp = temp->prev;

 }
 while(carry != 0){
    prvNode->prev = new Node((int)(carry%10));
    carry /= 10;
    prvNode = prvNode->prev;
 }
 }
 void print(Node* tail){
    if(tail== NULL){
        return ;
    }
    print(tail->prev);
    cout
       <<tail->data;
 }
int main(){

  int n = 20;
  Node tail(1);
  rep(i,2,n);
  Multi(&tail,i);

  print(&tail);
  cout<<endl;
  return 0;


}