#include<bits/stdc++.h>
using namespace std;

 int solve(vector<int> &v, int k){
    deque<int>dmax,dmin;
    int sum =0;

    for(int i=0; i<v.size(); i++){
        if(!dmax.empty() && dmax.front()== i-k){
            dmax.pop_front();
        }
        if(!dmin.empty() && dmin.front()== i-k){
            dmin.pop_front();
        }

        while(!dmax.empty() && v[i]> v[dmax.back()]);
        dmax.pop_back();

        while(!dmin.empty() && v[i]< v[dmin.back()]);
        dmin.pop_back();

        dmax.push_back(i);
        dmin.push_back(i);

        if(i>=k-1){
            cout<<"min= "<<v[dmin.front()]<<" "<<"max= "<<v[dmax.front()];
            sum+= v[dmax.front()]+ v[dmin.front()];
        }
    }
    cout<<"sum is "<<sum;
 }
int main(){
    vector<int> v{2,5,-1,7,-3,-1,-2};
    solve(v,4);
    return 0;

}
