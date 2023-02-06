#include <bits/stdc++.h>
using namespace std;
vector<int> inTime;
vector<int> outTime;
int timer=1;
void resize(int n){
	inTime.resize(n+1);
	outTime.resize(n+1);
}
void dfs(int src, int par, vector<int> g[]){
	inTime[src]= timer++;
	for(auto it: g[src]){
		if(it != par){
			dfs(it,src,g);
		}
	}
	outTime[src]= timer++;
}
bool check(int x,int y){
	if(inTime[x]>inTime[y] && outTime[x]< outTime[y])
	   return true;
 return false;
}

int main() {
  int n;
  cin>>n;
  timer=1;
  resize(n);
  vector<int> g[n+1];
  for(int i=0;i<n-1;i++){
	  int x,y;
	  cin>>x>>y;
	  g[x].push_back(y);
	  g[y].push_back(x);
  }
  dfs(1,0,g);
  int q;
  cin>>q;
  for(int i=0;i<q;i++){
	  int type,x,y;
	  cin>>type>>x>>y;
	  if(!check(x,y) && !check(y,x)){
		  cout<<"NO"<<endl;
		  continue;
	  }
	  if(type==0){
		  if(check(y,x)){
			  cout<<"YES"<<endl;
		  }
		  else{
			  cout<<"NO"<<endl;
		  }
	  }
	  else if(type==1){
		  if(check(x,y)){
			  cout<<"YES"<<endl;
		  }
		  else{
			  cout<<"NO"<<endl;
		  }
	  }
  }
  return 0;
}