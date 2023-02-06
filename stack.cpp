
#include<bits/stdc++.h>
#include<stack>
using namespace std;

// implementaion of stack
class Stack{
    // properties
public:
  int *arr;
  int top;
  int size;
// behaviour
    Stack(int size){
        this->size= size;
        arr= new int[size];
        top= -1;
    }
    void push(int element){
           if(size-top>1){
            top++;
            arr[top]= element;
           }
           else{
            cout<<"stack is overflow"<<endl;
           }
    }
    void pop(){
     if(top>=0){
        top--;
     }
     else{
        cout<<"Stack underflow"<<endl;
     }

    }
    int peek(){
        if(top>=0)
             return arr[top];

        else
        cout<<"stack is empty" <<endl;
        return -1;    
    }
    bool isEmpty(){
        if(top== -1)
        return true;

        else 
        return false;
    }

};


// int main(){

// // creation of stack;
//    stack<int> s;
// //    push operation

// s.push(2);
// s.push(3);
// s.push(4);

// s.pop();

// cout<<"printing top element "<<s.top()<<endl;

// if(s.empty()){
//     cout<<"stack is not empty"<<endl;
// }
// else{
//     cout<<"stack is not empty"<<endl;
// }

//     return 0;





int main(){
  Stack st(5);

  st.push(22);
  st.push(43);
  st.push(33);
  st.push(11);



  cout<<st.peek()<<endl;
  st.pop();

  cout<<st.peek()<<endl;
  st.pop();

  cout<<st.peek()<<endl;
  st.pop();

  cout<<st.peek()<<endl;
  st.pop();

 


if(st.isEmpty()){
    cout<<"stack is not empty"<<endl;
}
else{
    cout<<"stack is not empty"<<endl;
}


}