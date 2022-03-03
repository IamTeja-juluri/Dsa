//Tabulation
//Accepted Approach
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int combinations(int n){
    
    vector<long long>dp(n+1,0);

    dp[0]=1;

    for(int i=1;i<=n;i++){
    
    for(int j=1;j<=6;j++){
        
        if((i-j)>=0){
         dp[i]=((dp[i]%mod)+(dp[i-j]%mod))%mod;
        }
        else
            break;

      }
  }
    return dp[n]%mod;
    
}


int main(){

	#ifndef ONLINE_JUDGE
	   freopen("input.txt","r",stdin);
	   freopen("output.txt","w",stdout);
	#endif
	  
	  int n;
	  cin>>n;

     cout<<combinations(n)<<endl;

     

	}