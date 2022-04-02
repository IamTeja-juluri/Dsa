#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int maxN=1e5+5;

int n;
vector<int>w,p;
vector<int>adj[maxN];
vector<int>mi,ma;
int ans=0;

void dfs(int node,int par){
    
    for(auto nbr:adj[node]){
        if(nbr!=par){
            dfs(nbr,node);
            mi[node]=min(mi[node],mi[nbr]);
            ma[node]=max(ma[node],ma[nbr]);
        }
    }
    mi[node]=min(mi[node],w[node]);
    ma[node]=max(ma[node],w[node]);
    ans=max(ans,abs(w[node]-ma[node]));
    ans=max(ans,abs(w[node]-mi[node]));
    
}



int32_t main(){
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    cin>>n;
    w.resize(n+1,0);
    p.resize(n+1,0);
    mi.resize(n+1,0);
    ma.resize(n+1,0);
    
    for(int i=1;i<=n;i++){
       int x;
       cin>>x;
       w[i]=x; 
       ma[i]=INT_MIN;
       mi[i]=INT_MAX;
    }
    
    int root=0;
    
     for(int i=1;i<=n;i++){
       int x;
       cin>>x;
       p[i]=x; 
       if(x==-1)
           root=i;
       else
         adj[x].push_back(i);
    }
    
    dfs(root,0);
    cout<<ans<<endl;
}
