//dp with graph
#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
vector<int> gr[maxn];
vector<int>dp;

int dfs(int node){
    
    if(dp[node]!=-1)
    	return  dp[node];

    int ans=0;
   
	for(auto nbr:gr[node])
		ans=max(ans,dfs(nbr)+1);
	

	return dp[node]=ans;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputgr.txt","r",stdin);
	freopen("outputgr.txt","w",stdout);
	#endif

	int n,m;
	cin>>n>>m;

    dp.resize(n+1,-1);

	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		gr[x].push_back(y);
	}
    
    int ans=0;

    for(int i=1;i<=n;i++){
       ans=max(ans,dfs(i));
    } 
    
    cout<<ans<<endl;

}
