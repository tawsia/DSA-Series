#include<bits/stdc++.h>
using namespace std;



// sort array with many repeated entries
void func(int arr[], int n){
    map<int,int> count;
    for(int i=0; i<n; i++){
        count[arr[i]]++;
    }
   map<int,int>::iterator it;
    int index = 0;
    for(it = count.begin(); it!= count.end(); it++){
        while(it->second--){
          arr[index++]= it->first;
        }
    }
}
void printArray(int arr[], int n)
{
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
        cout << endl;
 }
 
// Driver program to test above function.
int main()
{
    int arr[] = {100, 12, 100, 1, 1, 12, 100, 1, 12, 100, 1, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    cout << "Input array is\n";
    printArray(arr, n);
 
    func(arr, n);
 
    cout << "Sorted array is\n";
    printArray(arr, n);
 
    return 0;
}
