#include<bits/stdc++.h>
using namespace std;
int main(){

	#ifndef ONLINE_JUDGE
	 freopen("inputss.txt","r",stdin);
	 freopen("outputss.txt","w",stdout);
	#endif

  int n;
  cin>>n;
  vector<pair<int,int>> vp;

  while(n--){
    int x,y;
    cin>>x>>y;
    vp.push_back({x,1});
    vp.push_back({y,0});
  }
 
  sort(vp.begin(),vp.end());

  vector<int> prf;
  int count=0,ans=0;

  for(int i=0;i<vp.size();i++){
      if(vp[i].second==1)
        count++;
      else
        count-=1;
      prf.push_back(count);
  }

  for(int i=0;i<prf.size();i++)
    ans=max(ans,prf[i]);
  
 cout<<ans<<endl;
}