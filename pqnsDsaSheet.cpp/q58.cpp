// Disjoint Set
#include<bits/stdc++.h>
using namespace std;
class DisJoint{
  vector<int> rank, parent,size;
  public:
  DisJoint(int n){
     rank.resize(n+1,0);
     parent.resize(n+1);
     size.resize(n+1);
     for(int i=0; i<=n; i++){
        parent[i]=i;
        size[i]=1;
     }
  }

  int findpar(int node){
    if(node== parent[node]){
        return node;
    }

    // path compresion
return parent[node]=findpar(parent[node]);
  }

  void unionByRank(int u, int v){
     int ulp_u= findpar(u);
     int ulp_v= findpar(v);

     if(ulp_u== ulp_v)return;
     if(rank[ulp_u]<rank[ulp_v]){
        parent[ulp_u]= ulp_v;
     }
     else if(rank[ulp_v]<rank[ulp_u]){
        parent[ulp_v]= ulp_u;
     }
     else{
       parent[ulp_v]= ulp_u;
       rank[ulp_u]++;

     }
 }
  void unionBySize(int u, int v){
     int ulp_u= findpar(u);
     int ulp_v= findpar(v);

      if(ulp_u== ulp_v)return;
   if(size[ulp_u]<size[ulp_v]){
    parent[ulp_u]= ulp_v;
    size[ulp_v] += size[ulp_u];

   }
   else{
     parent[ulp_v]= ulp_u;
    size[ulp_u] += size[ulp_v];
   }

  }

};
int main(){
   DisJoint ds(7);
   ds.unionBySize(1,2);
   ds.unionBySize(2,3);
   ds.unionBySize(4,5);
   ds.unionBySize(6,7);
   ds.unionBySize(5,6);

   if(ds.findpar(3)== ds.findpar(7)){
    cout<<"same"<<endl;
   }
   else cout<<"Not Same"<<endl;
   ds.unionBySize(3,7);

     if(ds.findpar(3)== ds.findpar(7)){
    cout<<"same"<<endl;
   }
   else cout<<"Not Same"<<endl;
   


    return 0;
}
