#include<bits/stdc++.h>
using namespace std;
template <typename T>

class graph{

    public:
    unordered_map<T, list<T> > adj;

    void addEdge(T u, T v, bool direction){
    //    direction =0 -> undiredcted graph
    //    diection = 1 -> directed graph


    //   created an edge from u to v

     adj[u].push_back(v);

     if(direction == 0){
      adj[v].push_back(u);
     }
    }

    void print(){
        for(auto i: adj){
            cout<<i.first<<"->";
            for(auto j : i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};
int main(){

  int n;
  cout<<"Enter the no.of nodes "<<endl;

  cin>>n;

  int m;
  cout<<"Enter the no.of edges "<<endl;
  cin>>m;
  
   graph<int> g;
  for(int i=0; i<m ; i++){
    int u,v;
    cin>>u>>v;

    // creating undirected graph;
    g.addEdge(u,v, 0);
  }
  g.print();

    return 0;
}