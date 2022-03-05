#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll l,r;
ll dp[20][5][2];
ll solve(ll pos,ll cnt ,bool tight ){

   if(pos==s.size())
   	return 1;
   

   if(dp[pos][cnt][tight]!=-1)
   	 return dp[pos][cnt][tight];
 
  ll en=tight?(s[pos]-'0'):9;

  ll ans=0;

  for(ll i=0;i<=en;i++){
     
     ll tempcount=cnt+(i>0);

     if(tempcount<=3)
     	ans=ans+solve(pos+1,tempcount,tight&(i==en));

  }
 
 return dp[pos][cnt][tight]=ans;


}


int main(){
  
   #ifndef ONLINE_JUDGE
	freopen("inputdg.txt","r",stdin);
	freopen("outputdg.txt","w",stdout);
  #endif

   ll t;
   cin>>t;

   while(t--){

      cin>>l>>r;
      
      s=to_string(r);
      memset(dp,-1,sizeof dp);
      
      ll ans=solve(0,0,1);

      memset(dp,-1,sizeof dp);
      s=to_string(l-1);

      ans=ans-solve(0,0,1); 
      
      cout<<ans<<"\n";

   }


}
