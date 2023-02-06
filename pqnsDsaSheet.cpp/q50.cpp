#include<bits/stdc++.h>
using namespace std;
// struct Node{
//   int data;
//   Node* left;
//   Node* right;
//   Node(int x){
//     this->data=x;
//     left=right= NULL;
//   }
// };

void inOrder(int a[], vector<int> &v,
                        int n, int index)
{
    // if index is greater or equal to vector size
    if(index >= n)
        return;
    inOrder(a, v, n, 2 * index + 1);
     
    // push elements in vector
    v.push_back(a[index]);
    inOrder(a, v, n, 2 * index + 2);
}

int minSwaps(vector<int> &v){
    vector<pair<int,int>>vec(v.size());

       for(int i = 0; i < v.size(); i++)
        vec[i].first = v[i], vec[i].second = i;
     
    sort(vec.begin(), vec.end());
     int swaps=0;
    for(int i=0;i<vec.size(); i++){
        if(i== vec[i].second)continue;
        else{
            swaps++;
            swap(vec[i],vec[vec[i].second]);
            --i;
        }
    }
    return swaps;
}
int main(){
 int a[] = { 5, 6, 7, 8, 9, 10, 11 };
    int n = sizeof(a) / sizeof(a[0]);
    vector<int> v;
    inOrder(a, v, n, 0);
    cout << minSwaps(v) << endl;
}