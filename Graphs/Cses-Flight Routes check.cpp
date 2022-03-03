#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int n,m,col=0;
vector<int> gr[maxn],rg[maxn];
vector<bool> visited(maxn,false);
vector<int> order;
vector<int> component;


void topodfs(int node){
  
  visited[node]=true;

  for(auto nbr:gr[node]){

  	 if(!visited[nbr]){
         topodfs(nbr);
  	 }
  }
  order.push_back(node);

}

void dfs(int node){

   visited[node]=true;
  component.push_back(node);

  for(auto nbr:rg[node]){
  	if(!visited[nbr]){
  		dfs(nbr);
  	}
  }


}




int main(){

	#ifndef ONLINE_JUDGE
	 freopen("input.txt","r",stdin);
	 freopen("output.txt","w",stdout);
	#endif
    
	cin>>n>>m;

	for(int i=0;i<m;i++){
      
      int x,y;
      cin>>x>>y;
      gr[x].push_back(y);
      rg[y].push_back(x);

	}

   visited.assign(n,false);

	for(int i=1;i<=n;i++){
		if(!visited[i]){
			topodfs(i);
		}
	}

	reverse(order.begin(),order.end());

    vector<int> ans;
    visited.assign(n,false);

    for(auto nbr:order){
    	if(!visited[nbr]){
    		dfs(nbr);
    		ans.push_back(component[0]);
            component.clear();
    	}
    }

    if(ans.size()==1){
    	cout<<"YES"<<endl;
    }
    else{

    	cout<<"NO"<<endl;

    	cout<<ans[1]<<" "<<ans[0]<<endl;
    }





}