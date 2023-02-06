#include<bits/stdc++.h>
using namespace std;
class kQueue{


   public:
   int n;
   int k;
   int *arr;
   int *front;
   int *rear;
   int *next;
   int freespot;


   public:
   kQueue(int n,int k){
      this->n=n;
      this->k= k;
      front= new int[k];
      rear= new int[k];
      for(int i=0; i<k; i++){
        front[i]= -1;
        rear[i]= -1;
      }
      next= new int[n];
      for(int i=0; i<n; i++){
      next[i]= i+1;
      }

      next[n-1]= -1;
      arr= new int[n];
      freespot= 0;
   }
  void push(int x, int qn){
    //    overflow
    if(freespot==-1){
        cout<<"No space available"<<endl;
        return;
    }
    // find first free index
    int index= freespot;
    // update freespot
    freespot= next[index];

    // check for first element
    if(front[qn-1]==-1){
        front[qn-1]= index;
    }
    else{
        // link new ele to prv ele
        next[rear[qn]]= index;
   }
//    update next
   next[index]= -1;
//    update rear
rear[qn]= index;
// push element
  arr[index]= x;
   }
   int pop(int qn){
    //  undeflow
    if(front[qn-1]==-1){
        cout<<"queue underflow";
        return -1;
    }
    // find index to pop
    int index= front[qn-1];
    // front ko aage bdhao
    front[qn-1]= next[index];
    // free slot ko manaGE KaRO
    next[index]= freespot;
    freespot = index;
    return arr[index];
   }
};
int main(){

  kQueue q(10, 3);
  q.push(10,1);
  q.push(15,1);
  q.push(20,2);
  q.push(25,1);
//   q.push(25,1);

cout<<q.pop(1)<<endl;
cout<<q.pop(2)<<endl;
cout<<q.pop(1)<<endl;
cout<<q.pop(1)<<endl;

cout<<q.pop(1)<<endl;





    return 0;
}