
#include<bits/stdc++.h>
using namespace std;
class Heap{
   public:
   int arr[100];
   int size;

   Heap(){
    arr[0]= -1;
    size= 0;
   }
   void insert(int val){
        size= size+1;
        int index= size;
        arr[index]= val;

        while(index>1){
            int parent= index/2;

            if(arr[parent]<arr[index]){
                swap(arr[parent], arr[index]);
                index= parent;
            }
            else{
                return;
            }
        }
   }

   void print(){
     for(int i=1; i<=size; i++){
        cout<<arr[i]<<" ";
     }
     cout<<endl;
   }
   void deleteP(){
    if (size==0){
        cout<<" Nothing ro delete"<<endl;
        return;
    }
// put last element int first index
    arr[1]= arr[size];
 // Remove last element
    size--;

    // take root node its correct position
    
     int i=1;
     while(i<size){
        int leftIndex= 2*i;
        int rightIndex= 2*i+1;

        if(leftIndex<size && arr[i]< arr[leftIndex]){
            swap(arr[i], arr[leftIndex]);
            i= leftIndex;
        }
       else if(rightIndex<size && arr[i]< arr[rightIndex]){
            swap(arr[i], arr[rightIndex]);
            i= rightIndex;
        }
        else{
            return;
        }
     }


   }
};

void heapify(int arr[], int n, int i){
    int largest= i;

    int left= 2*i;
    int right= 2*i+1;

  if(left<= n && arr[largest] < arr[left])
    largest= left;

    if(right<=n && arr[largest] < arr[right])
    largest= right;

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr,n, largest);


    }

}

void heapsort(int arr[], int n){
    int size = n;
    while(size > 1){
      swap(arr[size],arr[1]);
      size--;


      heapify(arr, size, 1);
    }
}
int main(){

 Heap H;
 H.insert(50);
 H.insert(55);
 H.insert(53);
 H.insert(52);
 H.insert(54);
 H.print();

H.deleteP();
H.print();

int arr[6]= {-1, 54, 53, 55, 52, 50};
int n=5;

// heap creation
for(int i= n/2; i>0; i--){
    heapify(arr,n,i);
}

cout<<"printing the array now "<<endl;

for(int i=1; i<=n; i++){
    cout<<arr[i]<<" ";
}cout<<endl;

// heap sort ko coll kro
heapsort(arr,n);
cout<<"print sorted array "<<endl;

for(int i=1; i<=n; i++){
    cout<<arr[i]<<" ";
}cout<<endl;

cout<<"Using priority queue here"<<endl;

// max heap
priority_queue<int> pq;
pq.push(4);
pq.push(2);
pq.push(5);
pq.push(3);
pq.push(8);

cout<<"Element at top " <<pq.top()<<endl;
pq.pop();
cout<<"Element at top " <<pq.top()<<endl;



// min heap

priority_queue<int, vector<int>, greater<int> > minHeap;
minHeap.push(4);
minHeap.push(2);
minHeap.push(5);
minHeap.push(3);

cout<<"Element at top " <<minHeap.top()<<endl;
minHeap.pop();
cout<<"Element at top " <<minHeap.top()<<endl;
    return 0;
}