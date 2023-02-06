#include<bits/stdc++.h>
using namespace std;

class NStack
{
    
    int *arr;
    int *top;
    int *next;
    
    int n,s;
    int freespot;
public:
 NStack(int n, int s);
  
    // A utility function to check if there is space available
    bool isFull()   {  return (freespot  == -1);  }
  
    // To push an item in stack number 'sn' where sn is from 0 to k-1
    void push(int x, int m);
  
    // To pop an from stack number 'sn' where sn is from 0 to k-1
    int pop(int m);
  
    // To check whether stack number 'sn' is empty or not
    bool isEmpty(int m)  {  return (top[m] == -1); }
};
NStack::NStack(int N, int S){
    n= N;
    s= S;

    arr = new int[s];
    top = new int[n];
    next = new int[s];

//    intialize top
   for(int i=0; i<n; i++){
    top[i] = -1;
   }

   for(int i=0; i<s-1; i++){
    next[i] = i+1;
   }

//    update end of next
   next[s-1] = -1;
// intialize free spot 
 freespot = 0;
}

void NStack::push(int x, int m)
{


    // check over flow 
    if(isFull()){
        cout<<"Stack overflow"<<endl;
        return;
    }

    // find index
    int index = freespot;

    // update freespot
    freespot = next[index];

    // // insert in array
    // arr[index] = x;

    // update next
    next[index] = top[m];

    // update top 
    top[m] = index;

    
    // insert in array
    arr[index] = x;
}
int NStack::pop(int m){
    // check underflow
    if(isEmpty(m)){
        cout<<"Stack underflow"<<endl;
        return INT_MAX;
    }

    // index nikalo
    int index = top[m-1];

    top[m-1] = next[index];

    next[index] = freespot;
    freespot = index;

    return arr[index];
}
int main()
{
    // Let us create 3 stacks in an array of size 10
    int n= 3, s = 10;
    NStack ns(n, s);
  
    // Let us put some items in stack number 2
    // cout<< "pushed element in stack 2 is " << ns.push(15, 2) <<endl;
    ns.push(45, 2);
  
    // Let us put some items in stack number 1
    ns.push(17, 1);
    ns.push(49, 1);
    ns.push(39, 1);
  
    // Let us put some items in stack number 0
    ns.push(11, 0);
    ns.push(9, 0);
    ns.push(7, 0);
  
    // cout << "Popped element from stack 2 is " << ns.pop(2) << endl;
    // cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    // cout << "Popped element from stack 0 is " << ks.pop(0) << endl;
  
    return 0;
}