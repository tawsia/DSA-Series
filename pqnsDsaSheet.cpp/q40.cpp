// bit manipulation 
// calculate square of a number without using *,/ and pow
#include<bits/stdc++.h>

using namespace std;
int getSeq(int n){
  int x = n;
  int ans =0;
  int i=0;
  while(x){
    if(x&1){
        ans +=n;
        n= n<<i;
        x= x>>1;
        i++;
    }
  }
  return ans;
}
int main(){
   for (int n = 10; n <= 15; ++n)
        cout << "n = " << n << ", n^2 = " << getSeq(n) << endl;
    return 0;
}